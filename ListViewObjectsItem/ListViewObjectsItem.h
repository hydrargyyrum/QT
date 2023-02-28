#pragma once
#include <QAbstractListModel>
#include <MyWidget.h>

class ListViewObjectsItem : public QAbstractListModel {
Q_OBJECT
private:
    QList<MyWidget*> m_list;

public:
    ListViewObjectsItem(const QList<MyWidget*>& list, QObject* pobj = 0);
};
