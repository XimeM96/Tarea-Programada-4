#ifndef ELIMINARPRODUCTO_H
#define ELIMINARPRODUCTO_H

#include <QDialog>

namespace Ui {
class EliminarProducto;
}

class EliminarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit EliminarProducto(QWidget *parent = nullptr);
    ~EliminarProducto();

private:
    Ui::EliminarProducto *ui;
};

#endif // ELIMINARPRODUCTO_H
