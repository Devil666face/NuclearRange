/********************************************************************************
** Form generated from reading UI file 'resultwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTWINDOW_H
#define UI_RESULTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_ResultWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QCustomPlot *graph;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_zone;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_rad_D;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ResultWindow)
    {
        if (ResultWindow->objectName().isEmpty())
            ResultWindow->setObjectName(QString::fromUtf8("ResultWindow"));
        ResultWindow->resize(1433, 542);
        centralwidget = new QWidget(ResultWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graph = new QCustomPlot(frame);
        graph->setObjectName(QString::fromUtf8("graph"));

        verticalLayout->addWidget(graph);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(365, 16777215));
        frame_2->setFrameShape(QFrame::WinPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_zone = new QTableWidget(groupBox);
        tableWidget_zone->setObjectName(QString::fromUtf8("tableWidget_zone"));
        tableWidget_zone->setFrameShape(QFrame::StyledPanel);
        tableWidget_zone->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(tableWidget_zone);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox_rad_D = new QDoubleSpinBox(frame_2);
        doubleSpinBox_rad_D->setObjectName(QString::fromUtf8("doubleSpinBox_rad_D"));
        doubleSpinBox_rad_D->setEnabled(false);
        doubleSpinBox_rad_D->setReadOnly(false);
        doubleSpinBox_rad_D->setDecimals(1);
        doubleSpinBox_rad_D->setMaximum(10000000.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_rad_D);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(frame_2);

        ResultWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ResultWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1433, 26));
        ResultWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ResultWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ResultWindow->setStatusBar(statusbar);

        retranslateUi(ResultWindow);

        QMetaObject::connectSlotsByName(ResultWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ResultWindow)
    {
        ResultWindow->setWindowTitle(QCoreApplication::translate("ResultWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\270\321\200\321\203\321\216\321\211\320\270\320\265 \320\277\320\276\321\202\320\265\321\200\320\270 \320\273/\321\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ResultWindow", "\320\240\320\260\320\267\320\274\320\265\321\200\321\213 \320\267\320\276\320\275 \320\277\320\276\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("ResultWindow", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\275\320\276\320\265 \320\276\320\261\320\273\321\203\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("ResultWindow", "\321\200\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResultWindow: public Ui_ResultWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTWINDOW_H
