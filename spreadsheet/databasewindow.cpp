#include "databasewindow.h"
#include "ui_databasewindow.h"
#include <QtSql>
#include <QtDebug>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include "sqlrelationaltablemodel.h"
#include <QDialog>
#include <QMainWindow>


DatabaseWindow::DatabaseWindow(QString l, QString p) :
    QMainWindow(),
    ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);
    dealerFilter = "";
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL", "spreadsheet");
    db.setHostName("46.101.232.6");
    db.setDatabaseName("spreadsheet");
    db.setUserName(l);
    db.setPassword(p);
    qDebug() << l;
    qDebug() << p;
    model = new SqlRelationalTableModel(this,db);

    if(db.open())
    {
        qDebug() << "Opened";
        model->setTable("motostylemx");
        model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        model->select();
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("Design"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("Model"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("Status"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("Printer"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("Ebay"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("Order"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("Notes"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("Payment"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("Last changed"));
        model->setHeaderData(11,Qt::Horizontal,QObject::tr("Dealer"));

        model->setRelation(model->fieldIndex("dealer"), QSqlRelation("dealers", "id", "name"));
        model->setRelation(model->fieldIndex("printer"), QSqlRelation("printers", "id", "name"));
        model->setRelation(model->fieldIndex("status"), QSqlRelation("statuses", "id", "name"));

        archiveFilter = "status != 10";
        model->setFilter(archiveFilter);

        qDebug() << model->rowCount();
        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->tableView->hideColumn(0);
        ui->tableView->hideColumn(12);
        ui->tableView->hideColumn(10);
        ui->tableView->hideColumn(13);

        ui->removeButton->setVisible(false);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
        ui->tableView->resizeColumnsToContents();

        ui->tableView->setColumnWidth(3,160);
        ui->tableView->setColumnWidth(11,100);

        ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
        ui->tableView->setWindowTitle("Moto-StyleMX Spreadsheet");
        ui->label->setPixmap(QPixmap("C:/Users/Mimo/Documents/spreadsheet/assets/images/motofmr.png"));
        ui->tableView->show();
        connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(recordSelected()));
        connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));
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
                 QMainWindow::close();
               }
        }
        else
        {
            if (db.lastError().nativeErrorCode().toInt() == 1045) {
                QMessageBox::StandardButton resBtn = QMessageBox::Ok;
                QString error = "Error = " + db.lastError().nativeErrorCode() + " - " + db.lastError().text();
                       resBtn = QMessageBox::information( this, "Moto-StyleMX Spreadsheet",
                                                       tr(error.toLatin1()),
                                                       QMessageBox::Ok,
                                                       QMessageBox::Ok);
                   if (resBtn == QMessageBox::Ok) {
                     QMainWindow::close();
                   }
        }
    }
}
}

DatabaseWindow::~DatabaseWindow()
{
    this->db.close();
    delete ui;
}

void DatabaseWindow::on_addButton_clicked()
{
    QSqlQuery qry(db);

    qry.prepare("INSERT INTO motostylemx(design,model,status,printer,ebay,orderNum,notes,payment,"
                //"timestamp,"
                "user,dealer,isLocked"
                //",created"
                ")"
                "VALUES(:design,:model,:status,:printer,:ebay,:orderNum,:notes,:payment,"
                //":timestamp,"
                ":user,:dealer,:isLocked"
                //",:created"
                ")");

    qry.bindValue(":design","");
    qry.bindValue(":model","");
    qry.bindValue(":status",1);
    qry.bindValue(":printer",1);
    qry.bindValue(":ebay","");
    qry.bindValue(":orderNum",0);
    qry.bindValue(":notes","");
    qry.bindValue(":payment","");
    //qry.bindValue(":timestamp",NULL);
    qry.bindValue(":user",QString(db.userName()));
    qry.bindValue(":dealer",1);
    qry.bindValue(":isLocked",0);
    //qry.bindValue(":created","");

    if( !qry.exec() )
        qDebug() << qry.lastError().text();
    else
        qDebug( "Inserted!" );

    DatabaseWindow::on_lineEdit_returnPressed();
}

void DatabaseWindow::on_allButton_clicked()
{
    dealerFilter = "";
    DatabaseWindow::on_lineEdit_textEdited();
    //model->setFilter("");
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
    ui->label->setPixmap(QPixmap(":/assets/images/motofmr.png"));

}

void DatabaseWindow::on_cancelButton_clicked()
{
 model->QSqlRelationalTableModel::revertAll();
}

void DatabaseWindow::on_archiveCheckBox_toggled(bool checked)
{
    if (ui->archiveCheckBox->isChecked()) {

        archiveFilter = "status = 10";
        DatabaseWindow::on_lineEdit_textEdited();
    }
    else {
        archiveFilter = "status != 10";
        DatabaseWindow::on_lineEdit_textEdited();
    }
}

void DatabaseWindow::on_cancelSearchButton_clicked()
{
    model->setFilter("");
    ui->lineEdit->setText("");
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);

    if(!ui->archiveCheckBox->isChecked())
    {
        qDebug() << "the box is unchecked";
    }
}

void DatabaseWindow::on_fmrButton_clicked()
{
    dealerFilter = "2";
    model->setFilter(QString("dealer LIKE '%%1%'").arg(dealerFilter) + " AND " + archiveFilter);
    DatabaseWindow::on_lineEdit_textEdited();
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
ui->label->setPixmap(QPixmap(":/assets/images/fmr.png"));
}

void DatabaseWindow::on_lineEdit_returnPressed()
{
    QString str = ui->lineEdit->text();
     qDebug() << "Searching for: " << str;

     if (str == "") {
         model->setFilter("");
         ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
     }


    else {
         //model->setFilter(QString("design LIKE '%%1%'").arg(str));
     }
}

void DatabaseWindow::on_lineEdit_textEdited()
{
    QString str = ui->lineEdit->text();
     qDebug() << "Searching for: " << str;

     if (str == "") {
         model->setFilter((QString("dealer like '%%1%'").arg(dealerFilter)) + " AND " + archiveFilter);
         ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
     }


    else {

         qDebug() << "Dealer Filter: " << dealerFilter;
         model->setFilter((QString("(design like '%%1%'").arg(str))
                          + " OR " + (QString("notes like '%%1%'").arg(str))
                          + " OR " + (QString("ebay like '%%1%'").arg(str))
                          + " OR " + (QString("orderNum like '%%1%'").arg(str))
                          + ") AND " + (QString("dealer like '%%1%'").arg(dealerFilter))
                          + " AND " + archiveFilter);
     }
}

void DatabaseWindow::on_motostyleButton_clicked()
{
    dealerFilter = "1";
    model->setFilter(QString("dealer LIKE '%%1%'").arg(dealerFilter) + " AND " + archiveFilter);
    DatabaseWindow::on_lineEdit_textEdited();
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
    ui->label->setPixmap(QPixmap(":/assets/images/moto.png"));
}

void DatabaseWindow::on_removeButton_clicked()
{
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;

           resBtn = QMessageBox::question( this, "Moto-StyleMX Spreadsheet",
                                           tr("Are you sure you want to delete this row? This operation is not reversible.\n"),
                                           QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                           QMessageBox::Yes);

       if (resBtn == QMessageBox::Yes) {
            model->SqlRelationalTableModel::removeRow(ui->tableView->currentIndex().row());

    QModelIndex index = ui->tableView->currentIndex();

    int i = index.row();
    qDebug()<< "index row: " << i;
       qDebug() << model->SqlRelationalTableModel::setData(model->index(i,4), 10);

       }
}

void DatabaseWindow::on_saveButton_clicked()
{
    qDebug() << "Submit status: " << model->QSqlRelationalTableModel::submitAll();
    qDebug() << model->lastError().text();
}

void DatabaseWindow::reject(){
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;

           resBtn = QMessageBox::question( this, "Moto-StyleMX Spreadsheet",
                                           tr("Are you sure?\n"),
                                           QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                           QMessageBox::Yes);

       if (resBtn == QMessageBox::Yes) {
           db.close();
           qDebug() << db.isOpen();
           QMainWindow::close();
       }
}

void DatabaseWindow::recordSelected()
{
   QModelIndex index = ui->tableView->currentIndex();
   QSqlRecord record;
   int i = index.row(); // now you know which record was selected
   record = model->record(i);
   model->setData(model->index(index.row(), index.column()), QColor(Qt::red), Qt::ForegroundRole);
   qDebug() << "Current record selected is: " << i;
}

void DatabaseWindow::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    //qDebug() << "the cell in" << topLeft.row() <<  " row has changed";


    QVariant value = ui->tableView->model()->data(topLeft,0);

    value = ui->tableView->model()->data(bottomRight,1);


    QModelIndex index = model->index(topLeft.row(), 0, QModelIndex());

    //qDebug() << index.data(0).toInt();






}


void DatabaseWindow::on_pushButton_clicked()
{
    dealerFilter = "1";
    model->setFilter(QString("dealer LIKE '%%1%'").arg(dealerFilter) + " AND " + archiveFilter);
    DatabaseWindow::on_lineEdit_textEdited();
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
    ui->label->setPixmap(QPixmap(":/assets/images/moto.png"));
}
