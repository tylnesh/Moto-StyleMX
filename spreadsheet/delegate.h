#ifndef DELEGATE_H
#define DELEGATE_H

#include <QItemDelegate>
#include <QSqlRelationalDelegate>
#include <QObject>
#include <QModelIndex>
#include <QSize>
#include <QSpinBox>

QT_FORWARD_DECLARE_CLASS(QPainter)

class Delegate : public QSqlRelationalDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = 0);

QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

void paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const override;

QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

bool editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &option,
                 const QModelIndex &index) override;



signals:

public slots:


};

#endif // DELEGATE_H
