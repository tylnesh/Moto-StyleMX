#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QSqlRelationalTableModel>

class MyTableModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    explicit MyTableModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // MYTABLEMODEL_H
