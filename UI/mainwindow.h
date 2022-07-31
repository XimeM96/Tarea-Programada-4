#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../lib/tienda.h"
#include "../lib/producto.h"
#include "../lib/biblioteca.h"
#include "../lib/excepcionesProducto.h"
#include "../lib/excepcionesTienda.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CrearTienda_clicked();

    void on_CargarTienda_clicked();

    void on_GuardarTienda_clicked();

    void on_LimpiarInfo_clicked();

    void on_pushButton_3_clicked();

    void on_EliminarProducto_clicked();

    void on_ModificarProducto_clicked();

private:
    Ui::MainWindow *ui;
    Tienda* tienda;
};
#endif // MAINWINDOW_H
