#include <QtWidgets>
#include <iostream>
#include "Progress.h"

// ----------------------------------------------------------------------
Progress::Progress(QWidget* pwgt/*= 0*/)
    : QWidget(pwgt)
    , m_nStep(0), k(0)
{
    m_pprb = new QProgressBar;
    m_pprb->setRange(0, 5);
    m_pprb->setMinimumWidth(200);
    m_pprb->setAlignment(Qt::AlignCenter);

    QPushButton* pcmdStep  = new QPushButton("&Тык на счастье");
    QPushButton* pcmdReset = new QPushButton("&Перерождение");

 //   QLabel *l =new QLabel("$Следуй за мечтой")

    QObject::connect(pcmdStep, SIGNAL(clicked()), SLOT(slotStep()));
    QObject::connect(pcmdReset, SIGNAL(clicked()), SLOT(slotReset()));


    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(m_pprb);
    phbxLayout->addWidget(pcmdStep);
    phbxLayout->addWidget(pcmdReset);
  //  phbxLayout->addWidget(l);
    setLayout(phbxLayout);
}

// ----------------------------------------------------------------------
void Progress::slotStep()
{
    m_pprb->setValue(++m_nStep);
    ++k;
    std::cout << k << "\n";
    if (k==5) {

    QLabel* lbl = new QLabel (
                "<CENTER><TABLE>"
                   "    <TR BGCOLOR=ORANGE>"
                   "        <TD>Следуй за мечтой</TD>"
                   "    </TR>"
                "</TABLE></CENTER>"
                  );
    lbl->resize(300,200);
    lbl->show();
}
}

// ----------------------------------------------------------------------
void Progress::slotReset()
{
    m_nStep = 0;
    m_pprb->reset();
}
