#ifndef PROXYMODEL_HPP
#define PROXYMODEL_HPP

#include <QSortFilterProxyModel>
#include <QMap>

class ProxyModel : public QSortFilterProxyModel {
Q_OBJECT
// PRIVATE VARIABLES
QMap<int,Qt::Alignment> alignMap;
QMap<int,Qt::ItemFlags> flagMap;

public:
// CONSTRUCTOR
explicit ProxyModel(QObject *parent = 0) : QSortFilterProxyModel(parent) {}

// VIRTUAL FUNCTIONS INHERITED FROM QT SORT FILTER MODEL
QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
Qt::ItemFlags flags(const QModelIndex &index) const;

// PUBLIC FUNCTIONS
void setAlignment(unsigned int, Qt::Alignment);
void setAlignmentToAll(Qt::Alignment);
void clearAlignment();

void setFlag(unsigned int, Qt::ItemFlags);
void setFlagToAll(Qt::ItemFlags);
void clearFlag();

void setEnabled(unsigned int index, bool FLAG);
void setEditable(unsigned int index, bool FLAG);
};

#endif // PROXYMODEL_HPP
