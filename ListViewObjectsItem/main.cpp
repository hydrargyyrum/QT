#include <QApplication>
#include <QtSql>
#include<QHBoxLayout>
#include "ListViewObjectsItem.h"
#include "ListViewObjects.h"
#include "MyWidget.h"

QList<MyWidget> createWidgets(QSqlDatabase db){
    // connect to the DB, get pictures and characteristics

    /* MyWidget* wgt =
    ...
    return object QList<MyWidget>
    */
};

QList<MyWidget*> createWidgets_temp(int n){
    QList<MyWidget*> list;
    MyWidget** mpWidget = new MyWidget* [n];
    for (int i=0; i < n; i++) {
        mpWidget[i]= new MyWidget(nullptr,i);
        list << mpWidget[i];
    }
    return list;
};

int main(int argc, char** argv)
{
    QApplication app( argc, argv );
    int k =2;

    QWidget w;
    ListViewObjectsItem model(createWidgets_temp(k));
    ListViewObjects* pl = new ListViewObjects;
    pl->setModel(&model);
    QHBoxLayout* ph = new QHBoxLayout;
    ph->addWidget(pl);
    w.setLayout(ph);
    w.show();

    MyWidget wgt(nullptr,k);
    wgt.show();


    return app.exec();
}

