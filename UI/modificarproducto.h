#ifndef MODIFICARPRODUCTO_H
#define MODIFICARPRODUCTO_H

#include <QDialog>

using namespace std;

namespace Ui {
class ModificarProducto;
}

class ModificarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarProducto(QWidget *parent = nullptr);
    ~ModificarProducto();

    string getNombreNuevo();
    int getExistenciasNuevas();

private:
    Ui::ModificarProducto *ui;
};

#endif // MODIFICARPRODUCTO_H
