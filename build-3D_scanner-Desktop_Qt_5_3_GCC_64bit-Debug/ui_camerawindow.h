/********************************************************************************
** Form generated from reading UI file 'camerawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWINDOW_H
#define UI_CAMERAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camerawindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *camerawindow)
    {
        if (camerawindow->objectName().isEmpty())
            camerawindow->setObjectName(QStringLiteral("camerawindow"));
        camerawindow->resize(139, 202);
        widget = new QWidget(camerawindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 109, 145));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);


        retranslateUi(camerawindow);

        QMetaObject::connectSlotsByName(camerawindow);
    } // setupUi

    void retranslateUi(QDialog *camerawindow)
    {
        camerawindow->setWindowTitle(QApplication::translate("camerawindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("camerawindow", "Show Camera 1", 0));
        pushButton_2->setText(QApplication::translate("camerawindow", "Show Camera 2", 0));
        pushButton_3->setText(QApplication::translate("camerawindow", "Show Camera 3", 0));
        pushButton_4->setText(QApplication::translate("camerawindow", "Show Camera 4", 0));
        pushButton_5->setText(QApplication::translate("camerawindow", "Show IP camera", 0));
    } // retranslateUi

};

namespace Ui {
    class camerawindow: public Ui_camerawindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOW_H
