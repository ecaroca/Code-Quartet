#include "informacion.h"
#include "ui_informacion.h"

informacion::informacion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::informacion)
{
    ui->setupUi(this);
}

informacion::~informacion()
{
    delete ui;
}
