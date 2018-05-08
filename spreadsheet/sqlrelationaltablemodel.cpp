#include "sqlrelationaltablemodel.h"

#include <QBrush>

SqlRelationalTableModel::SqlRelationalTableModel(QObject *parent, QSqlDatabase db)
    :QSqlRelationalTableModel(parent, db)
{

}

QVariant SqlRelationalTableModel::data(const QModelIndex &item, int role) const
{
    if(role == Qt::BackgroundRole)

    {

       /* if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Waiting for approval")
                        return QVariant(QBrush(QColor::fromRgb(255,153,0)));*/
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Approved for production")
                        return QVariant(QBrush(QColor::fromRgb(135,206,235)));
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "EPS DONE")
                        return QVariant(QBrush(Qt::yellow));
       /* if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Up for print")
                        return QVariant(QBrush(Qt::cyan));*/
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Printed")
                        return QVariant(QBrush(Qt::green));
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Package complete")
                        return QVariant(QBrush(Qt::gray));
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Shipped")
                        return QVariant(QBrush(Qt::lightGray));
        if(QSqlRelationalTableModel::data(index(item.row(), 3), Qt::DisplayRole).toString().trimmed() == "Hold")
                        return QVariant(QBrush(Qt::red));


    }
    return QSqlRelationalTableModel::data(item, role);
}
