#include "eliminarproducto.h"
#include "ui_eliminarproducto.h"

EliminarProducto::EliminarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EliminarProducto)
{
    ui->setupUi(this);
}

EliminarProducto::~EliminarProducto()
{
    delete ui;
}
