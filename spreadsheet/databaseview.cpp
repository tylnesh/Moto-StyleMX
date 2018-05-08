#include "databaseview.h"
#include "ui_databaseview.h"
#include <QtSql>
#include <QtDebug>
#include <QSql>
#include <QSqlRelationalTableModel>
#include <QMessageBox>
#include "sqlrelationaltablemodel.h"
#include <QShortcut>
#include "relationaltablemodel.cpp"


DatabaseView::DatabaseView(QString l, QString p, QString ip) :
    QDialog(),
    ui(new Ui::DatabaseView)
{
    //myDelegate = new Delegate(this);
    dealerFilter = "";
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL", "spreadsheet");
   // db.setHostName("46.101.232.6");
    db.setHostName("ip");
    db.setDatabaseName("spreadsheet");
    db.setUserName(l);
    db.setPassword(p);
    qDebug() << l;
    qDebug() << p;
    //model = new QSqlRelationalTableModel(this,db);
    model = new SqlRelationalTableModel(this,db);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), this, SLOT(close()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_R), this, SLOT(onRefresh()));
    new QShortcut(QKeySequence(Qt::Key_F5), this, SLOT(onRefresh()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_F), this, SLOT(onSearch()));
    new QShortcut(QKeySequence(Qt::Key_Insert), this, SLOT(on_addButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_F1), this, SLOT(on_allButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_F2), this, SLOT(on_motostyleButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_F3), this, SLOT(on_fmrButton_clicked()));
    if(db.open())
    {
        qDebug() << "Opened";
        //db.close();
        model->setTable("motostylemx");
        //model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        //model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
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
        model->setHeaderData(13,Qt::Horizontal,QObject::tr("Created"));

        //model->setRelation(2, QSqlRelation("city", "id", "name"));
        model->setRelation(model->fieldIndex("dealer"), QSqlRelation("dealers", "id", "name"));
        model->setRelation(model->fieldIndex("printer"), QSqlRelation("printers", "id", "name"));
        model->setRelation(model->fieldIndex("status"), QSqlRelation("statuses", "id", "name"));


        srand(QTime::currentTime().msec());
        int uid = rand();
        auto delegate = new myDelegate(uid);

        archiveFilter = "status != 10";
        model->setFilter(archiveFilter);

        qDebug() << model->rowCount();
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        //ui->tableView->horizontalHeader()
       // ui->tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->tableView->hideColumn(0);
        ui->tableView->hideColumn(12);
        ui->tableView->hideColumn(10);
        //ui->tableView->hideColumn(13);

        QTimer timer;
            QObject::connect(&timer, &QTimer::timeout, [&]() {
                if(! delegate->isEdited() && ! model->isDirty()) {

                    //updating database causing view to reset.
                    //So we need to save and restore selection
                    auto selection = ui->tableView->selectionModel()->selectedIndexes();
                    auto current = ui->tableView->currentIndex();
                    model->select();
                    ui->tableView->setCurrentIndex(current);
                    for(auto s : selection) {
                        ui->tableView->selectionModel()->select(s, QItemSelectionModel::Select);
                    }
                }
            });
            //we will be updating database once every second
            timer.setInterval(1000);
            timer.start();


                QObject::connect(ui->saveButton, &QPushButton::clicked, [&]() {
                    //on submit we need to clear locked and lockedby fields
                    QSqlQuery query(QString("UPDATE motostylemx SET isLocked=%2, user=%3 WHERE user=%1").
                                    arg(uid).
                                    arg('0').
                                    arg('0'));
                    query.exec();
                    model->submitAll();
                });




        ui->removeButton->setVisible(false);
        //ui->tableView->setItemDelegate(delegate);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

        //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->tableView->resizeColumnsToContents();
        ui->tableView->setColumnWidth(3,160);
        ui->tableView->setColumnWidth(11,100);
        ui->saveButton->setVisible(false);
        ui->cancelButton->setVisible(false);


        ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
        ui->tableView->setWindowTitle("Moto-StyleMX Spreadsheet");
        ui->label->setPixmap(QPixmap(":/assets/images/motofmr.png"));
        ui->tableView->show();
        connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(recordSelected()));
        connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));
        //connect(ui->lineEdit, SIGNAL (textChanged(QString)), model, SLOT (filter(QString)));
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
                 QCoreApplication::quit();
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
                     QDialog::reject();
                   }

        }
    }

    //model->setFilter("");




}
}

DatabaseView::~DatabaseView()
{
    this->db.close();
    //&parent->show();
    delete ui;
}

void DatabaseView::on_motostyleButton_clicked()
{
    dealerFilter = "1";
    model->setFilter(QString("dealer LIKE '%%1%'").arg(dealerFilter) + " AND " + archiveFilter + DatabaseView::applyFilter());
    DatabaseView::on_lineEdit_textEdited();
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
    ui->label->setPixmap(QPixmap(":/assets/images/moto.png"));
}

void DatabaseView::on_fmrButton_clicked()
{
    dealerFilter = "2";
    model->setFilter(QString("dealer LIKE '%%1%'").arg(dealerFilter) + " AND " + archiveFilter + DatabaseView::applyFilter());
    DatabaseView::on_lineEdit_textEdited();
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
ui->label->setPixmap(QPixmap(":/assets/images/fmr.png"));
}

void DatabaseView::on_allButton_clicked()
{

 dealerFilter = "";
 DatabaseView::on_lineEdit_textEdited();
 //model->setFilter("");
 ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
 ui->label->setPixmap(QPixmap(":/assets/images/motofmr.png"));

}



void DatabaseView::on_addButton_clicked()
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
         if (dealerFilter == "") qry.bindValue(":dealer",1); else qry.bindValue(":dealer",dealerFilter.toInt());
         qry.bindValue(":isLocked",0);
         //qry.bindValue(":created","");

         if( !qry.exec() )
             qDebug() << qry.lastError().text();
         else
             qDebug( "Inserted!" );


         archiveFilter = "status != 10";
         DatabaseView::on_lineEdit_textEdited();

}

void DatabaseView::on_saveButton_clicked()
{
    qDebug() << "Submit status: " << model->QSqlRelationalTableModel::submitAll();
    qDebug() << model->lastError().text();

}

void DatabaseView::reject(){

   /* QMessageBox::StandardButton resBtn = QMessageBox::Yes;

           resBtn = QMessageBox::question( this, "Moto-StyleMX Spreadsheet",
                                           tr("Are you sure?\n"),
                                           QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                           QMessageBox::Yes);

       if (resBtn == QMessageBox::Yes) {
           db.close();
           qDebug() << db.isOpen();
           QDialog::reject();
       }
       */

       db.close();
       qDebug() << db.isOpen();
       QDialog::reject();

}

void DatabaseView::on_cancelButton_clicked()
{
    model->QSqlRelationalTableModel::revertAll();
}

void DatabaseView::on_lineEdit_returnPressed()
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



void DatabaseView::recordSelected()
{
   QModelIndex index = ui->tableView->currentIndex();
   QSqlRecord record;
   int i = index.row(); // now you know which record was selected
   record = model->record(i);
   model->setData(model->index(index.row(), index.column()), QColor(Qt::red), Qt::ForegroundRole);
   qDebug() << "Current record selected is: " << i;

}


void DatabaseView::on_removeButton_clicked()
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



void DatabaseView::on_cancelSearchButton_clicked()
{
    model->setFilter("");
    ui->lineEdit->setText("");
    ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);

    if(!ui->archiveCheckBox->isChecked())
    {
        qDebug() << "the box is unchecked";
    }
}

void DatabaseView::on_lineEdit_textEdited()
{
    QString str = ui->lineEdit->text();
     qDebug() << "Searching for: " << str;

     if (str == "") {
         model->setFilter((QString("dealer like '%%1%'").arg(dealerFilter)) + " AND " + archiveFilter + DatabaseView::applyFilter());
         ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
     }


    else {

         qDebug() << "Dealer Filter: " << dealerFilter;
         model->setFilter((QString("(design like '%%1%'").arg(str))
                          + " OR " + (QString("notes like '%%1%'").arg(str))
                          + " OR " + (QString("ebay like '%%1%'").arg(str))
                          + " OR " + (QString("orderNum like '%%1%'").arg(str))
                          + ") AND " + (QString("dealer like '%%1%'").arg(dealerFilter))
                          + " AND " + archiveFilter + DatabaseView::applyFilter());
     }
}

void DatabaseView::on_archiveCheckBox_toggled(bool checked)
{
if (ui->archiveCheckBox->isChecked()) {

    archiveFilter = "status = 10";
    //for (int i = 0; i<12; i++) filter[i] = false;
    //filter[10] = true;
    filter[1] = false;
    filter[4] = false;
    filter[5] = false;
    filter[7] = false;
    filter[8] = false;
    filter[11] = false;

    ui->noneCheckBox->setChecked(false);
     ui->approvedCheckBox->setChecked(false);
      ui->epsCheckBox->setChecked(false);
       ui->printedCheckBox->setChecked(false);
        ui->packagedCheckBox->setChecked(false);
         ui->holdCheckBox->setChecked(false);

    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
}
else {

    archiveFilter = "status != 10";
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
}
}


void DatabaseView::onDataChanged(const QModelIndex& topLeft, const QModelIndex& bottomRight)
{
    //qDebug() << "the cell in" << topLeft.row() <<  " row has changed";


    QVariant value = ui->tableView->model()->data(topLeft,0);

    value = ui->tableView->model()->data(bottomRight,1);


    //QModelIndex index = model->index(topLeft.row(), 0, QModelIndex());

    //qDebug() << index.data(0).toInt();






}

void DatabaseView::on_refreshButton_clicked()
{
    DatabaseView::on_lineEdit_textEdited();
    QSqlQuery qry(db);

    qry.prepare("UPDATE motostylemx SET notes = REPLACE(REPLACE(notes, '\r', '\, '), '\n', ' ')");
    qry.exec();
}


void DatabaseView::onRefresh(){
    DatabaseView::on_lineEdit_textEdited();
}
void DatabaseView::onSearch(){

    ui->lineEdit->setFocus();
}

//void DatabaseView::resizeEvent(QResizeEvent *event) {

////   // if (QDialog::isMaximized()) ui->tableView->setColumnWidth(7, this->width()/2);
////  //  else ui->tableView->setColumnWidth(7,this->width()/10);
////  //  ui->tableView->setColumnWidth(1, this->width()/3);
////    //ui->tableView->setColumnWidth(2, this->width()/3);

////    //QDialog::resizeEvent(event);

////    if(event->type() == QEvent::WindowStateChange) {

////            if(isMaximized()) {

////    ui->tableView->setColumnWidth(7, this->width()/2);

////            } else {

////                ui->tableView->setColumnWidth(7, this->width()/10);
////                   //ui->tableView->setColumnWidth(2, this->width()/3);

////            }
////        }

////        event->accept();


//    if( event->type() == QEvent::WindowStateChange )
//       {
//           QWindowStateChangeEvent* event = static_cast< QWindowStateChangeEvent* >( event );

//           if( event->oldState() & Qt::WindowMinimized )
//           {
//               ui->tableView->setColumnWidth(7, this->width()/10);
//               // qDebug() << "Window restored (to normal or maximized state)!";
//           }
//           else if( event->oldState() == Qt::WindowNoState && this->windowState() == Qt::WindowMaximized )
//           {
//                ui->tableView->setColumnWidth(7, this->width()/2);
//               //qDebug() << "Window Maximized!";
//           }
//       }
//    }




void DatabaseView::on_reconnectButton_clicked()
{
    if(db.open())
    {
        qDebug() << "Opened";
        //db.close();
        model->setTable("motostylemx");
        //model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
        model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
        //model->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
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
        model->setHeaderData(13,Qt::Horizontal,QObject::tr("Created"));

        //model->setRelation(2, QSqlRelation("city", "id", "name"));
        model->setRelation(model->fieldIndex("dealer"), QSqlRelation("dealers", "id", "name"));
        model->setRelation(model->fieldIndex("printer"), QSqlRelation("printers", "id", "name"));
        model->setRelation(model->fieldIndex("status"), QSqlRelation("statuses", "id", "name"));


        srand(QTime::currentTime().msec());
        int uid = rand();
        auto delegate = new myDelegate(uid);

        archiveFilter = "status != 10";
        model->setFilter(archiveFilter);
        model->setFilter(DatabaseView::applyFilter());

        qDebug() << model->rowCount();
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        //ui->tableView->horizontalHeader()
       // ui->tableView->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch );
        ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        ui->tableView->hideColumn(0);
        ui->tableView->hideColumn(12);
        ui->tableView->hideColumn(10);
        //ui->tableView->hideColumn(13);

        QTimer timer;
            QObject::connect(&timer, &QTimer::timeout, [&]() {
                if(! delegate->isEdited() && ! model->isDirty()) {

                    //updating database causing view to reset.
                    //So we need to save and restore selection
                    auto selection = ui->tableView->selectionModel()->selectedIndexes();
                    auto current = ui->tableView->currentIndex();
                    model->select();
                    ui->tableView->setCurrentIndex(current);
                    for(auto s : selection) {
                        ui->tableView->selectionModel()->select(s, QItemSelectionModel::Select);
                    }
                }
            });
            //we will be updating database once every second
            timer.setInterval(1000);
            timer.start();


                QObject::connect(ui->saveButton, &QPushButton::clicked, [&]() {
                    //on submit we need to clear locked and lockedby fields
                    QSqlQuery query(QString("UPDATE motostylemx SET isLocked=%2, user=%3 WHERE user=%1").
                                    arg(uid).
                                    arg('0').
                                    arg('0'));
                    query.exec();
                    model->submitAll();
                });




        ui->removeButton->setVisible(false);
        //ui->tableView->setItemDelegate(delegate);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));

        //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        ui->tableView->resizeColumnsToContents();
        ui->tableView->setColumnWidth(3,160);
        ui->tableView->setColumnWidth(11,100);
        ui->saveButton->setVisible(false);
        ui->cancelButton->setVisible(false);


        ui->tableView->sortByColumn(0,Qt::SortOrder::DescendingOrder);
        ui->tableView->setWindowTitle("Moto-StyleMX Spreadsheet");
        ui->label->setPixmap(QPixmap(":/assets/images/motofmr.png"));
        ui->tableView->show();
        connect(ui->tableView, SIGNAL(clicked(const QModelIndex&)), this, SLOT(recordSelected()));
        connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(onDataChanged(const QModelIndex&, const QModelIndex&)));
        //connect(ui->lineEdit, SIGNAL (textChanged(QString)), model, SLOT (filter(QString)));
        }

else
    {
        qDebug() << "Error = " << db.lastError().nativeErrorCode().toInt() << " - " << db.lastError().text();
}
}

void DatabaseView::on_archiveCheckBox_stateChanged(int arg1)
{

}

void DatabaseView::on_noneCheckBox_toggled(bool checked)
{
    if (!(ui->archiveCheckBox->isChecked()))  {
    filter[1] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
    }
}

void DatabaseView::on_approvedCheckBox_toggled(bool checked)
{
    if (!(ui->archiveCheckBox->isChecked()))  {
    filter[4] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
    }
}

void DatabaseView::on_epsCheckBox_toggled(bool checked)
{
    if (!(ui->archiveCheckBox->isChecked()))  {
    filter[5] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
    }
}

void DatabaseView::on_printedCheckBox_toggled(bool checked)
{
    if (!(ui->archiveCheckBox->isChecked()))  {
    filter[7] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
    }
}

void DatabaseView::on_packagedCheckBox_toggled(bool checked)
{
    if (!(ui->archiveCheckBox->isChecked()))  {
    filter[8] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
}

}

void DatabaseView::on_holdCheckBox_toggled(bool checked)
{
    filter[11] = checked;
    DatabaseView::on_lineEdit_textEdited();
    qDebug() << model->filter();
}

QString DatabaseView::applyFilter(){
    int sum = 0;
    QString currentFilter = " AND (";
    for (int i=0;i<12;i++)
        if (filter[i])
        { sum++;
            currentFilter = currentFilter + " status = " + QString::number(i) + " OR";
        }


        currentFilter.chop(3);
        currentFilter = currentFilter + ")";
        if (sum == 0) currentFilter = " OR false";
        qDebug() << currentFilter;
        return currentFilter;



}
