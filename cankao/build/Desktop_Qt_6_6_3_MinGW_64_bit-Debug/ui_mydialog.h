/********************************************************************************
** Form generated from reading UI file 'mydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYDIALOG_H
#define UI_MYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_myDialog
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;

    void setupUi(QDialog *myDialog)
    {
        if (myDialog->objectName().isEmpty())
            myDialog->setObjectName("myDialog");
        myDialog->resize(400, 300);
        myDialog->setMinimumSize(QSize(400, 300));
        myDialog->setMaximumSize(QSize(400, 300));
        textBrowser = new QTextBrowser(myDialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(15, 171, 371, 111));
        label = new QLabel(myDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 360, 140));

        retranslateUi(myDialog);

        QMetaObject::connectSlotsByName(myDialog);
    } // setupUi

    void retranslateUi(QDialog *myDialog)
    {
        myDialog->setWindowTitle(QCoreApplication::translate("myDialog", "Intruduction", nullptr));
        label->setText(QCoreApplication::translate("myDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myDialog: public Ui_myDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYDIALOG_H
