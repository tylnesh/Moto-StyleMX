/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *motostylemxButton;
    QLabel *label;
    QLineEdit *loginTextEdit;
    QLineEdit *passwordTextEdit;
    QPushButton *newUserButton;
    QCheckBox *rememberCheckBox;
    QPushButton *deleteLoginsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        motostylemxButton = new QPushButton(centralWidget);
        motostylemxButton->setObjectName(QStringLiteral("motostylemxButton"));
        motostylemxButton->setGeometry(QRect(300, 340, 181, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 651, 211));
        label->setPixmap(QPixmap(QString::fromUtf8("assets/images/motostyleLogo.png")));
        loginTextEdit = new QLineEdit(centralWidget);
        loginTextEdit->setObjectName(QStringLiteral("loginTextEdit"));
        loginTextEdit->setGeometry(QRect(290, 270, 211, 21));
        loginTextEdit->setFocusPolicy(Qt::StrongFocus);
        loginTextEdit->setEchoMode(QLineEdit::Normal);
        passwordTextEdit = new QLineEdit(centralWidget);
        passwordTextEdit->setObjectName(QStringLiteral("passwordTextEdit"));
        passwordTextEdit->setGeometry(QRect(290, 300, 211, 21));
        passwordTextEdit->setEchoMode(QLineEdit::Password);
        newUserButton = new QPushButton(centralWidget);
        newUserButton->setObjectName(QStringLiteral("newUserButton"));
        newUserButton->setGeometry(QRect(679, 510, 111, 21));
        rememberCheckBox = new QCheckBox(centralWidget);
        rememberCheckBox->setObjectName(QStringLiteral("rememberCheckBox"));
        rememberCheckBox->setGeometry(QRect(510, 270, 91, 19));
        deleteLoginsButton = new QPushButton(centralWidget);
        deleteLoginsButton->setObjectName(QStringLiteral("deleteLoginsButton"));
        deleteLoginsButton->setGeometry(QRect(10, 540, 111, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        motostylemxButton->setText(QApplication::translate("MainWindow", "Open Moto-StyleMX spreadsheet", Q_NULLPTR));
        label->setText(QString());
        loginTextEdit->setPlaceholderText(QApplication::translate("MainWindow", "Login", Q_NULLPTR));
        passwordTextEdit->setPlaceholderText(QApplication::translate("MainWindow", "Password", Q_NULLPTR));
        newUserButton->setText(QApplication::translate("MainWindow", "Create new user", Q_NULLPTR));
        rememberCheckBox->setText(QApplication::translate("MainWindow", "Don't log out", Q_NULLPTR));
        deleteLoginsButton->setText(QApplication::translate("MainWindow", "Delete saved logins", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
