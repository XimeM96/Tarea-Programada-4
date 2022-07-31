#include "modificarproducto.h"
#include "ui_modificarproducto.h"

ModificarProducto::ModificarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarProducto)
{
    ui->setupUi(this);
}

ModificarProducto::~ModificarProducto()
{
    delete ui;
}

string ModificarProducto::getNombreNuevo(){

    return this->ui->txtNombreNuevoProducto->text().toStdString();
}

int ModificarProducto::getExistenciasNuevas(){

    return this->ui->txtExistenciasNuevasProducto->text().toInt();
}
