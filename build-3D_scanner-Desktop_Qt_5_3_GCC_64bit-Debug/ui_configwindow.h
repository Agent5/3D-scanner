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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
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
    QLabel *label_19;
    QLineEdit *centerX1;
    QLabel *label_41;
    QLabel *label_42;
    QLineEdit *centerY1;
    QLabel *label_27;
    QLineEdit *laser_angle_1;
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
    QLabel *label_23;
    QLabel *label_37;
    QLineEdit *centerX2;
    QLabel *label_43;
    QLineEdit *centerY2;
    QLabel *label_28;
    QLineEdit *laser_angle_2;
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
    QLabel *label_24;
    QLineEdit *centerX3;
    QLabel *label_38;
    QLabel *label_44;
    QLineEdit *centerY3;
    QLabel *label_29;
    QLineEdit *laser_angle_3;
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
    QLabel *label_25;
    QLineEdit *centerX4;
    QLabel *label_39;
    QLabel *label_45;
    QLineEdit *centerY4;
    QLabel *label_30;
    QLineEdit *laser_angle_4;
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
    QLabel *label_26;
    QLineEdit *centerX5;
    QLabel *label_40;
    QLabel *label_46;
    QLineEdit *centerY5;
    QLabel *label_31;
    QLineEdit *laser_angle_5;
    QWidget *tab5;
    QLabel *label_4;
    QComboBox *comboBox_3;
    QWidget *tab_2;
    QLineEdit *width;
    QLineEdit *height;
    QLineEdit *sqSize;
    QLineEdit *numOfFrames;
    QLineEdit *frameDelay;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *FileSave;
    QLineEdit *fileSaveLocation;

    void setupUi(QDialog *configwindow)
    {
        if (configwindow->objectName().isEmpty())
            configwindow->setObjectName(QStringLiteral("configwindow"));
        configwindow->resize(672, 424);
        tabWidget = new QTabWidget(configwindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 651, 391));
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
        vDevice1->setGeometry(QRect(50, 50, 111, 23));
        label_3 = new QLabel(tab1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 20, 131, 21));
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
        label_19 = new QLabel(tab1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(260, 20, 191, 21));
        label_19->setFont(font);
        centerX1 = new QLineEdit(tab1);
        centerX1->setObjectName(QStringLiteral("centerX1"));
        centerX1->setGeometry(QRect(270, 60, 71, 29));
        label_41 = new QLabel(tab1);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(240, 60, 31, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_41->setFont(font1);
        label_42 = new QLabel(tab1);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(360, 60, 31, 31));
        label_42->setFont(font1);
        centerY1 = new QLineEdit(tab1);
        centerY1->setObjectName(QStringLiteral("centerY1"));
        centerY1->setGeometry(QRect(400, 60, 71, 29));
        label_27 = new QLabel(tab1);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(290, 100, 191, 31));
        label_27->setFont(font);
        laser_angle_1 = new QLineEdit(tab1);
        laser_angle_1->setObjectName(QStringLiteral("laser_angle_1"));
        laser_angle_1->setGeometry(QRect(320, 140, 71, 29));
        tabWidget->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        label_5 = new QLabel(tab2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 20, 131, 21));
        label_5->setFont(font);
        vDevice2 = new QComboBox(tab2);
        vDevice2->setObjectName(QStringLiteral("vDevice2"));
        vDevice2->setGeometry(QRect(50, 50, 111, 23));
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
        label_23 = new QLabel(tab2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(260, 20, 191, 21));
        label_23->setFont(font);
        label_37 = new QLabel(tab2);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(240, 60, 31, 31));
        label_37->setFont(font1);
        centerX2 = new QLineEdit(tab2);
        centerX2->setObjectName(QStringLiteral("centerX2"));
        centerX2->setGeometry(QRect(270, 60, 71, 29));
        label_43 = new QLabel(tab2);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(360, 60, 31, 31));
        label_43->setFont(font1);
        centerY2 = new QLineEdit(tab2);
        centerY2->setObjectName(QStringLiteral("centerY2"));
        centerY2->setGeometry(QRect(400, 60, 71, 29));
        label_28 = new QLabel(tab2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(290, 100, 191, 31));
        label_28->setFont(font);
        laser_angle_2 = new QLineEdit(tab2);
        laser_angle_2->setObjectName(QStringLiteral("laser_angle_2"));
        laser_angle_2->setGeometry(QRect(320, 140, 71, 29));
        tabWidget->addTab(tab2, QString());
        tab3 = new QWidget();
        tab3->setObjectName(QStringLiteral("tab3"));
        label_8 = new QLabel(tab3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 20, 131, 21));
        label_8->setFont(font);
        vDevice3 = new QComboBox(tab3);
        vDevice3->setObjectName(QStringLiteral("vDevice3"));
        vDevice3->setGeometry(QRect(50, 50, 111, 23));
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
        label_24 = new QLabel(tab3);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(260, 20, 191, 21));
        label_24->setFont(font);
        centerX3 = new QLineEdit(tab3);
        centerX3->setObjectName(QStringLiteral("centerX3"));
        centerX3->setGeometry(QRect(270, 60, 71, 29));
        label_38 = new QLabel(tab3);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(240, 60, 31, 31));
        label_38->setFont(font1);
        label_44 = new QLabel(tab3);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(360, 60, 31, 31));
        label_44->setFont(font1);
        centerY3 = new QLineEdit(tab3);
        centerY3->setObjectName(QStringLiteral("centerY3"));
        centerY3->setGeometry(QRect(400, 60, 71, 29));
        label_29 = new QLabel(tab3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(290, 100, 191, 31));
        label_29->setFont(font);
        laser_angle_3 = new QLineEdit(tab3);
        laser_angle_3->setObjectName(QStringLiteral("laser_angle_3"));
        laser_angle_3->setGeometry(QRect(320, 140, 71, 29));
        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName(QStringLiteral("tab4"));
        label_20 = new QLabel(tab4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(40, 20, 131, 21));
        label_20->setFont(font);
        vDevice4 = new QComboBox(tab4);
        vDevice4->setObjectName(QStringLiteral("vDevice4"));
        vDevice4->setGeometry(QRect(50, 50, 111, 23));
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
        label_25 = new QLabel(tab4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(260, 20, 191, 21));
        label_25->setFont(font);
        centerX4 = new QLineEdit(tab4);
        centerX4->setObjectName(QStringLiteral("centerX4"));
        centerX4->setGeometry(QRect(270, 60, 71, 29));
        label_39 = new QLabel(tab4);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(240, 60, 31, 31));
        label_39->setFont(font1);
        label_45 = new QLabel(tab4);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(360, 60, 31, 31));
        label_45->setFont(font1);
        centerY4 = new QLineEdit(tab4);
        centerY4->setObjectName(QStringLiteral("centerY4"));
        centerY4->setGeometry(QRect(400, 60, 71, 29));
        label_30 = new QLabel(tab4);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(290, 100, 191, 31));
        label_30->setFont(font);
        laser_angle_4 = new QLineEdit(tab4);
        laser_angle_4->setObjectName(QStringLiteral("laser_angle_4"));
        laser_angle_4->setGeometry(QRect(320, 140, 71, 29));
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
        label->setGeometry(QRect(130, 20, 221, 21));
        label->setFont(font);
        label_26 = new QLabel(tab);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(330, 120, 191, 21));
        label_26->setFont(font);
        centerX5 = new QLineEdit(tab);
        centerX5->setObjectName(QStringLiteral("centerX5"));
        centerX5->setGeometry(QRect(350, 150, 71, 29));
        label_40 = new QLabel(tab);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(320, 150, 31, 31));
        label_40->setFont(font1);
        label_46 = new QLabel(tab);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setGeometry(QRect(440, 150, 31, 31));
        label_46->setFont(font1);
        centerY5 = new QLineEdit(tab);
        centerY5->setObjectName(QStringLiteral("centerY5"));
        centerY5->setGeometry(QRect(470, 150, 71, 29));
        label_31 = new QLabel(tab);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(360, 200, 191, 31));
        label_31->setFont(font);
        laser_angle_5 = new QLineEdit(tab);
        laser_angle_5->setObjectName(QStringLiteral("laser_angle_5"));
        laser_angle_5->setGeometry(QRect(380, 240, 71, 29));
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
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        width = new QLineEdit(tab_2);
        width->setObjectName(QStringLiteral("width"));
        width->setGeometry(QRect(230, 30, 113, 23));
        height = new QLineEdit(tab_2);
        height->setObjectName(QStringLiteral("height"));
        height->setGeometry(QRect(230, 60, 113, 23));
        sqSize = new QLineEdit(tab_2);
        sqSize->setObjectName(QStringLiteral("sqSize"));
        sqSize->setGeometry(QRect(230, 90, 113, 23));
        numOfFrames = new QLineEdit(tab_2);
        numOfFrames->setObjectName(QStringLiteral("numOfFrames"));
        numOfFrames->setGeometry(QRect(230, 120, 113, 23));
        frameDelay = new QLineEdit(tab_2);
        frameDelay->setObjectName(QStringLiteral("frameDelay"));
        frameDelay->setGeometry(QRect(230, 150, 113, 23));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 30, 209, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout->addWidget(label_10);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout->addWidget(label_15);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout->addWidget(label_16);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout->addWidget(label_17);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout->addWidget(label_18);

        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 230, 581, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FileSave = new QPushButton(layoutWidget1);
        FileSave->setObjectName(QStringLiteral("FileSave"));

        horizontalLayout->addWidget(FileSave);

        fileSaveLocation = new QLineEdit(layoutWidget1);
        fileSaveLocation->setObjectName(QStringLiteral("fileSaveLocation"));

        horizontalLayout->addWidget(fileSaveLocation);

        tabWidget->addTab(tab_2, QString());

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
        vXAxis1->setPlaceholderText(QString());
        label_11->setText(QApplication::translate("configwindow", "X", 0));
        label_19->setText(QApplication::translate("configwindow", "Center of Turntable", 0));
        label_41->setText(QApplication::translate("configwindow", "X", 0));
        label_42->setText(QApplication::translate("configwindow", "Y", 0));
        label_27->setText(QApplication::translate("configwindow", "Laser Angle", 0));
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
        label_23->setText(QApplication::translate("configwindow", "Center of Turntable", 0));
        label_37->setText(QApplication::translate("configwindow", "X", 0));
        label_43->setText(QApplication::translate("configwindow", "Y", 0));
        label_28->setText(QApplication::translate("configwindow", "Laser Angle", 0));
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
        label_24->setText(QApplication::translate("configwindow", "Center of Turntable", 0));
        label_38->setText(QApplication::translate("configwindow", "X", 0));
        label_44->setText(QApplication::translate("configwindow", "Y", 0));
        label_29->setText(QApplication::translate("configwindow", "Laser Angle", 0));
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
        label_25->setText(QApplication::translate("configwindow", "Center of Turntable", 0));
        label_39->setText(QApplication::translate("configwindow", "X", 0));
        label_45->setText(QApplication::translate("configwindow", "Y", 0));
        label_30->setText(QApplication::translate("configwindow", "Laser Angle", 0));
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
        label_26->setText(QApplication::translate("configwindow", "Center of Turntable", 0));
        label_40->setText(QApplication::translate("configwindow", "X", 0));
        label_46->setText(QApplication::translate("configwindow", "Y", 0));
        label_31->setText(QApplication::translate("configwindow", "Laser Angle", 0));
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
        label_10->setText(QApplication::translate("configwindow", " Number of inner corners: width", 0));
        label_15->setText(QApplication::translate("configwindow", "Number of inner corners: height", 0));
        label_16->setText(QApplication::translate("configwindow", "                              Square unit size", 0));
        label_17->setText(QApplication::translate("configwindow", "                         Number of Frames", 0));
        label_18->setText(QApplication::translate("configwindow", "                                    Frame Delay", 0));
        FileSave->setText(QApplication::translate("configwindow", "File Location", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("configwindow", "Calibration", 0));
    } // retranslateUi

};

namespace Ui {
    class configwindow: public Ui_configwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWINDOW_H
