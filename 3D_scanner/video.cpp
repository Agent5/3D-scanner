#include "video.h"
#include "camerawindow.h"
#include "ui_camerawindow.h"
#include <cv.h>
#include <highgui.h>
#include <QSettings>
#include <QDebug>
#include <QtCore>
#include <QThread>
#include <QtConcurrent/qtconcurrentrun.h>
#include <QFuture>

video::video()
{
}

video::
