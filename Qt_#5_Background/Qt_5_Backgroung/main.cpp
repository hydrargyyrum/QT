// ======================================================================
 //  main.cpp
 // ======================================================================
 //                   This file is a part of the book
 //             "Qt 5.10 Professional programming with C++"
 //                       http://qt-book.com
 // ======================================================================
 //  Copyright (c) 2017 by Max Schlee
 // ======================================================================

 #include <QtWidgets>

 // ----------------------------------------------------------------------
 int main(int argc, char** argv)
 {
     QApplication app(argc, argv);
     QWidget      wgt;

     QWidget* pwgt1 = new QWidget(&wgt);
     QPalette pal1;
     pal1.setColor(pwgt1->backgroundRole(), Qt::blue);
     pwgt1->setPalette(pal1);
     pwgt1->resize(250, 240);
     pwgt1->move(25, 25);
     pwgt1->setAutoFillBackground(true);

     QWidget* pwgt2 = new QWidget(&wgt);
     QPixmap pix("/home/hydrargyrum/images.png");
     QPalette pal2;
     pal2.setBrush(pwgt2->backgroundRole(), QBrush(QPixmap("/home/hydrargyrum/images.png")));
     pwgt2->setPalette(pal2);
     //pwgt2->resize(100, 100);
     pwgt2->setFixedSize(pix.width(),pix.height());
     pwgt2->move(75, 75);
     pwgt2->setAutoFillBackground(true);

     wgt.resize(200, 200);
     wgt.show();

     return app.exec();
 }
