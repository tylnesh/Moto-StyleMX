/********************************************************************************
** Form generated from reading UI file 'newuserdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSERDIALOG_H
#define UI_NEWUSERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_newUserDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *newLoginEdit;
    QLineEdit *newPassEdit;
    QLineEdit *repeatPassEdit;

    void setupUi(QDialog *newUserDialog)
    {
        if (newUserDialog->objectName().isEmpty())
            newUserDialog->setObjectName(QStringLiteral("newUserDialog"));
        newUserDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(newUserDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        newLoginEdit = new QLineEdit(newUserDialog);
        newLoginEdit->setObjectName(QStringLiteral("newLoginEdit"));
        newLoginEdit->setGeometry(QRect(40, 20, 113, 21));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(newLoginEdit->sizePolicy().hasHeightForWidth());
        newLoginEdit->setSizePolicy(sizePolicy);
        newPassEdit = new QLineEdit(newUserDialog);
        newPassEdit->setObjectName(QStringLiteral("newPassEdit"));
        newPassEdit->setGeometry(QRect(40, 50, 113, 21));
        newPassEdit->setEchoMode(QLineEdit::Password);
        repeatPassEdit = new QLineEdit(newUserDialog);
        repeatPassEdit->setObjectName(QStringLiteral("repeatPassEdit"));
        repeatPassEdit->setGeometry(QRect(40, 80, 113, 21));
        repeatPassEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(newUserDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newUserDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newUserDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newUserDialog);
    } // setupUi

    void retranslateUi(QDialog *newUserDialog)
    {
        newUserDialog->setWindowTitle(QApplication::translate("newUserDialog", "Dialog", Q_NULLPTR));
        newLoginEdit->setPlaceholderText(QApplication::translate("newUserDialog", "Login", Q_NULLPTR));
        newPassEdit->setPlaceholderText(QApplication::translate("newUserDialog", "Password", Q_NULLPTR));
        repeatPassEdit->setPlaceholderText(QApplication::translate("newUserDialog", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class newUserDialog: public Ui_newUserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSERDIALOG_H
