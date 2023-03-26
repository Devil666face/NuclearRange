/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_map;
    QGridLayout *gridLayout;
    QGridLayout *map_lay;
    QFrame *frame_pane;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1116, 593);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_map = new QFrame(centralwidget);
        frame_map->setObjectName(QString::fromUtf8("frame_map"));
        frame_map->setFrameShape(QFrame::WinPanel);
        frame_map->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame_map);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        map_lay = new QGridLayout();
        map_lay->setObjectName(QString::fromUtf8("map_lay"));

        gridLayout->addLayout(map_lay, 0, 0, 1, 1);


        horizontalLayout->addWidget(frame_map);

        frame_pane = new QFrame(centralwidget);
        frame_pane->setObjectName(QString::fromUtf8("frame_pane"));
        frame_pane->setFrameShape(QFrame::WinPanel);
        frame_pane->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_pane);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1116, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\227\320\276\320\275\320\260 \320\277\320\276\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
