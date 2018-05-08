#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseview.h"
#include "newuserdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_motostylemxButton_clicked();

    void on_newUserButton_clicked();

    void on_passwordTextEdit_returnPressed();

    void on_rememberCheckBox_toggled(bool checked);

    void on_deleteLoginsButton_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseView *dw;
    newUserDialog *nw;
};

#endif // MAINWINDOW_H
