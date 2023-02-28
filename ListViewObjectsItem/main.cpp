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


};

int main(int argc, char** argv)
{
    QApplication app( argc, argv );
  MyWidget wgt(nullptr,1);
 /* QWidget w;
    QStringListModel model;
    model.setStringList(QStringList() <<"a"]]<<"b");
    QListView* pl = new QListView;
    pl->setModel(&model);
QHBoxLayout* ph = new QHBoxLayout;
ph->addWidget(pl);
w.setLayout(ph);
w.show(); */
    //ListViewObjectsItem model(createWidgets_temp(3));



   // ListViewObjects list;
  //  list.setModel(&model);
   // list.show();
   // MyWidget wgt(nullptr,1);
    wgt.show();


    return app.exec();
}

