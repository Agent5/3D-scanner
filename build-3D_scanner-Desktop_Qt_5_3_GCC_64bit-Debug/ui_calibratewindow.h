/********************************************************************************
** Form generated from reading UI file 'calibratewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATEWINDOW_H
#define UI_CALIBRATEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_calibratewindow
{
public:
    QPushButton *calibButton1;
    QPushButton *calibButton2;
    QPushButton *calibButton3;
    QPushButton *calibButton4;
    QPushButton *calibButton5;

    void setupUi(QDialog *calibratewindow)
    {
        if (calibratewindow->objectName().isEmpty())
            calibratewindow->setObjectName(QStringLiteral("calibratewindow"));
        calibratewindow->resize(158, 173);
        calibButton1 = new QPushButton(calibratewindow);
        calibButton1->setObjectName(QStringLiteral("calibButton1"));
        calibButton1->setGeometry(QRect(10, 10, 131, 27));
        calibButton2 = new QPushButton(calibratewindow);
        calibButton2->setObjectName(QStringLiteral("calibButton2"));
        calibButton2->setGeometry(QRect(10, 40, 131, 27));
        calibButton3 = new QPushButton(calibratewindow);
        calibButton3->setObjectName(QStringLiteral("calibButton3"));
        calibButton3->setGeometry(QRect(10, 70, 131, 27));
        calibButton4 = new QPushButton(calibratewindow);
        calibButton4->setObjectName(QStringLiteral("calibButton4"));
        calibButton4->setGeometry(QRect(10, 100, 131, 27));
        calibButton5 = new QPushButton(calibratewindow);
        calibButton5->setObjectName(QStringLiteral("calibButton5"));
        calibButton5->setGeometry(QRect(10, 130, 131, 27));

        retranslateUi(calibratewindow);

        QMetaObject::connectSlotsByName(calibratewindow);
    } // setupUi

    void retranslateUi(QDialog *calibratewindow)
    {
        calibratewindow->setWindowTitle(QApplication::translate("calibratewindow", "Dialog", 0));
        calibButton1->setText(QApplication::translate("calibratewindow", "Calibrate Camera 1", 0));
        calibButton2->setText(QApplication::translate("calibratewindow", "Calibrate Camera 2", 0));
        calibButton3->setText(QApplication::translate("calibratewindow", "Calibrate Camera 3", 0));
        calibButton4->setText(QApplication::translate("calibratewindow", "Calibrate Camera 4", 0));
        calibButton5->setText(QApplication::translate("calibratewindow", "Calibrate IP  Cam", 0));
    } // retranslateUi

};

namespace Ui {
    class calibratewindow: public Ui_calibratewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATEWINDOW_H
