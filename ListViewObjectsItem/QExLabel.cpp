#include <QExLabel.h>

void QExLabel::mouseReleaseEvent(QMouseEvent *e) {
    if(e->button() == Qt::LeftButton)
    {
        emit clicked();
    }
};
