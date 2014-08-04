/********************************************************************************
** Form generated from reading UI file 'configwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGWINDOW_H
#define UI_CONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configwindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab1;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QComboBox *vResolution1;
    QLabel *label_2;
    QComboBox *vDevice1;
    QLabel *label_3;
    QLineEdit *vXAxis1;
    QLineEdit *vYAxis1;
    QLabel *label_11;
    QLabel *vStatus1;
    QWidget *tab2;
    QLabel *label_5;
    QComboBox *vDevice2;
    QLabel *label_6;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QComboBox *vResolution2;
    QLabel *label_7;
    QLineEdit *vXAxis2;
    QLineEdit *vYAxis2;
    QLabel *vStatus2;
    QWidget *tab3;
    QLabel *label_8;
    QComboBox *vDevice3;
    QLabel *label_9;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QComboBox *vResolution3;
    QLineEdit *vXAxis3;
    QLineEdit *vYAxis3;
    QLabel *label_12;
    QLabel *vStatus3;
    QWidget *tab4;
    QLabel *label_20;
    QComboBox *vDevice4;
    QLabel *label_21;
    QRadioButton *radioButton_13;
    QRadioButton *radioButton_14;
    QComboBox *vResolution4;
    QLineEdit *vXAxis4;
    QLineEdit *vYAxis4;
    QLabel *label_13;
    QLabel *vStatus4;
    QWidget *tab;
    QLabel *label_22;
    QRadioButton *radioButton_15;
    QRadioButton *radioButton_16;
    QComboBox *vResolution5;
    QLineEdit *vXAxis5;
    QLineEdit *vYAxis5;
    QLabel *label_14;
    QLineEdit *vURL;
    QLabel *label;
    QWidget *tab5;
    QLabel *label_4;
    QComboBox *comboBox_3;

    void setupUi(QDialog *configwindow)
    {
        if (configwindow->objectName().isEmpty())
            configwindow->setObjectName(QStringLiteral("configwindow"));
        configwindow->resize(574, 423);
        tabWidget = new QTabWidget(configwindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 551, 391));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        radioButton = new QRadioButton(tab1);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 210, 16, 21));
        radioButton_2 = new QRadioButton(tab1);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 250, 16, 21));
        vResolution1 = new QComboBox(tab1);
        vResolution1->setObjectName(QStringLiteral("vResolution1"));
        vResolution1->setGeometry(QRect(50, 210, 101, 23));
        label_2 = new QLabel(tab1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 160, 111, 31));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        vDevice1 = new QComboBox(tab1);
        vDevice1->setObjectName(QStringLiteral("vDevice1"));
        vDevice1->setGeometry(QRect(50, 50, 101, 23));
        label_3 = new QLabel(tab1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 20, 131, 16));
        label_3->setFont(font);
        vXAxis1 = new QLineEdit(tab1);
        vXAxis1->setObjectName(QStringLiteral("vXAxis1"));
        vXAxis1->setGeometry(QRect(50, 250, 61, 23));
        vYAxis1 = new QLineEdit(tab1);
        vYAxis1->setObjectName(QStringLiteral("vYAxis1"));
        vYAxis1->setGeometry(QRect(140, 250, 61, 23));
        label_11 = new QLabel(tab1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 250, 21, 21));
        label_11->setFont(font);
        vStatus1 = new QLabel(tab1);
        vStatus1->setObjectName(QStringLiteral("vStatus1"));
        vStatus1->setGeometry(QRect(50, 90, 221, 16));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 20, 131, 16));
        label_5->setFont(font);
        vDevice2 = new QComboBox(tab2);
        vDevice2->setObjectName(QStringLiteral("vDevice2"));
        vDevice2->setGeometry(QRect(50, 50, 101, 23));
        label_6 = new QLabel(tab2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 160, 111, 31));
        label_6->setFont(font);
        radioButton_3 = new QRadioButton(tab2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 210, 16, 21));
        radioButton_4 = new QRadioButton(tab2);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 250, 16, 21));
        vResolution2 = new QComboBox(tab2);
        vResolution2->setObjectName(QStringLiteral("vResolution2"));
        vResolution2->setGeometry(QRect(50, 210, 101, 23));
        label_7 = new QLabel(tab2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 250, 21, 21));
        label_7->setFont(font);
        vXAxis2 = new QLineEdit(tab2);
        vXAxis2->setObjectName(QStringLiteral("vXAxis2"));
        vXAxis2->setGeometry(QRect(50, 250, 61, 23));
        vYAxis2 = new QLineEdit(tab2);
        vYAxis2->setObjectName(QStringLiteral("vYAxis2"));
        vYAxis2->setGeometry(QRect(140, 250, 61, 23));
        vStatus2 = new QLabel(tab2);
        vStatus2->setObjectName(QStringLiteral("vStatus2"));
        vStatus2->setGeometry(QRect(50, 90, 221, 16));
        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        label_8 = new QLabel(tab3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 20, 131, 16));
        label_8->setFont(font);
        vDevice3 = new QComboBox(tab3);
        vDevice3->setObjectName(QStringLiteral("vDevice3"));
        vDevice3->setGeometry(QRect(50, 50, 101, 23));
        label_9 = new QLabel(tab3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 160, 111, 31));
        label_9->setFont(font);
        radioButton_5 = new QRadioButton(tab3);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setGeometry(QRect(20, 210, 16, 21));
        radioButton_6 = new QRadioButton(tab3);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));
        radioButton_6->setGeometry(QRect(20, 250, 16, 21));
        vResolution3 = new QComboBox(tab3);
        vResolution3->setObjectName(QStringLiteral("vResolution3"));
        vResolution3->setGeometry(QRect(50, 210, 101, 23));
        vXAxis3 = new QLineEdit(tab3);
        vXAxis3->setObjectName(QStringLiteral("vXAxis3"));
        vXAxis3->setGeometry(QRect(50, 250, 61, 23));
        vYAxis3 = new QLineEdit(tab3);
        vYAxis3->setObjectName(QStringLiteral("vYAxis3"));
        vYAxis3->setGeometry(QRect(140, 250, 61, 23));
        label_12 = new QLabel(tab3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(120, 250, 21, 21));
        label_12->setFont(font);
        vStatus3 = new QLabel(tab3);
        vStatus3->setObjectName(QStringLiteral("vStatus3"));
        vStatus3->setGeometry(QRect(50, 90, 221, 16));
        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        label_20 = new QLabel(tab4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 20, 131, 16));
        label_20->setFont(font);
        vDevice4 = new QComboBox(tab4);
        vDevice4->setObjectName(QStringLiteral("vDevice4"));
        vDevice4->setGeometry(QRect(50, 50, 101, 23));
        label_21 = new QLabel(tab4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(50, 160, 111, 31));
        label_21->setFont(font);
        radioButton_13 = new QRadioButton(tab4);
        radioButton_13->setObjectName(QStringLiteral("radioButton_13"));
        radioButton_13->setGeometry(QRect(20, 210, 16, 21));
        radioButton_14 = new QRadioButton(tab4);
        radioButton_14->setObjectName(QStringLiteral("radioButton_14"));
        radioButton_14->setGeometry(QRect(20, 250, 16, 21));
        vResolution4 = new QComboBox(tab4);
        vResolution4->setObjectName(QStringLiteral("vResolution4"));
        vResolution4->setGeometry(QRect(50, 210, 101, 23));
        vXAxis4 = new QLineEdit(tab4);
        vXAxis4->setObjectName(QStringLiteral("vXAxis4"));
        vXAxis4->setGeometry(QRect(50, 250, 61, 23));
        vYAxis4 = new QLineEdit(tab4);
        vYAxis4->setObjectName(QStringLiteral("vYAxis4"));
        vYAxis4->setGeometry(QRect(140, 250, 61, 23));
        label_13 = new QLabel(tab4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(120, 250, 21, 21));
        label_13->setFont(font);
        vStatus4 = new QLabel(tab4);
        vStatus4->setObjectName(QStringLiteral("vStatus4"));
        vStatus4->setGeometry(QRect(50, 90, 221, 16));
        tabWidget->addTab(tab4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(50, 160, 111, 31));
        label_22->setFont(font);
        radioButton_15 = new QRadioButton(tab);
        radioButton_15->setObjectName(QStringLiteral("radioButton_15"));
        radioButton_15->setGeometry(QRect(20, 210, 16, 21));
        radioButton_16 = new QRadioButton(tab);
        radioButton_16->setObjectName(QStringLiteral("radioButton_16"));
        radioButton_16->setGeometry(QRect(20, 250, 16, 21));
        vResolution5 = new QComboBox(tab);
        vResolution5->setObjectName(QStringLiteral("vResolution5"));
        vResolution5->setGeometry(QRect(50, 210, 101, 23));
        vXAxis5 = new QLineEdit(tab);
        vXAxis5->setObjectName(QStringLiteral("vXAxis5"));
        vXAxis5->setGeometry(QRect(50, 250, 61, 23));
        vYAxis5 = new QLineEdit(tab);
        vYAxis5->setObjectName(QStringLiteral("vYAxis5"));
        vYAxis5->setGeometry(QRect(140, 250, 61, 23));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(120, 250, 21, 21));
        label_14->setFont(font);
        vURL = new QLineEdit(tab);
        vURL->setObjectName(QStringLiteral("vURL"));
        vURL->setGeometry(QRect(50, 50, 381, 23));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 20, 221, 16));
        label->setFont(font);
        tabWidget->addTab(tab, QString());
        tab5 = new QWidget();
        tab5->setObjectName(QStringLiteral("tab5"));
        label_4 = new QLabel(tab5);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 20, 131, 16));
        label_4->setFont(font);
        comboBox_3 = new QComboBox(tab5);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(40, 50, 121, 23));
        tabWidget->addTab(tab5, QString());

        retranslateUi(configwindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(configwindow);
    } // setupUi

    void retranslateUi(QDialog *configwindow)
    {
        configwindow->setWindowTitle(QApplication::translate("configwindow", "Dialog", 0));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        vResolution1->clear();
        vResolution1->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "160x90", 0)
         << QApplication::translate("configwindow", "160x120", 0)
         << QApplication::translate("configwindow", "176x144", 0)
         << QApplication::translate("configwindow", "320x180", 0)
         << QApplication::translate("configwindow", "320x240", 0)
         << QApplication::translate("configwindow", "352x288", 0)
         << QApplication::translate("configwindow", "432x240", 0)
         << QApplication::translate("configwindow", "640x360", 0)
         << QApplication::translate("configwindow", "640x480", 0)
         << QApplication::translate("configwindow", "800x448", 0)
         << QApplication::translate("configwindow", "800x600", 0)
         << QApplication::translate("configwindow", "864x480", 0)
         << QApplication::translate("configwindow", "960x720", 0)
         << QApplication::translate("configwindow", "1024x576", 0)
         << QApplication::translate("configwindow", "1280x720", 0)
         << QApplication::translate("configwindow", "1600x896", 0)
         << QApplication::translate("configwindow", "1920x1080", 0)
         << QApplication::translate("configwindow", "2304x1296", 0)
         << QApplication::translate("configwindow", "2304x1536", 0)
        );
        label_2->setText(QApplication::translate("configwindow", "Resolution", 0));
        vDevice1->clear();
        vDevice1->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("configwindow", "/dev/video0", 0)
         << QApplication::translate("configwindow", "/dev/video1", 0)
         << QApplication::translate("configwindow", "/dev/video2", 0)
         << QApplication::translate("configwindow", "/dev/video3", 0)
        );
        label_3->setText(QApplication::translate("configwindow", "Video Device", 0));
        label_11->setText(QApplication::translate("configwindow", "X", 0));
        vStatus1->setText(QApplication::translate("configwindow", "Video Status", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("configwindow", "Vid Device 1", 0));
        label_5->setText(QApplication::translate("configwindow", "Video Device", 0));
        vDevice2->clear();
        vDevice2->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("configwindow", "/dev/video0", 0)
         << QApplication::translate("configwindow", "/dev/video1", 0)
         << QApplication::translate("configwindow", "/dev/video2", 0)
         << QApplication::translate("configwindow", "/dev/video3", 0)
        );
        label_6->setText(QApplication::translate("configwindow", "Resolution", 0));
        radioButton_3->setText(QString());
        radioButton_4->setText(QString());
        vResolution2->clear();
        vResolution2->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "160x90", 0)
         << QApplication::translate("configwindow", "160x120", 0)
         << QApplication::translate("configwindow", "176x144", 0)
         << QApplication::translate("configwindow", "320x180", 0)
         << QApplication::translate("configwindow", "320x240", 0)
         << QApplication::translate("configwindow", "352x288", 0)
         << QApplication::translate("configwindow", "432x240", 0)
         << QApplication::translate("configwindow", "640x360", 0)
         << QApplication::translate("configwindow", "640x480", 0)
         << QApplication::translate("configwindow", "800x448", 0)
         << QApplication::translate("configwindow", "800x600", 0)
         << QApplication::translate("configwindow", "864x480", 0)
         << QApplication::translate("configwindow", "960x720", 0)
         << QApplication::translate("configwindow", "1024x576", 0)
         << QApplication::translate("configwindow", "1280x720", 0)
         << QApplication::translate("configwindow", "1600x896", 0)
         << QApplication::translate("configwindow", "1920x1080", 0)
         << QApplication::translate("configwindow", "2304x1296", 0)
         << QApplication::translate("configwindow", "2304x1536", 0)
        );
        label_7->setText(QApplication::translate("configwindow", "X", 0));
        vStatus2->setText(QApplication::translate("configwindow", "Video Status", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab2), QApplication::translate("configwindow", "Vid Device 2", 0));
        label_8->setText(QApplication::translate("configwindow", "Video Device", 0));
        vDevice3->clear();
        vDevice3->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("configwindow", "/dev/video0", 0)
         << QApplication::translate("configwindow", "/dev/video1", 0)
         << QApplication::translate("configwindow", "/dev/video2", 0)
         << QApplication::translate("configwindow", "/dev/video3", 0)
        );
        label_9->setText(QApplication::translate("configwindow", "Resolution", 0));
        radioButton_5->setText(QString());
        radioButton_6->setText(QString());
        vResolution3->clear();
        vResolution3->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "160x90", 0)
         << QApplication::translate("configwindow", "160x120", 0)
         << QApplication::translate("configwindow", "176x144", 0)
         << QApplication::translate("configwindow", "320x180", 0)
         << QApplication::translate("configwindow", "320x240", 0)
         << QApplication::translate("configwindow", "352x288", 0)
         << QApplication::translate("configwindow", "432x240", 0)
         << QApplication::translate("configwindow", "640x360", 0)
         << QApplication::translate("configwindow", "640x480", 0)
         << QApplication::translate("configwindow", "800x448", 0)
         << QApplication::translate("configwindow", "800x600", 0)
         << QApplication::translate("configwindow", "864x480", 0)
         << QApplication::translate("configwindow", "960x720", 0)
         << QApplication::translate("configwindow", "1024x576", 0)
         << QApplication::translate("configwindow", "1280x720", 0)
         << QApplication::translate("configwindow", "1600x896", 0)
         << QApplication::translate("configwindow", "1920x1080", 0)
         << QApplication::translate("configwindow", "2304x1296", 0)
         << QApplication::translate("configwindow", "2304x1536", 0)
        );
        label_12->setText(QApplication::translate("configwindow", "X", 0));
        vStatus3->setText(QApplication::translate("configwindow", "Video Status", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QApplication::translate("configwindow", "Vid Device 3", 0));
        label_20->setText(QApplication::translate("configwindow", "Video Device", 0));
        vDevice4->clear();
        vDevice4->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("configwindow", "/dev/video0", 0)
         << QApplication::translate("configwindow", "/dev/video1", 0)
         << QApplication::translate("configwindow", "/dev/video2", 0)
         << QApplication::translate("configwindow", "/dev/video3", 0)
        );
        label_21->setText(QApplication::translate("configwindow", "Resolution", 0));
        radioButton_13->setText(QString());
        radioButton_14->setText(QString());
        vResolution4->clear();
        vResolution4->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "160x90", 0)
         << QApplication::translate("configwindow", "160x120", 0)
         << QApplication::translate("configwindow", "176x144", 0)
         << QApplication::translate("configwindow", "320x180", 0)
         << QApplication::translate("configwindow", "320x240", 0)
         << QApplication::translate("configwindow", "352x288", 0)
         << QApplication::translate("configwindow", "432x240", 0)
         << QApplication::translate("configwindow", "640x360", 0)
         << QApplication::translate("configwindow", "640x480", 0)
         << QApplication::translate("configwindow", "800x448", 0)
         << QApplication::translate("configwindow", "800x600", 0)
         << QApplication::translate("configwindow", "864x480", 0)
         << QApplication::translate("configwindow", "960x720", 0)
         << QApplication::translate("configwindow", "1024x576", 0)
         << QApplication::translate("configwindow", "1280x720", 0)
         << QApplication::translate("configwindow", "1600x896", 0)
         << QApplication::translate("configwindow", "1920x1080", 0)
         << QApplication::translate("configwindow", "2304x1296", 0)
         << QApplication::translate("configwindow", "2304x1536", 0)
        );
        label_13->setText(QApplication::translate("configwindow", "X", 0));
        vStatus4->setText(QApplication::translate("configwindow", "Video Status", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QApplication::translate("configwindow", "Vid Device 4", 0));
        label_22->setText(QApplication::translate("configwindow", "Resolution", 0));
        radioButton_15->setText(QString());
        radioButton_16->setText(QString());
        vResolution5->clear();
        vResolution5->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "160x90", 0)
         << QApplication::translate("configwindow", "160x120", 0)
         << QApplication::translate("configwindow", "176x144", 0)
         << QApplication::translate("configwindow", "320x180", 0)
         << QApplication::translate("configwindow", "320x240", 0)
         << QApplication::translate("configwindow", "352x288", 0)
         << QApplication::translate("configwindow", "432x240", 0)
         << QApplication::translate("configwindow", "640x360", 0)
         << QApplication::translate("configwindow", "640x480", 0)
         << QApplication::translate("configwindow", "800x448", 0)
         << QApplication::translate("configwindow", "800x600", 0)
         << QApplication::translate("configwindow", "864x480", 0)
         << QApplication::translate("configwindow", "960x720", 0)
         << QApplication::translate("configwindow", "1024x576", 0)
         << QApplication::translate("configwindow", "1280x720", 0)
         << QApplication::translate("configwindow", "1600x896", 0)
         << QApplication::translate("configwindow", "1920x1080", 0)
         << QApplication::translate("configwindow", "2304x1296", 0)
         << QApplication::translate("configwindow", "2304x1536", 0)
        );
        label_14->setText(QApplication::translate("configwindow", "X", 0));
        label->setText(QApplication::translate("configwindow", "URL of MJPEG interface", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("configwindow", "IP Camera", 0));
        label_4->setText(QApplication::translate("configwindow", "Serial Device", 0));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("configwindow", "/dev/ttyUSB0", 0)
         << QApplication::translate("configwindow", "/dev/ttyUSB1", 0)
         << QApplication::translate("configwindow", "/dev/ttyUSB2", 0)
         << QApplication::translate("configwindow", "/dev/ttyUSB3", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab5), QApplication::translate("configwindow", "Serial", 0));
    } // retranslateUi

};

namespace Ui {
    class configwindow: public Ui_configwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWINDOW_H
