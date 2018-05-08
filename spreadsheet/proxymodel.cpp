#include "proxymodel.hpp"

//  DATA =

QVariant ProxyModel::data(const QModelIndex &index, int role) const {
 // if text alignment is asked for enters
 if(role == Qt::TextAlignmentRole) {
 // if the column alignment was set-up for all columns
 if(alignMap.contains(-1))
 return QVariant(alignMap.value(-1));
 // searches if the column alignment was set-up and returns the flag
 if(alignMap.contains(index.column())) {
 return QVariant(alignMap.value(index.column()));
 }
 }
 // if the column wasn't found or if alignment wasn't requested returns default QVariant
 return QSortFilterProxyModel::data(index, role);
}

void ProxyModel::setAlignment(unsigned int index, Qt::Alignment flag) {
 // checks if setAlignmentToAll() was called and, if so, rests alignMap
 if(alignMap.contains(-1))
 clearAlignment();
 // inserts flag
 alignMap.insert(index, flag);
}

void ProxyModel::setAlignmentToAll(Qt::Alignment flag) {
 // reset QMap
 clearAlignment();
 // inserts flag
 alignMap.insert(-1, flag);
}

void ProxyModel::clearAlignment() {
 // deletes all items
 alignMap.clear();
}

//  FLAGS

Qt::ItemFlags ProxyModel::flags(const QModelIndex &index) const {
 // if the column alignment was set-up for all columns
 if(flagMap.contains(-1))
 return flagMap.value(-1);
 // searches if the column alignment was set-up and returns the flag
 if(flagMap.contains(index.column())) {
 return flagMap.value(index.column());
 }
 return QSortFilterProxyModel::flags(index);
}

void ProxyModel::setFlag(unsigned int index, Qt::ItemFlags flag) {
 // checks if setFlagToAll() was called and, if so, rests flagMap
 if(flagMap.contains(-1))
 clearFlag();
 // inserts flag
 flagMap.insert(index, flag);
}

void ProxyModel::setFlagToAll(Qt::ItemFlags flag) {
 // reset QMap
 clearFlag();
 // inserts flag
 flagMap.insert(-1, flag);
}

void ProxyModel::clearFlag() {
 // deletes all items
 flagMap.clear();
}

void ProxyModel::setEnabled(unsigned int index, bool FLAG) {
 if(FLAG)
 setFlag(index, Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEnabled);
 else
 setFlag(index, Qt::NoItemFlags);
}

void ProxyModel::setEditable(unsigned int index, bool FLAG) {
 if(FLAG)
 setFlag(index, Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEnabled);
 else
 setFlag(index, Qt::NoItemFlags | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsEnabled);
}
