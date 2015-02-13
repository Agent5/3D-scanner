/********************************************************************************
** Form generated from reading UI file 'scanwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANWINDOW_H
#define UI_SCANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_scanwindow
{
public:

    void setupUi(QDialog *scanwindow)
    {
        if (scanwindow->objectName().isEmpty())
            scanwindow->setObjectName(QStringLiteral("scanwindow"));
        scanwindow->resize(400, 300);

        retranslateUi(scanwindow);

        QMetaObject::connectSlotsByName(scanwindow);
    } // setupUi

    void retranslateUi(QDialog *scanwindow)
    {
        scanwindow->setWindowTitle(QApplication::translate("scanwindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class scanwindow: public Ui_scanwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANWINDOW_H
