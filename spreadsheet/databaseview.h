#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlDatabase>
#include "sqlrelationaltablemodel.h"


namespace Ui {
class DatabaseView;
}

class DatabaseView : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseView(QString l = "login", QString p = "pass");

    ~DatabaseView();

//protected:
//    void resizeEvent(QResizeEvent *event) override;



private slots:
    void on_motostyleButton_clicked();

    void on_fmrButton_clicked();

    void on_allButton_clicked();

    void on_addButton_clicked();

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

    void on_lineEdit_returnPressed();

    void recordSelected();

    void on_removeButton_clicked();

    void on_cancelSearchButton_clicked();

    void on_lineEdit_textEdited();

    void on_archiveCheckBox_toggled(bool checked);

    void onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight);

    void onSearch();

    void onRefresh();


    void on_refreshButton_clicked();

    void on_reconnectButton_clicked();

    void on_archiveCheckBox_stateChanged(int arg1);

    void on_noneCheckBox_toggled(bool checked);

    void on_approvedCheckBox_toggled(bool checked);

    void on_epsCheckBox_toggled(bool checked);

    void on_printedCheckBox_toggled(bool checked);

    void on_packagedCheckBox_toggled(bool checked);

    void on_holdCheckBox_toggled(bool checked);

private:

    void reject();
    QString applyFilter();
    QString archiveFilter;

    QString dealerFilter;
    QString noneFilter;
    QString approvedFilter;
    QString epsFilter;
    QString printedFilter;
    QString holdFilter;

    bool filter[12] = {false,true,false,false,true,true,false,true,true,false,false,true};

    Ui::DatabaseView *ui;
    QSqlDatabase db;
    SqlRelationalTableModel *model;

    //QStandardItemModel

};

#endif // DATABASEVIEW_H
