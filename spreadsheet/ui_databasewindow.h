/********************************************************************************
** Form generated from reading UI file 'databasewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWINDOW_H
#define UI_DATABASEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *allButton;
    QPushButton *motostyleButton;
    QPushButton *fmrButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *archiveCheckBox;
    QLineEdit *lineEdit;
    QPushButton *cancelSearchButton;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *addButton;
    QPushButton *removeButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DatabaseWindow)
    {
        if (DatabaseWindow->objectName().isEmpty())
            DatabaseWindow->setObjectName(QStringLiteral("DatabaseWindow"));
        DatabaseWindow->resize(800, 600);
        centralwidget = new QWidget(DatabaseWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setFocusPolicy(Qt::ClickFocus);
        tableView->setAutoFillBackground(false);
        tableView->setFrameShadow(QFrame::Sunken);
        tableView->setMidLineWidth(0);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableView->setAlternatingRowColors(true);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableView->setSortingEnabled(true);

        horizontalLayout->addWidget(tableView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        allButton = new QPushButton(centralwidget);
        allButton->setObjectName(QStringLiteral("allButton"));
        allButton->setAutoDefault(false);

        verticalLayout_2->addWidget(allButton);

        motostyleButton = new QPushButton(centralwidget);
        motostyleButton->setObjectName(QStringLiteral("motostyleButton"));
        motostyleButton->setAutoDefault(false);

        verticalLayout_2->addWidget(motostyleButton);

        fmrButton = new QPushButton(centralwidget);
        fmrButton->setObjectName(QStringLiteral("fmrButton"));
        fmrButton->setAutoDefault(false);

        verticalLayout_2->addWidget(fmrButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        archiveCheckBox = new QCheckBox(centralwidget);
        archiveCheckBox->setObjectName(QStringLiteral("archiveCheckBox"));

        verticalLayout_2->addWidget(archiveCheckBox);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(lineEdit);

        cancelSearchButton = new QPushButton(centralwidget);
        cancelSearchButton->setObjectName(QStringLiteral("cancelSearchButton"));

        verticalLayout_2->addWidget(cancelSearchButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout_2->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        verticalLayout_2->addWidget(removeButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        verticalLayout_2->addWidget(saveButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        DatabaseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DatabaseWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        DatabaseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DatabaseWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DatabaseWindow->setStatusBar(statusbar);

        retranslateUi(DatabaseWindow);

        allButton->setDefault(true);
        fmrButton->setDefault(false);


        QMetaObject::connectSlotsByName(DatabaseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DatabaseWindow)
    {
        DatabaseWindow->setWindowTitle(QApplication::translate("DatabaseWindow", "MainWindow", Q_NULLPTR));
        allButton->setText(QApplication::translate("DatabaseWindow", "ALL", Q_NULLPTR));
        motostyleButton->setText(QApplication::translate("DatabaseWindow", "Moto-StyleMX", Q_NULLPTR));
        fmrButton->setText(QApplication::translate("DatabaseWindow", "FMR FACTORY", Q_NULLPTR));
        label->setText(QString());
        archiveCheckBox->setText(QApplication::translate("DatabaseWindow", "Archive", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("DatabaseWindow", "Search", Q_NULLPTR));
        cancelSearchButton->setText(QApplication::translate("DatabaseWindow", "CANCEL SEARCH", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DatabaseWindow", "PushButton", Q_NULLPTR));
        addButton->setText(QApplication::translate("DatabaseWindow", "ADD", Q_NULLPTR));
        removeButton->setText(QApplication::translate("DatabaseWindow", "REMOVE", Q_NULLPTR));
        saveButton->setText(QApplication::translate("DatabaseWindow", "SAVE", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DatabaseWindow", "CANCEL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseWindow: public Ui_DatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWINDOW_H
