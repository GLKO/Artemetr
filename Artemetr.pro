#-------------------------------------------------
#
# Project created by QtCreator 2020-02-09T00:55:35
#
#-------------------------------------------------

QT       += core gui serialport
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = MovingCam
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += TEST
#DEFINES += TEST_WITH_ARDUINO

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

RC_ICONS = appicon.ico

SOURCES += \
        camera.cpp \
        cameracontrol.cpp \
        cameraschemewidget.cpp \
        camerawidget.cpp \
        comport.cpp \
        hardware.cpp \
        main.cpp \
        mainwindow.cpp \
        manualcontrolwidget.cpp \
        resultsaver.cpp \
        robot.cpp \
        settings.cpp \
        tablepoints.cpp

HEADERS += \
        camera.h \
        cameracontrol.h \
        cameraschemewidget.h \
        camerawidget.h \
        comport.h \
        common/icamera.h \
        common/icomport.h \
        common/iobserver.h \
        common/keywords.h \
        hardware.h \
        mainwindow.h \
        common/point.h \
        manualcontrolwidget.h \
        resultsaver.h \
        robot.h \
        settings.h \
        struct_result.h \
        tablepoints.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += common/

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/imageAnalyzer/release/ -limageAnalyzer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/imageAnalyzer/debug/ -limageAnalyzer

INCLUDEPATH += $$PWD/imageAnalyzer
DEPENDPATH += $$PWD/imageAnalyzer
