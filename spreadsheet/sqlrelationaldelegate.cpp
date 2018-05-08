#include "sqlrelationaldelegate.h"
#include <QSqlRelationalDelegate>

SqlRelationalDelegate::SqlRelationalDelegate(QObject *parent) : QObject(parent)
{

}


QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)
{
        /*//QVariant data(&index,12); //isLocked is  12th column
        if(data == 1)
            return nullptr; // do not create editor

        else
            {
            data.setValue(1);
            return QSqlRelationalDelegate::createEditor(*parent, &option, &index);*/
    //}
}
