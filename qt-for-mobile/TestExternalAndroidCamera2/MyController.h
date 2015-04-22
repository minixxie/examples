#ifndef __MY_CONTROLLER_H__
#define __MY_CONTROLLER_H__

#include <QObject>

class MyController : public QObject
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

};

#endif
