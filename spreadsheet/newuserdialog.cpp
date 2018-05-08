#include "newuserdialog.h"
#include "ui_newuserdialog.h"
#include <QMessageBox>
#include <QDebug>
#include <QtSql>
#include <QtDebug>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QMessageBox>

newUserDialog::newUserDialog(QWidget *parent, QString l, QString p)  :
    QDialog(parent),
    ui(new Ui::newUserDialog)
{
    ui->setupUi(this);

    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL", "spreadsheet");
    db.setHostName("46.101.232.6");
    db.setDatabaseName("spreadsheet");
    db.setUserName(l);
    db.setPassword(p);
    qDebug() << l;
    qDebug() << p;

    if(db.open())
    {
        qDebug() << "Opened";
      }

else
    {
        qDebug() << "Error = " << db.lastError().nativeErrorCode().toInt() << " - " << db.lastError().text();



        if (db.lastError().nativeErrorCode().toInt() == 1045) {

            QMessageBox::StandardButton resBtn = QMessageBox::Ok;

                   resBtn = QMessageBox::information( this, "Moto-StyleMX Spreadsheet",
                                                   tr("Wrong pass or login.\n"),
                                                   QMessageBox::Ok,
                                                   QMessageBox::Ok);

               if (resBtn == QMessageBox::Ok) {
                 QDialog::reject();
               }


        }
    }



}

newUserDialog::~newUserDialog()
{
    delete ui;
}

void newUserDialog::on_buttonBox_accepted()
{
    QString login, pass, pass2;
    login = ui->newLoginEdit->text();
    pass = ui->newPassEdit->text();
    pass2 = ui->repeatPassEdit->text();

    if (pass == pass2)
    {
        QSqlQuery qry(db);
        qry.prepare("CREATE USER 'myuser'@'%' IDENTIFIED BY 'mypass';");
    }


}
