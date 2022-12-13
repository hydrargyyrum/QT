#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget    wgt;
    QLabel* l = new QLabel("Условия для Нового Года:");
    QCheckBox* pchkNormal = new QCheckBox("&Снежная погода");
    pchkNormal->setChecked(true);
    QCheckBox* pchkNormal1 = new QCheckBox("&Красивая ёлка");
    pchkNormal->setChecked(true);
    QCheckBox* pchkNormal2 = new QCheckBox("&Упакованные подарки");
    pchkNormal->setChecked(true);
    QCheckBox* pchkNormal5 = new QCheckBox("&Неадекватные люди");
    pchkNormal->setChecked(false);
    QCheckBox* pchkNormal3 = new QCheckBox("&Хорошее настроение");
    pchkNormal->setChecked(true);
    QCheckBox* pchkNormal4 = new QCheckBox("&Оливье");
    pchkNormal->setChecked(true);
    QCheckBox* pchkNormal6 = new QCheckBox("&ОМОН в доме");
    pchkNormal->setChecked(false);

    QCheckBox* pchkTristate = new QCheckBox("&Качественные напитки 18+");
    pchkTristate->setTristate(true);
    pchkTristate->setCheckState(Qt::PartiallyChecked);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(l);
    pvbxLayout->addWidget(pchkNormal);
    pvbxLayout->addWidget(pchkNormal1);
    pvbxLayout->addWidget(pchkNormal2);
    pvbxLayout->addWidget(pchkNormal5);
    pvbxLayout->addWidget(pchkNormal3);
    pvbxLayout->addWidget(pchkNormal4);
    pvbxLayout->addWidget(pchkNormal6);

    pvbxLayout->addWidget(pchkTristate);
    wgt.setLayout(pvbxLayout);

    wgt.show();

    return app.exec();
}
