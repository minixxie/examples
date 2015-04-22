#include "MyController.h"

#ifdef Q_OS_ANDROID
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QtAndroid>
#endif

#include <QDebug>

void MyController::callExternalCamera()
{
#ifdef Q_OS_ANDROID
	QAndroidJniObject activity = QtAndroid::androidActivity();

	activity.callMethod<void>("callExternalCamera","()V");
#endif

}

