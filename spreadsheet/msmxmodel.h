#ifndef MSMXMODEL_H
#define MSMXMODEL_H
#include <QtSql/qtsqlglobal.h>
#include <QtSql/qsqltablemodel.h>

#include <QtCore/qtypeinfo.h>
QT_BEGIN_NAMESPACE
class Q_SQL_EXPORT MSMXRelation
{
public:
    MSMXRelation() {}
    MSMXRelation(const QString &aTableName, const QString &indexCol,
               const QString &displayCol)
        : tName(aTableName), iColumn(indexCol), dColumn(displayCol) {}

void swap(MSMXRelation &other) Q_DECL_NOTHROW
{
qSwap(tName, other.tName);
qSwap(iColumn, other.iColumn);
qSwap(dColumn, other.dColumn);
}

inline QString tableName() const
{ return tName; }
inline QString indexColumn() const
{ return iColumn; }
inline QString displayColumn() const
{ return dColumn; }
bool isValid() const Q_DECL_NOTHROW
{ return !(tName.isEmpty() || iColumn.isEmpty() || dColumn.isEmpty()); }
private:
QString tName, iColumn, dColumn;
};
Q_DECLARE_SHARED_NOT_MOVABLE_UNTIL_QT6(MSMXRelation)

class MSMXModelPrivate;

class Q_SQL_EXPORT MSMXModel: public QSqlTableModel
{
Q_OBJECT

public:
enum JoinMode {
InnerJoin,
LeftJoin
};

explicit MSMXModel(QObject *parent = Q_NULLPTR,
QSqlDatabase db = QSqlDatabase());
virtual ~MSMXModel();

QVariant data(const QModelIndex &item, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
bool setData(const QModelIndex &item, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

void clear() Q_DECL_OVERRIDE;
bool select() Q_DECL_OVERRIDE;

void setTable(const QString &tableName) Q_DECL_OVERRIDE;
virtual void setRelation(int column, const MSMXRelation &relation);
MSMXRelation relation(int column) const;
virtual QSqlTableModel *relationModel(int column) const;
void setJoinMode( MSMXModel::JoinMode joinMode );

public Q_SLOTS:
void revertRow(int row) Q_DECL_OVERRIDE;

protected:
QString selectStatement() const Q_DECL_OVERRIDE;
bool updateRowInTable(int row, const QSqlRecord &values) Q_DECL_OVERRIDE;
bool insertRowIntoTable(const QSqlRecord &values) Q_DECL_OVERRIDE;
QString orderByClause() const Q_DECL_OVERRIDE;

private:
Q_DECLARE_PRIVATE(MSMXModel)
};

QT_END_NAMESPACE

#endif // MSMXMODEL_H
