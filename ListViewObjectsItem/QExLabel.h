#pragma once
#include <QLabel>
#include <QMouseEvent>

class QExLabel : public QLabel
{
    Q_OBJECT
public:
    QExLabel(QWidget* parent = 0) : QLabel(parent){};
signals:
    void clicked();
protected:
    void mouseReleaseEvent(QMouseEvent *e)
    {
        if(e->button() == Qt::LeftButton)
        {
            emit clicked();
        }
    }
};
