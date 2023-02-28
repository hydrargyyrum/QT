#include "ListViewObjectsItem.h"
#include "MyWidget.h"

 ListViewObjectsItem::ListViewObjectsItem(const QList<MyWidget*>& list, QObject* pobj/*=0*/)
        : QAbstractListModel(pobj)
        , m_list(list)
{
}
