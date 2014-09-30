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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camerawindow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *calib1;
    QCheckBox *calib2;
    QCheckBox *calib3;
    QCheckBox *calib4;
    QCheckBox *calib5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cam1R;
    QCheckBox *cam1G;
    QCheckBox *cam1B;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cam2R;
    QCheckBox *cam2G;
    QCheckBox *cam2B;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cam3R;
    QCheckBox *cam3G;
    QCheckBox *cam3B;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cam4R;
    QCheckBox *cam4G;
    QCheckBox *cam4B;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cam5R;
    QCheckBox *cam5G;
    QCheckBox *cam5B;

    void setupUi(QDialog *camerawindow)
    {
        if (camerawindow->objectName().isEmpty())
            camerawindow->setObjectName(QStringLiteral("camerawindow"));
        camerawindow->resize(382, 187);
        widget = new QWidget(camerawindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 361, 167));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
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


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        calib1 = new QCheckBox(widget);
        calib1->setObjectName(QStringLiteral("calib1"));

        verticalLayout_4->addWidget(calib1);

        calib2 = new QCheckBox(widget);
        calib2->setObjectName(QStringLiteral("calib2"));

        verticalLayout_4->addWidget(calib2);

        calib3 = new QCheckBox(widget);
        calib3->setObjectName(QStringLiteral("calib3"));

        verticalLayout_4->addWidget(calib3);

        calib4 = new QCheckBox(widget);
        calib4->setObjectName(QStringLiteral("calib4"));

        verticalLayout_4->addWidget(calib4);

        calib5 = new QCheckBox(widget);
        calib5->setObjectName(QStringLiteral("calib5"));

        verticalLayout_4->addWidget(calib5);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cam1R = new QCheckBox(widget);
        cam1R->setObjectName(QStringLiteral("cam1R"));

        horizontalLayout->addWidget(cam1R);

        cam1G = new QCheckBox(widget);
        cam1G->setObjectName(QStringLiteral("cam1G"));

        horizontalLayout->addWidget(cam1G);

        cam1B = new QCheckBox(widget);
        cam1B->setObjectName(QStringLiteral("cam1B"));

        horizontalLayout->addWidget(cam1B);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cam2R = new QCheckBox(widget);
        cam2R->setObjectName(QStringLiteral("cam2R"));

        horizontalLayout_2->addWidget(cam2R);

        cam2G = new QCheckBox(widget);
        cam2G->setObjectName(QStringLiteral("cam2G"));

        horizontalLayout_2->addWidget(cam2G);

        cam2B = new QCheckBox(widget);
        cam2B->setObjectName(QStringLiteral("cam2B"));

        horizontalLayout_2->addWidget(cam2B);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cam3R = new QCheckBox(widget);
        cam3R->setObjectName(QStringLiteral("cam3R"));

        horizontalLayout_3->addWidget(cam3R);

        cam3G = new QCheckBox(widget);
        cam3G->setObjectName(QStringLiteral("cam3G"));

        horizontalLayout_3->addWidget(cam3G);

        cam3B = new QCheckBox(widget);
        cam3B->setObjectName(QStringLiteral("cam3B"));

        horizontalLayout_3->addWidget(cam3B);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cam4R = new QCheckBox(widget);
        cam4R->setObjectName(QStringLiteral("cam4R"));

        horizontalLayout_4->addWidget(cam4R);

        cam4G = new QCheckBox(widget);
        cam4G->setObjectName(QStringLiteral("cam4G"));

        horizontalLayout_4->addWidget(cam4G);

        cam4B = new QCheckBox(widget);
        cam4B->setObjectName(QStringLiteral("cam4B"));

        horizontalLayout_4->addWidget(cam4B);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cam5R = new QCheckBox(widget);
        cam5R->setObjectName(QStringLiteral("cam5R"));

        horizontalLayout_5->addWidget(cam5R);

        cam5G = new QCheckBox(widget);
        cam5G->setObjectName(QStringLiteral("cam5G"));

        horizontalLayout_5->addWidget(cam5G);

        cam5B = new QCheckBox(widget);
        cam5B->setObjectName(QStringLiteral("cam5B"));

        horizontalLayout_5->addWidget(cam5B);


        verticalLayout_5->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_5);


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
        calib1->setText(QApplication::translate("camerawindow", "Calibrate", 0));
        calib2->setText(QApplication::translate("camerawindow", "Calibrate", 0));
        calib3->setText(QApplication::translate("camerawindow", "Calibrate", 0));
        calib4->setText(QApplication::translate("camerawindow", "Calibrate", 0));
        calib5->setText(QApplication::translate("camerawindow", "Calibrate", 0));
        cam1R->setText(QApplication::translate("camerawindow", "R", 0));
        cam1G->setText(QApplication::translate("camerawindow", "G", 0));
        cam1B->setText(QApplication::translate("camerawindow", "B", 0));
        cam2R->setText(QApplication::translate("camerawindow", "R", 0));
        cam2G->setText(QApplication::translate("camerawindow", "G", 0));
        cam2B->setText(QApplication::translate("camerawindow", "B", 0));
        cam3R->setText(QApplication::translate("camerawindow", "R", 0));
        cam3G->setText(QApplication::translate("camerawindow", "G", 0));
        cam3B->setText(QApplication::translate("camerawindow", "B", 0));
        cam4R->setText(QApplication::translate("camerawindow", "R", 0));
        cam4G->setText(QApplication::translate("camerawindow", "G", 0));
        cam4B->setText(QApplication::translate("camerawindow", "B", 0));
        cam5R->setText(QApplication::translate("camerawindow", "R", 0));
        cam5G->setText(QApplication::translate("camerawindow", "G", 0));
        cam5B->setText(QApplication::translate("camerawindow", "B", 0));
    } // retranslateUi

};

namespace Ui {
    class camerawindow: public Ui_camerawindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWINDOW_H
