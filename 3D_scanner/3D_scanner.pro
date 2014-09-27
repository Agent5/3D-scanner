#-------------------------------------------------
#
# Project created by QtCreator 2014-07-30T23:07:41
#
#-------------------------------------------------

QT       += core gui
QT       += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3D_scanner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configwindow.cpp \
    camerawindow.cpp \
    calibratewindow.cpp

HEADERS  += mainwindow.h \
    settings.h \
    configwindow.h \
    camerawindow.h \
    calibratewindow.h

FORMS    += mainwindow.ui \
    configwindow.ui \
    camerawindow.ui \
    calibratewindow.ui

INCLUDEPATH += /home/josh/OpenCV/opencv/include/opencv/
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann

