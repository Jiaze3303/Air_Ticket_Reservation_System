/********************************************************************************
** Form generated from reading UI file 'find_ticket.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_TICKET_H
#define UI_FIND_TICKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Find_Ticket
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label;

    void setupUi(QWidget *Find_Ticket)
    {
        if (Find_Ticket->objectName().isEmpty())
            Find_Ticket->setObjectName(QString::fromUtf8("Find_Ticket"));
        Find_Ticket->resize(348, 418);
        Find_Ticket->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(Find_Ticket);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 350, 71, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height: 30px;\n"
"width: 80px;\n"
"background-color: #2789EE;border:none;color:rgb(255, 255, 255);font:16px Microsoft YaHei;}\n"
"QPushButton:pressed{background-color: rgb(38, 195, 238);border:none;color:rgb(255, 255, 255);font:16px Microsoft YaHei;}"));
        lineEdit = new QLineEdit(Find_Ticket);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 100, 261, 41));
        QFont font;
        font.setFamily(QString::fromUtf8(".PingFang HK"));
        font.setPointSize(12);
        lineEdit->setFont(font);
        pushButton_2 = new QPushButton(Find_Ticket);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 350, 71, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"height: 30px;\n"
"width: 80px;\n"
"background-color: #2789EE;border:none;color:rgb(255, 255, 255);font:16px Microsoft YaHei;}\n"
"QPushButton:pressed{background-color: rgb(38, 195, 238);border:none;color:rgb(255, 255, 255);font:16px Microsoft YaHei;}"));
        label_10 = new QLabel(Find_Ticket);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 10, 10, 30));
        label_10->setStyleSheet(QString::fromUtf8("background-color: #2789EE;"));
        label_9 = new QLabel(Find_Ticket);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 10, 121, 30));
        label_9->setStyleSheet(QString::fromUtf8("font: 20px \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0\357\274\2140\357\274\2140);"));
        label = new QLabel(Find_Ticket);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 54, 12));

        retranslateUi(Find_Ticket);

        QMetaObject::connectSlotsByName(Find_Ticket);
    } // setupUi

    void retranslateUi(QWidget *Find_Ticket)
    {
        Find_Ticket->setWindowTitle(QApplication::translate("Find_Ticket", "Form", nullptr));
        pushButton->setText(QApplication::translate("Find_Ticket", "\346\237\245\350\257\242\346\234\272\347\245\250", nullptr));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QString());
        pushButton_2->setText(QApplication::translate("Find_Ticket", "\350\277\224\345\233\236", nullptr));
        label_10->setText(QString());
        label_9->setText(QApplication::translate("Find_Ticket", "\346\234\272\347\245\250\346\237\245\350\257\242", nullptr));
        label->setText(QApplication::translate("Find_Ticket", "\350\272\253\344\273\275\350\257\201\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Find_Ticket: public Ui_Find_Ticket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_TICKET_H
