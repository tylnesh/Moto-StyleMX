#ifndef DATABASEWINDOW_H
#define DATABASEWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include "sqlrelationaltablemodel.h"

namespace Ui {
class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DatabaseWindow(QString l = "login", QString p = "pass");

    ~DatabaseWindow();

private slots:
    void on_addButton_clicked();

    void on_allButton_clicked();

    void on_cancelButton_clicked();

    void on_archiveCheckBox_toggled(bool checked);

    void on_cancelSearchButton_clicked();

    void on_fmrButton_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_textEdited();

    void on_motostyleButton_clicked();

    void on_removeButton_clicked();

    void on_saveButton_clicked();

    void recordSelected();

    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

    void on_pushButton_clicked();

private:
    Ui::DatabaseWindow *ui;
    void reject();
    QString dealerFilter;
    QString archiveFilter;
    QSqlDatabase db;
    SqlRelationalTableModel *model;
};

#endif // DATABASEWINDOW_H
