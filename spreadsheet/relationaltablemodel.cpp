/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtSql>
#include <QDebug>
//#include "connection.h"

class myDelegate: public QSqlRelationalDelegate {
public:
    myDelegate (int uid, QObject * parent = nullptr) :
       QSqlRelationalDelegate(parent), m_uid(uid), m_isEdited(false)
       {
       }

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
        int  id_col = 0;
        auto id_idx = index.model()->index(index.row(), id_col);
        QSqlQuery query(QString("SELECT isLocked, user FROM motostylemx WHERE id=%1").arg(id_idx.data().toString()));
        query.next();
        bool isLocked = query.value(0).toBool();
        int lockedBy = query.value(1).toInt();

        // if it is locked by other user
        if(isLocked && lockedBy != m_uid)
            return nullptr; // do not create editor

        query.exec(QString("UPDATE motostylemx SET isLocked=%2, user=%3 WHERE id=%1").
                         arg(id_idx.data().toString()).
                         arg('1').
                         arg(m_uid));

        // else lock current index
        // and return default editor
        m_isEdited = true;
        return QSqlRelationalDelegate::createEditor(parent, option, index);   
    }

    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const {
        //editor is closed
        m_isEdited = false;
        QSqlRelationalDelegate::setModelData(editor, model, index);
    }

    //used to prevent model update while editor is opened as it will reset the view
    bool isEdited() {
        return m_isEdited;
    }

private:
    // sets to true while editor is active
    mutable bool m_isEdited;
    // current user id
    int m_uid;
};

//void initializeModel(QSqlRelationalTableModel *model)
//{
////! [0]
//    model->setTable("employee");
////! [0]

//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

////! [1]
//    model->setRelation(2, QSqlRelation("city", "id", "name"));
////! [1] //! [2]
//    model->setRelation(3, QSqlRelation("country", "id", "name"));
////! [2]

////! [3]
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
////! [3]

//    model->select();
//}

//QTableView *createView(const QString &title, QSqlTableModel *model)
//{
//    //! [4]
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->setItemDelegate(new QSqlRelationalDelegate(view));
//    //! [4]
//    view->setWindowTitle(title);
//    return view;
//}

//void createRelationalTables()
//{
//    QSqlQuery query;
//    query.exec("create table employee(id int primary key, name varchar(20), city int, country int, locked bool, lockedby int)");
//    query.exec("insert into employee values(1, 'Espen', 5000, 47, 0, 0)");
//    query.exec("insert into employee values(2, 'Harald', 80000, 49, 0, 0)");
//    query.exec("insert into employee values(3, 'Sam', 100, 1, 0, 0)");

//    query.exec("create table city(id int, name varchar(20))");
//    query.exec("insert into city values(100, 'San Jose')");
//    query.exec("insert into city values(5000, 'Oslo')");
//    query.exec("insert into city values(80000, 'Munich')");

//    query.exec("create table country(id int, name varchar(20))");
//    query.exec("insert into country values(1, 'USA')");
//    query.exec("insert into country values(47, 'Norway')");
//    query.exec("insert into country values(49, 'Germany')");
//}

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    if (!createConnection())
//        return 1;

//    //call this once to create and fill tables and comment out later
//    createRelationalTables();

//    srand(QTime::currentTime().msec());
//    int uid = rand();

//    QSqlRelationalTableModel model;


//    initializeModel(&model);

//    QTableView * view = createView(QObject::tr("Relational Table Model"), &model);
//    auto delegate = new myDelegate(uid);
//    view->setItemDelegate(delegate);

//    QTimer timer;
//    //here we update our model if it is clean (not changed or changes are submitted)
//    QObject::connect(&timer, &QTimer::timeout, [&]() {
//        if(! delegate->isEdited() && ! model.isDirty()) {

//            //updating database causing view to reset.
//            //So we need to save and restore selection
//            auto selection = view->selectionModel()->selectedIndexes();
//            auto current = view->currentIndex();
//            model.select();
//            view->setCurrentIndex(current);
//            for(auto s : selection) {
//                view->selectionModel()->select(s, QItemSelectionModel::Select);
//            }
//        }
//    });
//    //we will be updating database once every second
//    timer.setInterval(1000);
//    timer.start();

//    QWidget * window = new QWidget();
//    QHBoxLayout * layout = new QHBoxLayout();
//    QPushButton * submitButton = new QPushButton("Submit");

//    layout->addWidget(view);
//    layout->addWidget(submitButton);
//    window->setLayout(layout);

//    window->show();

//    QObject::connect(submitButton, &QPushButton::clicked, [&]() {
//        //on submit we need to clear locked and lockedby fields
//        QSqlQuery query(QString("UPDATE employee SET locked=%2, lockedby=%3 WHERE lockedby=%1").
//                        arg(uid).
//                        arg('0').
//                        arg('0'));
//        query.exec();
//        model.submitAll();
//    });

//    return app.exec();
//}
