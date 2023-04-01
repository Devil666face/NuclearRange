/********************************************************************************
** Form generated from reading UI file 'inputwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTWINDOW_H
#define UI_INPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_blast;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QComboBox *comboBox_type;
    QLabel *label_2;
    QComboBox *comboBox_q;
    QLabel *label_3;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_lon;
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_lat;
    QLabel *label_8;
    QGridLayout *lay_coor;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_weather;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_weater;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_people;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QSpinBox *spinBox_t_enter;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *spinBox_T_work;
    QLabel *label_12;
    QLabel *label_14;
    QSpinBox *spinBox_D_before;
    QLabel *label_13;
    QLabel *label_19;
    QSpinBox *spinBox_N_count;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *doubleSpinBox_lon_work;
    QDoubleSpinBox *doubleSpinBox_lat_work;
    QLabel *label_15;
    QLabel *label_18;
    QLabel *label_16;
    QLabel *label_17;
    QGridLayout *lay_coor_work;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_radiation;
    QGridLayout *gridLayout_4;
    QLabel *label_20;
    QSpinBox *spinBox_D_cloud;
    QLabel *label_21;
    QLabel *label_22;
    QSpinBox *spinBox_D_ground;
    QLabel *label_23;
    QLabel *label_24;
    QSpinBox *spinBox_t_delta_nuclear;
    QLabel *label_25;
    QLabel *label_26;
    QSpinBox *spinBox_A_air;
    QLabel *label_27;
    QGridLayout *lay_enter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InputWindow)
    {
        if (InputWindow->objectName().isEmpty())
            InputWindow->setObjectName(QString::fromUtf8("InputWindow"));
        InputWindow->resize(924, 523);
        centralwidget = new QWidget(InputWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_blast = new QGroupBox(frame);
        groupBox_blast->setObjectName(QString::fromUtf8("groupBox_blast"));
        gridLayout_5 = new QGridLayout(groupBox_blast);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(groupBox_blast);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        comboBox_type = new QComboBox(groupBox_blast);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        gridLayout_5->addWidget(comboBox_type, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_blast);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        comboBox_q = new QComboBox(groupBox_blast);
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->addItem(QString());
        comboBox_q->setObjectName(QString::fromUtf8("comboBox_q"));

        gridLayout_5->addWidget(comboBox_q, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_blast);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_blast);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 2, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBox_blast);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setWrapping(false);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        gridLayout_5->addWidget(dateTimeEdit, 2, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(groupBox_blast);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        doubleSpinBox_lon = new QDoubleSpinBox(groupBox_blast);
        doubleSpinBox_lon->setObjectName(QString::fromUtf8("doubleSpinBox_lon"));
        doubleSpinBox_lon->setEnabled(false);
        doubleSpinBox_lon->setReadOnly(true);
        doubleSpinBox_lon->setMinimum(-360.000000000000000);
        doubleSpinBox_lon->setMaximum(360.000000000000000);
        doubleSpinBox_lon->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_lon, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_blast);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_blast);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        doubleSpinBox_lat = new QDoubleSpinBox(groupBox_blast);
        doubleSpinBox_lat->setObjectName(QString::fromUtf8("doubleSpinBox_lat"));
        doubleSpinBox_lat->setEnabled(false);
        doubleSpinBox_lat->setReadOnly(false);
        doubleSpinBox_lat->setMinimum(-360.000000000000000);
        doubleSpinBox_lat->setMaximum(360.000000000000000);
        doubleSpinBox_lat->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_lat, 1, 1, 1, 1);

        label_8 = new QLabel(groupBox_blast);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 1, 2, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        lay_coor = new QGridLayout();
        lay_coor->setObjectName(QString::fromUtf8("lay_coor"));

        horizontalLayout_2->addLayout(lay_coor);


        gridLayout_5->addLayout(horizontalLayout_2, 3, 0, 1, 3);


        verticalLayout_5->addWidget(groupBox_blast);


        gridLayout_6->addWidget(frame, 0, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::WinPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_weather = new QGroupBox(frame_2);
        groupBox_weather->setObjectName(QString::fromUtf8("groupBox_weather"));
        verticalLayout = new QVBoxLayout(groupBox_weather);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_weater = new QTableWidget(groupBox_weather);
        tableWidget_weater->setObjectName(QString::fromUtf8("tableWidget_weater"));

        verticalLayout->addWidget(tableWidget_weater);


        verticalLayout_6->addWidget(groupBox_weather);


        gridLayout_6->addWidget(frame_2, 0, 1, 1, 1);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::WinPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_people = new QGroupBox(frame_3);
        groupBox_people->setObjectName(QString::fromUtf8("groupBox_people"));
        gridLayout_3 = new QGridLayout(groupBox_people);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(groupBox_people);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        spinBox_t_enter = new QSpinBox(groupBox_people);
        spinBox_t_enter->setObjectName(QString::fromUtf8("spinBox_t_enter"));
        spinBox_t_enter->setValue(1);

        gridLayout_3->addWidget(spinBox_t_enter, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox_people);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 2, 1, 1);

        label_11 = new QLabel(groupBox_people);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        spinBox_T_work = new QSpinBox(groupBox_people);
        spinBox_T_work->setObjectName(QString::fromUtf8("spinBox_T_work"));
        spinBox_T_work->setValue(3);

        gridLayout_3->addWidget(spinBox_T_work, 1, 1, 1, 1);

        label_12 = new QLabel(groupBox_people);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 1, 2, 1, 1);

        label_14 = new QLabel(groupBox_people);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 2, 0, 1, 1);

        spinBox_D_before = new QSpinBox(groupBox_people);
        spinBox_D_before->setObjectName(QString::fromUtf8("spinBox_D_before"));
        spinBox_D_before->setMaximum(100000);
        spinBox_D_before->setSingleStep(10);
        spinBox_D_before->setValue(100);

        gridLayout_3->addWidget(spinBox_D_before, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox_people);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 2, 1, 1);

        label_19 = new QLabel(groupBox_people);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_19, 3, 0, 1, 1);

        spinBox_N_count = new QSpinBox(groupBox_people);
        spinBox_N_count->setObjectName(QString::fromUtf8("spinBox_N_count"));
        spinBox_N_count->setValue(1);

        gridLayout_3->addWidget(spinBox_N_count, 3, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        doubleSpinBox_lon_work = new QDoubleSpinBox(groupBox_people);
        doubleSpinBox_lon_work->setObjectName(QString::fromUtf8("doubleSpinBox_lon_work"));
        doubleSpinBox_lon_work->setEnabled(false);
        doubleSpinBox_lon_work->setReadOnly(true);
        doubleSpinBox_lon_work->setMinimum(-360.000000000000000);
        doubleSpinBox_lon_work->setMaximum(360.000000000000000);
        doubleSpinBox_lon_work->setValue(0.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_lon_work, 0, 1, 1, 1);

        doubleSpinBox_lat_work = new QDoubleSpinBox(groupBox_people);
        doubleSpinBox_lat_work->setObjectName(QString::fromUtf8("doubleSpinBox_lat_work"));
        doubleSpinBox_lat_work->setEnabled(false);
        doubleSpinBox_lat_work->setReadOnly(false);
        doubleSpinBox_lat_work->setMinimum(-360.000000000000000);
        doubleSpinBox_lat_work->setMaximum(360.000000000000000);
        doubleSpinBox_lat_work->setValue(0.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox_lat_work, 1, 1, 1, 1);

        label_15 = new QLabel(groupBox_people);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_15, 0, 0, 1, 1);

        label_18 = new QLabel(groupBox_people);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 0, 2, 1, 1);

        label_16 = new QLabel(groupBox_people);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 1, 2, 1, 1);

        label_17 = new QLabel(groupBox_people);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_17, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 4, 0, 1, 1);

        lay_coor_work = new QGridLayout();
        lay_coor_work->setObjectName(QString::fromUtf8("lay_coor_work"));

        gridLayout_3->addLayout(lay_coor_work, 4, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_people);


        gridLayout_6->addWidget(frame_3, 1, 0, 1, 1);

        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::WinPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_radiation = new QGroupBox(frame_4);
        groupBox_radiation->setObjectName(QString::fromUtf8("groupBox_radiation"));
        gridLayout_4 = new QGridLayout(groupBox_radiation);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_20 = new QLabel(groupBox_radiation);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_20, 0, 0, 1, 1);

        spinBox_D_cloud = new QSpinBox(groupBox_radiation);
        spinBox_D_cloud->setObjectName(QString::fromUtf8("spinBox_D_cloud"));
        spinBox_D_cloud->setMaximum(1000000);
        spinBox_D_cloud->setSingleStep(100);
        spinBox_D_cloud->setValue(200);

        gridLayout_4->addWidget(spinBox_D_cloud, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox_radiation);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 0, 2, 1, 1);

        label_22 = new QLabel(groupBox_radiation);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_22, 0, 3, 1, 1);

        spinBox_D_ground = new QSpinBox(groupBox_radiation);
        spinBox_D_ground->setObjectName(QString::fromUtf8("spinBox_D_ground"));
        spinBox_D_ground->setMaximum(100000);
        spinBox_D_ground->setSingleStep(100);
        spinBox_D_ground->setValue(150);

        gridLayout_4->addWidget(spinBox_D_ground, 0, 4, 1, 2);

        label_23 = new QLabel(groupBox_radiation);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_4->addWidget(label_23, 0, 6, 1, 2);

        label_24 = new QLabel(groupBox_radiation);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_24, 1, 0, 1, 1);

        spinBox_t_delta_nuclear = new QSpinBox(groupBox_radiation);
        spinBox_t_delta_nuclear->setObjectName(QString::fromUtf8("spinBox_t_delta_nuclear"));
        spinBox_t_delta_nuclear->setMaximum(99);
        spinBox_t_delta_nuclear->setSingleStep(1);
        spinBox_t_delta_nuclear->setValue(1);

        gridLayout_4->addWidget(spinBox_t_delta_nuclear, 1, 1, 1, 1);

        label_25 = new QLabel(groupBox_radiation);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 1, 2, 1, 1);

        label_26 = new QLabel(groupBox_radiation);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_26, 1, 3, 1, 2);

        spinBox_A_air = new QSpinBox(groupBox_radiation);
        spinBox_A_air->setObjectName(QString::fromUtf8("spinBox_A_air"));
        spinBox_A_air->setValue(1);

        gridLayout_4->addWidget(spinBox_A_air, 1, 5, 1, 2);

        label_27 = new QLabel(groupBox_radiation);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 1, 7, 1, 1);


        verticalLayout_3->addWidget(groupBox_radiation);


        gridLayout_6->addWidget(frame_4, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_6);

        lay_enter = new QGridLayout();
        lay_enter->setObjectName(QString::fromUtf8("lay_enter"));

        verticalLayout_4->addLayout(lay_enter);

        InputWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InputWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 924, 26));
        InputWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(InputWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        InputWindow->setStatusBar(statusbar);

        retranslateUi(InputWindow);

        QMetaObject::connectSlotsByName(InputWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InputWindow)
    {
        InputWindow->setWindowTitle(QCoreApplication::translate("InputWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        groupBox_blast->setTitle(QCoreApplication::translate("InputWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\262\320\267\321\200\321\213\320\262\320\260", nullptr));
        label->setText(QCoreApplication::translate("InputWindow", "\320\222\320\270\320\264 \320\262\320\267\321\200\321\213\320\262\320\260", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("InputWindow", "\320\222\320\276\320\267\320\264\321\203\321\210\320\275\321\213\320\271", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("InputWindow", "\320\235\320\260\320\267\320\265\320\274\320\275\321\213\320\271", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("InputWindow", "\320\235\320\260\320\264\320\262\320\276\320\264\320\275\321\213\320\271", nullptr));
        comboBox_type->setItemText(3, QCoreApplication::translate("InputWindow", "\320\237\320\276\320\264\320\267\320\265\320\274\320\275\321\213\320\271", nullptr));
        comboBox_type->setItemText(4, QCoreApplication::translate("InputWindow", "\320\237\320\276\320\264\320\262\320\276\320\264\320\275\321\213\320\271", nullptr));

        label_2->setText(QCoreApplication::translate("InputWindow", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214 \320\262\320\267\321\200\321\213\320\262\320\260", nullptr));
        comboBox_q->setItemText(0, QCoreApplication::translate("InputWindow", "0.1", nullptr));
        comboBox_q->setItemText(1, QCoreApplication::translate("InputWindow", "0.2", nullptr));
        comboBox_q->setItemText(2, QCoreApplication::translate("InputWindow", "0.5", nullptr));
        comboBox_q->setItemText(3, QCoreApplication::translate("InputWindow", "1", nullptr));
        comboBox_q->setItemText(4, QCoreApplication::translate("InputWindow", "2", nullptr));
        comboBox_q->setItemText(5, QCoreApplication::translate("InputWindow", "5", nullptr));
        comboBox_q->setItemText(6, QCoreApplication::translate("InputWindow", "10", nullptr));
        comboBox_q->setItemText(7, QCoreApplication::translate("InputWindow", "20", nullptr));
        comboBox_q->setItemText(8, QCoreApplication::translate("InputWindow", "50", nullptr));
        comboBox_q->setItemText(9, QCoreApplication::translate("InputWindow", "100", nullptr));
        comboBox_q->setItemText(10, QCoreApplication::translate("InputWindow", "200", nullptr));
        comboBox_q->setItemText(11, QCoreApplication::translate("InputWindow", "500", nullptr));
        comboBox_q->setItemText(12, QCoreApplication::translate("InputWindow", "1000", nullptr));
        comboBox_q->setItemText(13, QCoreApplication::translate("InputWindow", "2000", nullptr));
        comboBox_q->setItemText(14, QCoreApplication::translate("InputWindow", "5000", nullptr));
        comboBox_q->setItemText(15, QCoreApplication::translate("InputWindow", "10000", nullptr));

        label_3->setText(QCoreApplication::translate("InputWindow", "\321\202\321\213\321\201. \321\202", nullptr));
        label_4->setText(QCoreApplication::translate("InputWindow", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217\n"
"\320\262\320\267\321\200\321\213\320\262\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("InputWindow", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260", nullptr));
        label_7->setText(QCoreApplication::translate("InputWindow", "\302\260", nullptr));
        label_6->setText(QCoreApplication::translate("InputWindow", "\320\250\320\270\321\200\320\276\321\202\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("InputWindow", "\302\260", nullptr));
        groupBox_weather->setTitle(QCoreApplication::translate("InputWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\265\321\202\320\265\320\276\320\261\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270", nullptr));
        groupBox_people->setTitle(QCoreApplication::translate("InputWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\273/\321\201", nullptr));
        label_9->setText(QCoreApplication::translate("InputWindow", "\320\222\321\200\320\265\320\274\321\217 \320\262\321\205\320\276\320\264\320\260 \320\273/\321\201 \320\262 \320\267\320\276\320\275\321\203\321\202\n"
"\320\277\320\276\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\277\320\276\321\201\320\273\320\265 \320\262\320\267\321\200\321\213\320\262\320\260", nullptr));
        label_10->setText(QCoreApplication::translate("InputWindow", "\321\207", nullptr));
        label_11->setText(QCoreApplication::translate("InputWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217 \321\200\320\260\320\261\320\276\321\202", nullptr));
        label_12->setText(QCoreApplication::translate("InputWindow", "\321\207", nullptr));
        label_14->setText(QCoreApplication::translate("InputWindow", "\320\236\321\201\321\202\320\260\321\202\320\276\321\207\320\275\320\260\321\217 \320\264\320\276\320\267\320\260 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_13->setText(QCoreApplication::translate("InputWindow", "\321\200\320\260\320\264", nullptr));
        label_19->setText(QCoreApplication::translate("InputWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\320\274\320\265\320\275", nullptr));
        label_15->setText(QCoreApplication::translate("InputWindow", "\320\224\320\276\320\273\320\263\320\276\321\202\320\260", nullptr));
        label_18->setText(QCoreApplication::translate("InputWindow", "\302\260", nullptr));
        label_16->setText(QCoreApplication::translate("InputWindow", "\302\260", nullptr));
        label_17->setText(QCoreApplication::translate("InputWindow", "\320\250\320\270\321\200\320\276\321\202\320\260", nullptr));
        groupBox_radiation->setTitle(QCoreApplication::translate("InputWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_20->setText(QCoreApplication::translate("InputWindow", "\320\224\320\276\320\267\320\260 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217 \320\276\321\202\n"
"\320\277\321\200\320\276\321\205\320\276\320\264\321\217\321\211\320\265\320\263\320\276 \320\276\320\261\320\273\320\260\320\272\320\260", nullptr));
        label_21->setText(QCoreApplication::translate("InputWindow", "\321\200\320\260\320\264", nullptr));
        label_22->setText(QCoreApplication::translate("InputWindow", "\320\224\320\276\320\267\320\260 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217 \320\276\321\202\n"
"\320\267\320\260\320\263\321\200\321\217\320\267\320\275\320\265\320\275\320\270\321\217 \320\274\320\265\321\201\321\202\320\275\320\276\321\201\321\202\320\270", nullptr));
        label_23->setText(QCoreApplication::translate("InputWindow", "\321\200\320\260\320\264", nullptr));
        label_24->setText(QCoreApplication::translate("InputWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\276\320\261\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_25->setText(QCoreApplication::translate("InputWindow", "\321\207", nullptr));
        label_26->setText(QCoreApplication::translate("InputWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\321\214 \320\240\320\222 \320\262 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\265\n"
"\320\270\320\275\320\263\320\260\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\276\320\263\320\276 \320\277\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_27->setText(QCoreApplication::translate("InputWindow", "\320\232\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputWindow: public Ui_InputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWINDOW_H
