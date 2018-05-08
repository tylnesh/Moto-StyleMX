#include "mytablemodel.h"

MyTableModel::MyTableModel(QObject *parent)
    : QSqlRelationalTableModel(parent)
{
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
