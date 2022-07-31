#include "agregarproducto.h"
#include "ui_agregarproducto.h"

using namespace std;

AgregarProducto::AgregarProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AgregarProducto)
{
    ui->setupUi(this);
}

AgregarProducto::~AgregarProducto()
{
    delete ui;
}

int AgregarProducto::getIDProductoNuevo()
{
    return this->ui->txtIDProductoNuevo->text().toInt();
}

string AgregarProducto::getNombreProductoNuevo()
{
    return this->ui->txtNombreProductoNuevo->text().toStdString();
}

int AgregarProducto::getExistenciasProductoNuevo()
{

    return ui->txtExistenciasProductoNuevo->text().toInt();
}
