#ifndef SQLRELATIONALDELEGATE_H
#define SQLRELATIONALDELEGATE_H

#include <QSqlRelationalDelegate>
#include <QWidget>

class SqlRelationalDelegate : public QObject
{
    Q_OBJECT
public:
    SqlRelationalDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:
};

#endif // SQLRELATIONALDELEGATE_H
