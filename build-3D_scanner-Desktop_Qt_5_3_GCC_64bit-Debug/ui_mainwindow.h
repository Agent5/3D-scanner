/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *viewCameraButton;
    QPushButton *calibrateButton;
    QPushButton *scanButton;
    QPushButton *datasetButton;
    QPushButton *quitButton;
    QPushButton *configureButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(159, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        viewCameraButton = new QPushButton(centralWidget);
        viewCameraButton->setObjectName(QStringLiteral("viewCameraButton"));
        viewCameraButton->setGeometry(QRect(20, 150, 121, 27));
        calibrateButton = new QPushButton(centralWidget);
        calibrateButton->setObjectName(QStringLiteral("calibrateButton"));
        calibrateButton->setGeometry(QRect(20, 50, 121, 27));
        scanButton = new QPushButton(centralWidget);
        scanButton->setObjectName(QStringLiteral("scanButton"));
        scanButton->setGeometry(QRect(20, 90, 121, 27));
        datasetButton = new QPushButton(centralWidget);
        datasetButton->setObjectName(QStringLiteral("datasetButton"));
        datasetButton->setGeometry(QRect(20, 190, 121, 27));
        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(20, 230, 121, 27));
        configureButton = new QPushButton(centralWidget);
        configureButton->setObjectName(QStringLiteral("configureButton"));
        configureButton->setGeometry(QRect(20, 10, 121, 27));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        viewCameraButton->setText(QApplication::translate("MainWindow", "View Camera", 0));
        calibrateButton->setText(QApplication::translate("MainWindow", "Calibrate", 0));
        scanButton->setText(QApplication::translate("MainWindow", "Scan", 0));
        datasetButton->setText(QApplication::translate("MainWindow", "Process Dataset", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        configureButton->setText(QApplication::translate("MainWindow", "Configure", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
