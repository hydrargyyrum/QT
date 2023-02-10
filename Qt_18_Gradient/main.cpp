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

// ======================================================================
class LinearGradientWidget : public QWidget {
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter        painter(this);
        QLinearGradient gradient(0, 0, width(), height());

        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(0.5, Qt::green);
        gradient.setColorAt(1, Qt::blue);
        painter.setBrush(gradient);
        painter.drawRect(rect());
    }

public:
    LinearGradientWidget(QWidget* pwgt = 0) : QWidget(pwgt)
    {
    }
};

// ======================================================================
 class ConicalGradientWidget : public QWidget {
 protected:
     virtual void paintEvent(QPaintEvent*)
     {
         QPainter         painter(this);
         QConicalGradient gradient(width() / 2, height() / 2, 0);

         gradient.setColorAt(0, Qt::red);
         gradient.setColorAt(0.4, Qt::green);
         gradient.setColorAt(0.8, Qt::blue);
         gradient.setColorAt(1, Qt::red);
         painter.setBrush(gradient);
         painter.drawRect(rect());
     }

 public:
     ConicalGradientWidget(QWidget* pwgt = 0) : QWidget(pwgt)
     {
     }
 };

 // ======================================================================
 class RadialGradientWidget : public QWidget {
  protected:
      virtual void paintEvent(QPaintEvent*)
      {
          QPainter        painter(this);
          QPointF         ptCenter(rect().center());
          QRadialGradient gradient(ptCenter, width() / 2, ptCenter);

          gradient.setColorAt(0, Qt::red);
          gradient.setColorAt(0.5, Qt::green);
          gradient.setColorAt(1, Qt::blue);
          painter.setBrush(gradient);
          painter.drawRect(rect());
      }

  public:
      RadialGradientWidget(QWidget* pwgt = 0) : QWidget(pwgt)
      {
      }
  };
// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    LinearGradientWidget wgt;
    ConicalGradientWidget wgt2;
    RadialGradientWidget wgt3;
    wgt2.show();
    wgt.show();
    wgt3.show();

    return app.exec();
}
