/********************************************************************************
** Form generated from reading UI file 'info_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFO_DIALOG_H
#define UI_INFO_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_info_dialog
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *info_dialog)
    {
        if (info_dialog->objectName().isEmpty())
            info_dialog->setObjectName("info_dialog");
        info_dialog->resize(463, 379);
        label = new QLabel(info_dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 431, 161));
        textBrowser = new QTextBrowser(info_dialog);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 200, 441, 171));

        retranslateUi(info_dialog);

        QMetaObject::connectSlotsByName(info_dialog);
    } // setupUi

    void retranslateUi(QDialog *info_dialog)
    {
        info_dialog->setWindowTitle(QCoreApplication::translate("info_dialog", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class info_dialog: public Ui_info_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFO_DIALOG_H
