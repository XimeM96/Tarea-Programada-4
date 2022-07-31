#ifndef AGREGARPRODUCTO_H
#define AGREGARPRODUCTO_H

#include <QDialog>
#include <string>

using namespace std;

namespace Ui {
class AgregarProducto;
}

class AgregarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit AgregarProducto(QWidget *parent = nullptr);
    ~AgregarProducto();

    int getIDProductoNuevo();
    string getNombreProductoNuevo();
    int getExistenciasProductoNuevo();

private:
    Ui::AgregarProducto *ui;
};

#endif // AGREGARPRODUCTO_H
