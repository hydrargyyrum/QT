#include "ListViewObjectsItem.h"
#include "MyWidget.h"

//Q_DECLARE_METATYPE (MyWidget)

 ListViewObjectsItem::ListViewObjectsItem(const QList<MyWidget*>& list, QObject* pobj/*=0*/)
        : QAbstractListModel(pobj)
        , m_list(list)
{
}

 QVariant ListViewObjectsItem::data(const QModelIndex& index, int nRole) const
 {
    if (!index.isValid()) {
         return QVariant();
     }
    if (index.row() < 0 || index.row() >= m_list.size()) {
         return QVariant();
     }
     return (nRole == Qt::DisplayRole) //если все хорошо, то верни указатель на виджет, который надо как-то отрисовать и распознать
            ? &m_list.at(index.row())  //ЧТО С ТИПОМ?
            : QVariant();
 }

 int ListViewObjectsItem::rowCount(const QModelIndex& parent/*=QModelIndex()*/
                           ) const
 {
     if (parent.isValid()) {
         return 0;
     }

     return m_list.size();
 }
