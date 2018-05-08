#include "delegate.h"
#include <QtWidgets>


Delegate::Delegate(QObject *parent) : QSqlRelationalDelegate(parent)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{

    if (index.column() != 5) {
           QStyleOptionViewItem opt = option;
           opt.rect.adjust(0, 0, -1, -1); // since we draw the grid ourselves
           QSqlRelationalDelegate::paint(painter, opt, index);
       } else {
           const QAbstractItemModel *model = index.model();
           QPalette::ColorGroup cg = (option.state & QStyle::State_Enabled) ?
               (option.state & QStyle::State_Active) ? QPalette::Normal : QPalette::Inactive : QPalette::Disabled;

           if (option.state & QStyle::State_Selected)
               painter->fillRect(option.rect, option.palette.color(cg, QPalette::Highlight));

           //int rating = model->data(index, Qt::DisplayRole).toInt();
           //int width = star.width();
           //int height = star.height();
          // int x = option.rect.x();
          // int y = option.rect.y() + (option.rect.height() / 2) - (height / 2);
           //for (int i = 0; i < rating; ++i) {
            //   painter->drawPixmap(x, y, star);
           //    x += width;
         //  }
           drawFocus(painter, option, option.rect.adjusted(0, 0, -1, -1)); // since we draw the grid ourselves
       }

       QPen pen = painter->pen();
       painter->setPen(option.palette.color(QPalette::Mid));
       painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
       painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
       painter->setPen(pen);

}


QWidget *Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{


}

//void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const{


//}

//void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{


//}

//void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{


//}

