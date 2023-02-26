#pragma once

#include <QListView>

// ======================================================================
class listview : public QListView {
Q_OBJECT
public:
    listview(QObject* pobj = 0);
};

