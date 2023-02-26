#pragma once

#include <QAbstractListModel>
#include <QWidget>
#include <MyWidget.h>

// ======================================================================
class ListViewObjectsItem : public QAbstractListModel {
Q_OBJECT
private:
    QList<QWidget> m_list;

public:
    ListViewObjectsItem(const QList<MyWidget>& list, QObject* pobj = 0);
};
