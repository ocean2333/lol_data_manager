/********************************************************************************
** Form generated from reading UI file 'untitled.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QComboBox *comboBox;
    QTextBrowser *textBrowser;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(640, 480);
        comboBox = new QComboBox(Form);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 23, 191, 31));
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(250, 70, 361, 381));
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 85, 113, 25));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(110, 160, 113, 25));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 90, 81, 18));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 160, 81, 18));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Form", "\346\240\271\346\215\256\345\257\271\346\211\213\351\200\211\346\213\251\346\216\250\350\215\220", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Form", "\346\240\271\346\215\256\344\275\240\347\232\204\351\200\211\346\213\251\346\216\250\350\215\220", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Form", "\346\211\223\351\207\216\350\267\257\347\272\277\346\216\250\350\215\220", nullptr));

        label->setText(QCoreApplication::translate("Form", "\350\213\261\351\233\204", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "\344\275\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
