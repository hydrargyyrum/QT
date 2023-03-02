#include <QtGui>
#include <QtWidgets>
#include "MyWidget.h"
#include "QExLabel.h"

//MyWidget::MyWidget(QWidget* parent = nullptr/*, QSqlDatabase db*/); // такой конструктор будет, когда подтянем БД
MyWidget::MyWidget(QWidget *parent, int k) : QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    this->k=k;

    msgBox_pic = new QMessageBox();
    msgBox_pic->setText("Заглушка. Просмотр изображения.");
    msgBox_name = new QMessageBox();
    msgBox_name->setText("Заглушка. Просмотр подробных сведений об объекте.");

    QImage img  ("/home/hydrargyrum/Qt/ListViewObjectsItem/image.png");             //прилетает из БД
    QSize picSize(100,100);
    plbl_pic = new QExLabel;
    plbl_pic->setFixedSize(img.scaled(picSize,Qt::KeepAspectRatio).size());
    plbl_pic->setPixmap(QPixmap::fromImage(img.scaled(picSize,Qt::KeepAspectRatio)));

    plbl = new QLabel("Характеристики объекта:");                //неизменно
    plbl_name = new QExLabel;             //имя из БД
    plbl_name->setText("Название объекта");
    plbl->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    plbl_pic->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    plbl_circle = new QLabel("");
    plbl_circle->setFixedSize(50,50);
    plbl_circle->setStyleSheet("background-color:"+colorSelection(k)+"; border-radius: 25px ");
    plbl_circle->setToolTip("Это текстовая подсказка"); //почему не работает? или работает, но через раз?


    mplbl = new QLabel* [k];                        //число приходит из БД, которая передается в конструктор
    for(int j=0; j < k; j++){
        mplbl[j] = new QLabel("Характеристика");
        mplbl[j]->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    }

    cur_image = QCursor(Qt::PointingHandCursor);
    cur_name = QCursor(Qt::PointingHandCursor);
    plbl_pic->setCursor(cur_image);
    plbl_name->setCursor(cur_name);

    fillLayout();

    connect(plbl_pic, SIGNAL(clicked()), msgBox_pic, SLOT(exec()));
    connect(plbl_name, SIGNAL(clicked()), msgBox_name, SLOT(exec()));
}

 void MyWidget::fillLayout(){
     QHBoxLayout* phbxLayout = new QHBoxLayout;
     QVBoxLayout* pvbxLayout = new QVBoxLayout;
     phbxLayout->setContentsMargins(20,20,20,20);
     phbxLayout->setSpacing(10);
     phbxLayout->addWidget(plbl_pic);

     pvbxLayout->setContentsMargins(5,5,5,5);
     pvbxLayout->setSpacing(5);
     pvbxLayout->addWidget(plbl_name);
     pvbxLayout->addWidget(plbl);

     for(int j=0; j < k; j++)
     pvbxLayout->addWidget(mplbl[j]);

     phbxLayout->addLayout(pvbxLayout);
     phbxLayout->addWidget(plbl_circle);
     this->setLayout(phbxLayout);

}

 QString MyWidget::colorSelection(int l){
     if (l==1) return "red";
     if (l==2) return "yellow";
     if (l==3) return "green";
     else return nullptr;
 }
