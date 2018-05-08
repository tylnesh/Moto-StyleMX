#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseview.h"
#include "newuserdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

bool toSave = false;
QString login;
QString pass;
bool loginLoaded = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->newUserButton->setVisible(false);
    ui->label->setPixmap(QPixmap(":/assets/images/motostyleLogo.png"));

    QString filename = "login.txt";
       QFile file(filename);
       if (file.open(QIODevice::ReadOnly)) {
           QTextStream textStream(&file);
           login = textStream.readLine();
           pass = textStream.readLine();
           loginLoaded = true;
       } file.close();

/*if (loginLoaded) {
    qDebug() << "Sending login: " << login << " and password: " << pass;

    dw = new DatabaseView(login,pass);
    dw->setWindowFlags(Qt::Window);
    dw->show();
    hide();
}*/
       if(loginLoaded) {
           ui->loginTextEdit->setText(login);
           ui->passwordTextEdit->setText(pass);
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_motostylemxButton_clicked()
{


    login = ui->loginTextEdit->text().toLower();
    pass = ui->passwordTextEdit->text();

    qDebug() << "Sending login: " << login << " and password: " << pass;

    dw = new DatabaseView(login,pass);
    dw->setWindowFlags(Qt::Window);
    dw->show();

    if (toSave){

        QString filename = "login.txt";
           QFile file(filename);
           if (file.open(QIODevice::ReadWrite)) {
               QTextStream stream(&file);
               stream << login << endl << pass << endl;
           } file.close();

    }

    hide();



    //show();
}

void MainWindow::on_newUserButton_clicked()
{

    login = ui->loginTextEdit->text().toLower();
    pass = ui->passwordTextEdit->text();

    //nw = new newUserDialog(this, login, pass);
    //nw->show();
}

void MainWindow::on_passwordTextEdit_returnPressed()
{
   /* QString login;
    QString pass;
    login = ui->loginTextEdit->text().toLower();
    pass = ui->passwordTextEdit->text();

    qDebug() << "Sending login: " << login << " and password: " << pass;

    dw = new DatabaseView(login,pass);
    dw->setWindowFlags(Qt::Window);
    dw->show();
    hide();*/
    on_motostylemxButton_clicked();
}



void MainWindow::on_rememberCheckBox_toggled(bool checked)
{
  qDebug() << "checkox is " << checked;
  toSave = checked;
}

void MainWindow::on_deleteLoginsButton_clicked()
{
    QString filename = "login.txt";
       QFile file(filename);
        file.remove();
}
