/********************************************************************************
** Form generated from reading UI file 'pjwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PJWIDGET_H
#define UI_PJWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pjWidget
{
public:
    QCheckBox *selector;
    QPushButton *off;
    QLabel *online_icon;
    QPushButton *on;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QWidget *pjWidget)
    {
        if (pjWidget->objectName().isEmpty())
            pjWidget->setObjectName(QString::fromUtf8("pjWidget"));
        pjWidget->resize(588, 26);
        selector = new QCheckBox(pjWidget);
        selector->setObjectName(QString::fromUtf8("selector"));
        selector->setGeometry(QRect(20, 3, 116, 20));
        off = new QPushButton(pjWidget);
        off->setObjectName(QString::fromUtf8("off"));
        off->setGeometry(QRect(542, -3, 31, 32));
        off->setStyleSheet(QString::fromUtf8("background-color:rgb(253, 124, 128);"));
        online_icon = new QLabel(pjWidget);
        online_icon->setObjectName(QString::fromUtf8("online_icon"));
        online_icon->setGeometry(QRect(5, 5, 16, 16));
        online_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/img/ko.png")));
        on = new QPushButton(pjWidget);
        on->setObjectName(QString::fromUtf8("on"));
        on->setGeometry(QRect(510, -3, 31, 32));
        on->setStyleSheet(QString::fromUtf8("background-color:rgb(173, 247, 165);"));
        label = new QLabel(pjWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 4, 291, 16));
        label_3 = new QLabel(pjWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(468, 4, 41, 16));

        retranslateUi(pjWidget);

        QMetaObject::connectSlotsByName(pjWidget);
    } // setupUi

    void retranslateUi(QWidget *pjWidget)
    {
        pjWidget->setWindowTitle(QApplication::translate("pjWidget", "Form", nullptr));
        selector->setText(QApplication::translate("pjWidget", "NAME", nullptr));
        off->setText(QApplication::translate("pjWidget", "OFF", nullptr));
        online_icon->setText(QString());
        on->setText(QApplication::translate("pjWidget", "ON", nullptr));
        label->setText(QApplication::translate("pjWidget", "Disconnected", nullptr));
        label_3->setText(QApplication::translate("pjWidget", "Power", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pjWidget: public Ui_pjWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PJWIDGET_H
