#pragma once
#include <QListView>

class ListViewObjects : public QListView {
Q_OBJECT
public:
    ListViewObjects(QObject* pobj = 0);
};
