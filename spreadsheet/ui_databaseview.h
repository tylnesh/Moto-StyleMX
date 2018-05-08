/********************************************************************************
** Form generated from reading UI file 'databaseview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEVIEW_H
#define UI_DATABASEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DatabaseView
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *refreshButton;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *allButton;
    QPushButton *motostyleButton;
    QPushButton *fmrButton;
    QSpacerItem *verticalSpacer_2;
    QCheckBox *noneCheckBox;
    QCheckBox *approvedCheckBox;
    QCheckBox *epsCheckBox;
    QCheckBox *printedCheckBox;
    QCheckBox *packagedCheckBox;
    QCheckBox *holdCheckBox;
    QSpacerItem *verticalSpacer_6;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *archiveCheckBox;
    QLineEdit *lineEdit;
    QPushButton *cancelSearchButton;
    QSpacerItem *verticalSpacer;
    QPushButton *removeButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *saveButton;
    QPushButton *reconnectButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *DatabaseView)
    {
        if (DatabaseView->objectName().isEmpty())
            DatabaseView->setObjectName(QStringLiteral("DatabaseView"));
        DatabaseView->resize(1280, 800);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DatabaseView->sizePolicy().hasHeightForWidth());
        DatabaseView->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(DatabaseView);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        tableView = new QTableView(DatabaseView);
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
        refreshButton = new QPushButton(DatabaseView);
        refreshButton->setObjectName(QStringLiteral("refreshButton"));

        verticalLayout_2->addWidget(refreshButton);

        addButton = new QPushButton(DatabaseView);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout_2->addWidget(addButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        allButton = new QPushButton(DatabaseView);
        allButton->setObjectName(QStringLiteral("allButton"));
        allButton->setAutoDefault(false);

        verticalLayout_2->addWidget(allButton);

        motostyleButton = new QPushButton(DatabaseView);
        motostyleButton->setObjectName(QStringLiteral("motostyleButton"));
        motostyleButton->setAutoDefault(false);

        verticalLayout_2->addWidget(motostyleButton);

        fmrButton = new QPushButton(DatabaseView);
        fmrButton->setObjectName(QStringLiteral("fmrButton"));
        fmrButton->setAutoDefault(false);

        verticalLayout_2->addWidget(fmrButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        noneCheckBox = new QCheckBox(DatabaseView);
        noneCheckBox->setObjectName(QStringLiteral("noneCheckBox"));
        noneCheckBox->setChecked(true);

        verticalLayout_2->addWidget(noneCheckBox);

        approvedCheckBox = new QCheckBox(DatabaseView);
        approvedCheckBox->setObjectName(QStringLiteral("approvedCheckBox"));
        approvedCheckBox->setChecked(true);

        verticalLayout_2->addWidget(approvedCheckBox);

        epsCheckBox = new QCheckBox(DatabaseView);
        epsCheckBox->setObjectName(QStringLiteral("epsCheckBox"));
        epsCheckBox->setChecked(true);

        verticalLayout_2->addWidget(epsCheckBox);

        printedCheckBox = new QCheckBox(DatabaseView);
        printedCheckBox->setObjectName(QStringLiteral("printedCheckBox"));
        printedCheckBox->setChecked(true);

        verticalLayout_2->addWidget(printedCheckBox);

        packagedCheckBox = new QCheckBox(DatabaseView);
        packagedCheckBox->setObjectName(QStringLiteral("packagedCheckBox"));
        packagedCheckBox->setChecked(true);

        verticalLayout_2->addWidget(packagedCheckBox);

        holdCheckBox = new QCheckBox(DatabaseView);
        holdCheckBox->setObjectName(QStringLiteral("holdCheckBox"));
        holdCheckBox->setChecked(true);

        verticalLayout_2->addWidget(holdCheckBox);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        label = new QLabel(DatabaseView);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        archiveCheckBox = new QCheckBox(DatabaseView);
        archiveCheckBox->setObjectName(QStringLiteral("archiveCheckBox"));

        verticalLayout_2->addWidget(archiveCheckBox);

        lineEdit = new QLineEdit(DatabaseView);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setClearButtonEnabled(false);

        verticalLayout_2->addWidget(lineEdit);

        cancelSearchButton = new QPushButton(DatabaseView);
        cancelSearchButton->setObjectName(QStringLiteral("cancelSearchButton"));

        verticalLayout_2->addWidget(cancelSearchButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        removeButton = new QPushButton(DatabaseView);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        verticalLayout_2->addWidget(removeButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        saveButton = new QPushButton(DatabaseView);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        verticalLayout_2->addWidget(saveButton);

        reconnectButton = new QPushButton(DatabaseView);
        reconnectButton->setObjectName(QStringLiteral("reconnectButton"));

        verticalLayout_2->addWidget(reconnectButton);

        cancelButton = new QPushButton(DatabaseView);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout_2->addWidget(cancelButton);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DatabaseView);

        refreshButton->setDefault(true);
        allButton->setDefault(true);
        fmrButton->setDefault(false);


        QMetaObject::connectSlotsByName(DatabaseView);
    } // setupUi

    void retranslateUi(QDialog *DatabaseView)
    {
        DatabaseView->setWindowTitle(QApplication::translate("DatabaseView", "Moto-StyleMX Database", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        refreshButton->setToolTip(QApplication::translate("DatabaseView", "<html><head/><body><p>F5 or CTRL + R</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        refreshButton->setText(QApplication::translate("DatabaseView", "Refresh", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QApplication::translate("DatabaseView", "<html><head/><body><p>Insert</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("DatabaseView", "ADD", Q_NULLPTR));
        allButton->setText(QApplication::translate("DatabaseView", "ALL", Q_NULLPTR));
        motostyleButton->setText(QApplication::translate("DatabaseView", "Moto-StyleMX", Q_NULLPTR));
        fmrButton->setText(QApplication::translate("DatabaseView", "FMR FACTORY", Q_NULLPTR));
        noneCheckBox->setText(QApplication::translate("DatabaseView", "None", Q_NULLPTR));
        approvedCheckBox->setText(QApplication::translate("DatabaseView", "Approved", Q_NULLPTR));
        epsCheckBox->setText(QApplication::translate("DatabaseView", "EPS done", Q_NULLPTR));
        printedCheckBox->setText(QApplication::translate("DatabaseView", "Printed", Q_NULLPTR));
        packagedCheckBox->setText(QApplication::translate("DatabaseView", "Packaged", Q_NULLPTR));
        holdCheckBox->setText(QApplication::translate("DatabaseView", "Hold", Q_NULLPTR));
        label->setText(QString());
        archiveCheckBox->setText(QApplication::translate("DatabaseView", "Archive", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("DatabaseView", "Search", Q_NULLPTR));
        cancelSearchButton->setText(QApplication::translate("DatabaseView", "CANCEL SEARCH", Q_NULLPTR));
        removeButton->setText(QApplication::translate("DatabaseView", "REMOVE", Q_NULLPTR));
        saveButton->setText(QApplication::translate("DatabaseView", "SAVE", Q_NULLPTR));
        reconnectButton->setText(QApplication::translate("DatabaseView", "RECONNECT", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("DatabaseView", "CANCEL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DatabaseView: public Ui_DatabaseView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEVIEW_H
