/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionPowerOnAll;
    QAction *actionPowerOffAll;
    QWidget *centralWidget;
    QGroupBox *groupProjectors;
    QCheckBox *select_all;
    QWidget *pjCommands;
    QLabel *app_title;
    QFrame *line_2;
    QPushButton *selection_connect;
    QFrame *line;
    QLabel *label;
    QTextBrowser *textBrowser;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(780, 382);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        actionConnect->setFont(font);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionDisconnect->setFont(font);
        actionPowerOnAll = new QAction(MainWindow);
        actionPowerOnAll->setObjectName(QString::fromUtf8("actionPowerOnAll"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\352\265\264\353\246\274\354\262\264"));
        font1.setPointSize(12);
        actionPowerOnAll->setFont(font1);
        actionPowerOffAll = new QAction(MainWindow);
        actionPowerOffAll->setObjectName(QString::fromUtf8("actionPowerOffAll"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\352\265\264\353\246\274"));
        font2.setPointSize(12);
        actionPowerOffAll->setFont(font2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupProjectors = new QGroupBox(centralWidget);
        groupProjectors->setObjectName(QString::fromUtf8("groupProjectors"));
        groupProjectors->setGeometry(QRect(10, 7, 761, 331));
        select_all = new QCheckBox(groupProjectors);
        select_all->setObjectName(QString::fromUtf8("select_all"));
        select_all->setGeometry(QRect(190, 30, 87, 20));
        pjCommands = new QWidget(groupProjectors);
        pjCommands->setObjectName(QString::fromUtf8("pjCommands"));
        pjCommands->setGeometry(QRect(170, 55, 636, 241));
        app_title = new QLabel(groupProjectors);
        app_title->setObjectName(QString::fromUtf8("app_title"));
        app_title->setGeometry(QRect(5, 25, 161, 16));
        line_2 = new QFrame(groupProjectors);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 40, 166, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        selection_connect = new QPushButton(groupProjectors);
        selection_connect->setObjectName(QString::fromUtf8("selection_connect"));
        selection_connect->setGeometry(QRect(40, 60, 81, 26));
        line = new QFrame(groupProjectors);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(160, 20, 16, 291));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(groupProjectors);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 270, 151, 41));
        textBrowser = new QTextBrowser(groupProjectors);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 100, 151, 151));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionConnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPowerOnAll);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPowerOffAll);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QApplication::translate("MainWindow", "CONNECT ALL", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect All", nullptr));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setText(QApplication::translate("MainWindow", "DISCONNECT ALL", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect All", nullptr));
#endif // QT_NO_TOOLTIP
        actionPowerOnAll->setText(QApplication::translate("MainWindow", "PowerOnAll", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPowerOnAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionPowerOffAll->setText(QApplication::translate("MainWindow", "PowerOffAll", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPowerOffAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        groupProjectors->setTitle(QApplication::translate("MainWindow", "PROJECTORS", nullptr));
        select_all->setText(QApplication::translate("MainWindow", "Select All", nullptr));
        app_title->setText(QApplication::translate("MainWindow", "For selection :", nullptr));
        selection_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        label->setText(QApplication::translate("MainWindow", "HULIAC c", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">&lt;\354\202\254\354\232\251\353\262\225&gt;</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. \354\227\260\352\262\260\355\225\240 \355\224\204\353\241\234\354\240\235\355\204\260\353\245\274 \354\262\264\355\201\254\355\225\230\352\263\240 Connect \353\262\204\355\212\274\354\235\204 \353\210"
                        "\204\353\245\270\353\213\244. (\354\235\264\353\257\270 \354\264\210\353\241\235\353\266\210\354\235\264\353\251\264 \353\260\224\353\241\234 3\353\262\210\354\234\274\353\241\234)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. \354\264\210\353\241\235\353\266\210\354\235\264 \353\223\244\354\226\264\354\230\244\353\251\264 \354\273\264\355\223\250\355\204\260\354\231\200 \355\224\204\353\241\234\354\240\235\355\204\260\352\260\200 \354\227\260\352\262\260\353\220\234 \352\262\203\354\235\264\353\213\244.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\">3. Power on/off \353\262\204\355\212\274\354\235\204 \353\210\204\353\245\270\353\213\244.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. Successfully sent\352\260\200 \353\202\230\354\230\244\353\251\264 \354\204\261\352\263\265. \355\224\204\353\241\234\354\240\235\355\204\260\352\260\200 \353\252\205\353\240\271\354\235\204 \354\210\230\355\226\211\355\225\240\353\225\214\352\271\214\354\247\200 \352\270\260\353\213\244\353\246\254\354\236\220.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">+) Fail to send"
                        ". Push the button later\353\212\224 \355\224\204\353\241\234\354\240\235\355\204\260\352\260\200 \353\252\205\353\240\271\354\235\204 \354\210\230\355\226\211\355\225\230\354\247\200 \353\252\273 \355\225\230\353\212\224 \354\203\201\355\203\234\354\235\264\353\257\200\353\241\234 \352\270\260\353\213\244\353\240\270\353\213\244 \353\213\244\354\213\234 \353\210\204\353\245\270\353\213\244.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">+) \354\235\264 \355\224\204\353\241\234\352\267\270\353\236\250\354\235\200 \355\217\264\353\215\224 \353\202\264\354\227\220 \354\236\210\353\212\224 pj_time.txt \353\251\224\353\252\250\354\236\245 \355\214\214\354\235\274\354\227\220 \354\240\201\355\236\214 \354\213\234\352\260\204\354\235\264 \355\235\220\353\245\270 \355\233\204, \353"
                        "\252\250\353\223\240 \355\224\204\353\241\234\354\240\235\355\204\260\353\245\274 Power off\355\225\230\352\263\240 \355\230\204\354\236\254 \354\273\264\355\223\250\355\204\260\353\217\204 \354\242\205\353\243\214\354\213\234\355\202\250\353\213\244. \354\230\210\353\245\274 \353\223\244\354\226\264 pj_time \353\251\224\353\252\250\354\236\245\354\227\220 10:11:12\353\235\274\352\263\240 \354\240\201\355\230\200\354\236\210\354\234\274\353\251\264 10\354\213\234\352\260\204 11\353\266\204 12\354\264\210 \354\235\264\355\233\204\354\227\220 \354\242\205\353\243\214\355\225\230\353\212\224 \352\262\203\354\235\264\353\213\244.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0p"
                        "x; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\353\254\270\354\235\230\354\202\254\355\225\255 : 010-7110-4235</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\352\271\200\353\214\200\355\230\270 \354\202\254\354\233\220</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
