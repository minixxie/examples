TEMPLATE = app

QT += qml quick

SOURCES += main.cpp MyController.cpp
HEADERS += MyController.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

android {    #如果构建目标(build target)是android
	QT += androidextras  #使用此库
}
