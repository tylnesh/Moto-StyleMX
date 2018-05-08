#ifndef NEWUSERDIALOG_H
#define NEWUSERDIALOG_H

#include <QDialog>
#include <QSqlDatabase>


namespace Ui {
class newUserDialog;
}

class newUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit newUserDialog(QWidget *parent = 0, QString l = "login", QString p = "pass");
    ~newUserDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::newUserDialog *ui;
    QSqlDatabase db;
};

#endif // NEWUSERDIALOG_H
