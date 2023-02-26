#include <QtWidgets>
#include <QtSql>
#include "ListViewObjectsItem.h"
#include "ListViewObjects.h"
#include "MyWidget.h"

// Сonnect to DB, create widgets!!!!!!

QList<MyWidget> createWidgets(QSqlDatabase db){
    // connect to the DB, get pictures and characteristics

    /* QImage image =
    QVariant characteristics =
    ...
    return object QList<MyWidget>
    */
}

QList<MyWidget> createWidgets_temp(int n){
    QList<MyWidget> list;

    for (int i=0; i < n; i++)
    {
        QWidget wgt;
        wgt.resize(800,200);

        QPainter painter(&wgt);
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(600, 100, 50, 50);

        QImage img  ("/image.png");
       // QImage img  ("/home/hydrargyrum/Qt/ListViewObjectsItem/image.png");
        QSize picSize(100,100);

        QLabel* plbl = new QLabel;
        QLabel* plbl1 = new QLabel("Характеристики объекта:");


        plbl->setFixedSize(img.scaled(picSize,Qt::KeepAspectRatio).size());
        plbl->setPixmap(QPixmap::fromImage(img.scaled(picSize,Qt::KeepAspectRatio)));

        QLabel** mplbl = new QLabel* [i];
        for(int j=0; j < i; j++)
            mplbl[j] = new QLabel("Характеристика");




    }

}


// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app( argc, argv );

    ListViewObjectsItem model(createWidgets_temp(3));

            //(QList<QWidget>() << 123 << 2341 << 32 << 5342 << 723);

    ListViewObjects list;
    list.setModel(&model);
    list.show();

    return app.exec();
}

