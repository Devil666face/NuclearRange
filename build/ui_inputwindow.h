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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_pane;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_blast;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_type;
    QLabel *label_2;
    QComboBox *comboBox_q;
    QLabel *label_3;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_lon;
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_lat;
    QLabel *label_8;
    QGridLayout *lay_coor;
    QGroupBox *groupBox_weather;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_weater;
    QGroupBox *groupBox_radiation;
    QGroupBox *groupBox_people;
    QGridLayout *lay_enter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *InputWindow)
    {
        if (InputWindow->objectName().isEmpty())
            InputWindow->setObjectName(QString::fromUtf8("InputWindow"));
        InputWindow->resize(947, 473);
        centralwidget = new QWidget(InputWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_pane = new QFrame(centralwidget);
        frame_pane->setObjectName(QString::fromUtf8("frame_pane"));
        frame_pane->setFrameShape(QFrame::WinPanel);
        frame_pane->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frame_pane);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_blast = new QGroupBox(frame_pane);
        groupBox_blast->setObjectName(QString::fromUtf8("groupBox_blast"));
        verticalLayout_3 = new QVBoxLayout(groupBox_blast);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox_blast);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_type = new QComboBox(groupBox_blast);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        gridLayout->addWidget(comboBox_type, 0, 1, 1, 2);

        label_2 = new QLabel(groupBox_blast);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

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

        gridLayout->addWidget(comboBox_q, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_blast);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_blast);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(groupBox_blast);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setWrapping(false);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        gridLayout->addWidget(dateTimeEdit, 2, 1, 1, 2);

        label_5 = new QLabel(groupBox_blast);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        doubleSpinBox_lon = new QDoubleSpinBox(groupBox_blast);
        doubleSpinBox_lon->setObjectName(QString::fromUtf8("doubleSpinBox_lon"));
        doubleSpinBox_lon->setEnabled(false);
        doubleSpinBox_lon->setReadOnly(true);
        doubleSpinBox_lon->setMinimum(-360.000000000000000);
        doubleSpinBox_lon->setMaximum(360.000000000000000);
        doubleSpinBox_lon->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_lon, 3, 1, 1, 1);

        label_7 = new QLabel(groupBox_blast);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        label_6 = new QLabel(groupBox_blast);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        doubleSpinBox_lat = new QDoubleSpinBox(groupBox_blast);
        doubleSpinBox_lat->setObjectName(QString::fromUtf8("doubleSpinBox_lat"));
        doubleSpinBox_lat->setEnabled(false);
        doubleSpinBox_lat->setReadOnly(false);
        doubleSpinBox_lat->setMinimum(-360.000000000000000);
        doubleSpinBox_lat->setMaximum(360.000000000000000);
        doubleSpinBox_lat->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_lat, 4, 1, 1, 1);

        label_8 = new QLabel(groupBox_blast);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        lay_coor = new QGridLayout();
        lay_coor->setObjectName(QString::fromUtf8("lay_coor"));

        verticalLayout_3->addLayout(lay_coor);


        gridLayout_2->addWidget(groupBox_blast, 0, 0, 1, 1);

        groupBox_weather = new QGroupBox(frame_pane);
        groupBox_weather->setObjectName(QString::fromUtf8("groupBox_weather"));
        verticalLayout = new QVBoxLayout(groupBox_weather);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_weater = new QTableWidget(groupBox_weather);
        tableWidget_weater->setObjectName(QString::fromUtf8("tableWidget_weater"));

        verticalLayout->addWidget(tableWidget_weater);


        gridLayout_2->addWidget(groupBox_weather, 0, 1, 1, 1);

        groupBox_radiation = new QGroupBox(frame_pane);
        groupBox_radiation->setObjectName(QString::fromUtf8("groupBox_radiation"));

        gridLayout_2->addWidget(groupBox_radiation, 1, 0, 1, 1);

        groupBox_people = new QGroupBox(frame_pane);
        groupBox_people->setObjectName(QString::fromUtf8("groupBox_people"));

        gridLayout_2->addWidget(groupBox_people, 1, 1, 1, 1);


        verticalLayout_2->addWidget(frame_pane);

        lay_enter = new QGridLayout();
        lay_enter->setObjectName(QString::fromUtf8("lay_enter"));

        verticalLayout_2->addLayout(lay_enter);

        InputWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(InputWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 947, 26));
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
        groupBox_radiation->setTitle(QCoreApplication::translate("InputWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\270\320\267\320\273\321\203\321\207\320\265\320\275\320\270\321\217", nullptr));
        groupBox_people->setTitle(QCoreApplication::translate("InputWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\273/\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputWindow: public Ui_InputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWINDOW_H
