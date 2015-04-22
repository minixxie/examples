#ifndef __MY_CONTROLLER_H__
#define __MY_CONTROLLER_H__

#include <QObject>
#ifdef Q_OS_ANDROID
	#include <QAndroidActivityResultReceiver>
#endif

#ifdef Q_OS_ANDROID
class MyController : public QObject, QAndroidActivityResultReceiver
#else
class MyController : public QObject
#endif
{
	Q_OBJECT
	Q_PROPERTY(QString imagePath READ imagePath NOTIFY imagePathChanged)
private:
	QString m_imagePath;
public://getters/setters
	const QString& imagePath() const { return this->m_imagePath; }

public:
	Q_INVOKABLE void callExternalCamera();

signals:
	void imagePathChanged();

private:
#ifdef Q_OS_ANDROID
	QAndroidJniObject takePhotoSavedUri;
	void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject & data);
#endif

};

#endif
