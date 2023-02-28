#pragma once
#include <QAbstractListModel>
#include <MyWidget.h>

class ListViewObjectsItem : public QAbstractListModel {
Q_OBJECT
private:
    QList<MyWidget*> m_list;

public:
    ListViewObjectsItem(const QList<MyWidget*>& list, QObject* pobj = 0);

    QVariant data(const QModelIndex& index, int nRole) const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
};
