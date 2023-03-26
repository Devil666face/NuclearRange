/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_theme;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_projection;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(468, 778);
        centralwidget = new QWidget(SettingsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(3);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listWidget_theme = new QListWidget(groupBox);
        listWidget_theme->setObjectName(QString::fromUtf8("listWidget_theme"));
        listWidget_theme->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(listWidget_theme);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 120));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget_projection = new QListWidget(groupBox_2);
        listWidget_projection->setObjectName(QString::fromUtf8("listWidget_projection"));
        listWidget_projection->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(listWidget_projection);


        verticalLayout_3->addWidget(groupBox_2);


        verticalLayout_4->addWidget(frame);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_4->addWidget(pushButton);

        SettingsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 468, 25));
        SettingsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SettingsWindow->setStatusBar(statusbar);

        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\272\320\260\321\200\321\202\321\213", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingsWindow", "\320\241\321\202\320\270\320\273\321\214 \320\272\320\260\321\200\321\202\321\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SettingsWindow", "\320\237\321\200\320\276\320\265\320\272\321\206\320\270\321\217 \320\272\320\260\321\200\321\202\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("SettingsWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
