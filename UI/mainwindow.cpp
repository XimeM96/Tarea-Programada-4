#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "agregarproducto.h"
#include "modificarproducto.h"
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CrearTienda_clicked()
{
    string nombreTienda = tienda->getNombre(this->ui->txtNombreTienda->text().toStdString());
    string direccionDeInternet = tienda->getDireccionDeInternet(this->ui->txtDireccionWeb->text().toStdString());
    string direccionFisica = tienda->getDireccionFisica(this->ui->txtDireccionFisica->text().toStdString());
    string telefono = tienda->getTelefono(this->ui->txtTelefono->text().toStdString());

    if(nombreTienda == "" || direccionDeInternet == "" || direccionFisica == "" || telefono == ""){

        QMessageBox* msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("Error al crear la tienda. Por favor complete todos los datos.");
        msgbox->open();
        return;

    } else {


        try {

            tienda->crearTienda(nombreTienda, direccionDeInternet, direccionFisica,telefono);

            QString nombre = QString::fromStdString(nombreTienda);
            this->ui->txtNombreTienda->setText(nombre);
            QString direccion = QString::fromStdString(direccionDeInternet);
            this->ui->txtDireccionWeb->setText(direccion);
            QString direccionFis = QString::fromStdString(direccionFisica);
            this->ui->txtDireccionFisica->setText(direccionFis);
            QString tel = QString::fromStdString(telefono);
            this->ui->txtTelefono->setText(tel);

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Felicidades!!");
            msgbox->setText("Su tienda ha sido creada con éxito");
            msgbox->open();


        } catch (const ExcepcionNombreTienda& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. Nombre inválido.");
            msgBox->open();
            return;
        } catch (const ExcepcionDireccionInternet& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. La dirección de internet es inválida.");
            msgBox->open();
            return;
        } catch (const ExcepcionDireccionFisica& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. La dirección física es inválida.");
            msgBox->open();
            return;
        } catch (const ExcepcionTelefono& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. El número de teléfono es inválido.");
            msgBox->open();
            return;
        }


    }
}


void MainWindow::on_CargarTienda_clicked()
{

    QString archivoBinario = QFileDialog::getOpenFileName(this,"Abrir archivo binario", "",tr("Archivo de datos (*dat);;All files(*)"));

    if (archivoBinario != "")
    {
        string archivo = archivoBinario.toStdString();
        ifstream streamEntrada;
        streamEntrada.open(archivo, ios::in|ios::binary);

        if (!streamEntrada.is_open())
        {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("No se ha podido leer el archivo.");
            msgBox->open();
            return;
        }

        this->tienda = new Tienda();
        this->tienda->cargarStreamBinario(&streamEntrada);
        streamEntrada.close();

        stringstream infoTienda;
        infoTienda << this->tienda;
        string lineaALeer {};
        getline(infoTienda, lineaALeer);
        this->ui->txtNombreTienda->setText(QString::fromStdString(lineaALeer));
        getline(infoTienda, lineaALeer);
        this->ui->txtDireccionWeb->setText(QString::fromStdString(lineaALeer));
        getline(infoTienda, lineaALeer);
        this->ui->txtDireccionFisica->setText(QString::fromStdString(lineaALeer));
        getline(infoTienda, lineaALeer);
        this->ui->txtTelefono->setText(QString::fromStdString(lineaALeer));
        this->ui->listaDeProductos->clear();


        while (getline(infoTienda, lineaALeer))
        {
            QString producto = QString::fromStdString(lineaALeer);
            this->ui->listaDeProductos->addItem(producto);
        }
    }
}


void MainWindow::on_GuardarTienda_clicked()
{

    string nombre = this->ui->txtNombreTienda->text().toStdString();
    string dirInternet = this->ui->txtDireccionWeb->text().toStdString();
    string dirFisica = this->ui->txtDireccionFisica->text().toStdString();
    string tel = this->ui->txtTelefono->text().toStdString();

    string nombreTienda = tienda->getNombre(nombre);
    string direccionDeInternet = tienda->getDireccionDeInternet(dirInternet);
    string direccionFisica = tienda->getDireccionFisica(dirFisica);
    string telefono = tienda->getTelefono(tel);

        try {

          this->tienda->crearTienda(nombreTienda, direccionDeInternet, direccionFisica, telefono);

        } catch (const ExcepcionNombreTienda& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. Nombre inválido.");
            msgBox->open();
            return;
        } catch (const ExcepcionDireccionInternet& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. La dirección de internet es inválida.");
            msgBox->open();
            return;
        } catch (const ExcepcionDireccionFisica& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. La dirección física es inválida.");
            msgBox->open();
            return;
        } catch (const ExcepcionTelefono& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error guardando la tienda. El número de teléfono es inválido.");
            msgBox->open();
            return;
        }

        QString nombreArchivo = QFileDialog::getSaveFileName(this,"Guardar Archivo de Datos", "",tr("Archivo de datos (*.dat);;All Files (*)"));

        if (nombreArchivo != "")
        {
            string archivo = nombreArchivo.toStdString();
            ofstream archivoSalida(archivo, ios::out|ios::binary);

            if (!archivoSalida.is_open())
            {
                QMessageBox* msgBox = new QMessageBox(this);
                msgBox->setWindowTitle("ERROR");
                msgBox->setText("Error imprimiendo el archivo solicitado.");
                msgBox->open();
                return;
            }

            this->tienda->generarStreamBinario(&archivoSalida);
            archivoSalida.close();
        }
}


void MainWindow::on_LimpiarInfo_clicked()
{
    this->ui->txtNombreTienda->setText("");
    this->ui->txtDireccionWeb->setText("");
    this->ui->txtDireccionFisica->setText("");
    this->ui->txtTelefono->setText("");
    this->ui->txtNombreTienda->setFocus();
}


void MainWindow::on_pushButton_3_clicked()
{

    //Botón agregar productos

    AgregarProducto AgregarProducto{this};
    AgregarProducto.setWindowTitle("NUEVO PRODUCTO");
    int ejecutable = AgregarProducto.exec();

    if (ejecutable == QDialog::Accepted)
    {
        int idProducto = AgregarProducto.getIDProductoNuevo();
        string nombreProducto = AgregarProducto.getNombreProductoNuevo();
        int existenciasProducto = AgregarProducto.getExistenciasProductoNuevo();

        try {
            Producto *producto = new Producto(idProducto, nombreProducto, existenciasProducto);

            tienda->agregarProducto(producto);

            QString id = QString::number(idProducto);
            QString nombre = QString::fromStdString(nombreProducto);
            QString existencias = QString::number(existenciasProducto);
            this->ui->listaDeProductos->addItem("ID: " + id + ", nombre: " + nombre + ", en existencias: " + existencias);
            this->ui->listaDeProductos->sortItems();

            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Felicidades!!");
            msgbox->setText("Su producto ha sido agregado exitosamente.");
            msgbox->open();

        } catch (ExcepcionNombreProductoInvalido &e) {

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error al agregar el producto nuevo. Nombre inválido.");
            msgBox->open();
            return;
        } catch (ExcepcionExistenciasDisponibles &e) {

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error al agregar el producto nuevo. Número de existencias inválido.");
            msgBox->open();
            return;
        } catch (ExcepcionIDProducto &e) {

            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("Error al agregar el producto nuevo. ID inválido.");
            msgBox->open();
            return;
        }



   }

}


void MainWindow::on_EliminarProducto_clicked()
{

    QListWidgetItem *productoAeliminar = this->ui->listaDeProductos->currentItem();

    if (productoAeliminar == nullptr)
        {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("ERROR");
            msgBox->setText("No se ha elegido ningún producto para eliminar.");
            msgBox->open();
        }
        else{

            try {
                  QListWidgetItem *linea = this->ui->listaDeProductos->takeItem(this->ui->listaDeProductos->currentRow());

                  delete linea;

                  tienda->eliminarProducto(this->ui->listaDeProductos->currentRow());

              } catch (const exception &e) {
                  QMessageBox *msgbox = new QMessageBox(this);
                  msgbox->setWindowTitle("ERROR");
                  msgbox->setText("No se pudo eliminar el producto seleccionado.");
                  msgbox->open();
              }

                QMessageBox *msgbox = new QMessageBox(this);
                msgbox->setWindowTitle("Felicidades!!");
                msgbox->setText("El producto seleccionado ha sido eliminado exitosamente.");
                msgbox->open();
          }

}


void MainWindow::on_ModificarProducto_clicked()
{

    QListWidgetItem *productoAModificar = this->ui->listaDeProductos->currentItem();
    ModificarProducto ModificarProducto{this};
    ModificarProducto.setWindowTitle("MODIFICAR PRODUCTO");
    int ejecutable = ModificarProducto.exec();


    if(productoAModificar == nullptr){

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("ERROR");
        msgbox->setText("No se ha seleccionado ningún producto para modificar.");
        msgbox->open();

    } else if(ejecutable == QDialog::Accepted){

        try{

        string nombreProd = ModificarProducto.getNombreNuevo();
        int existenciasProd = ModificarProducto.getExistenciasNuevas();

        this->tienda->getProducto(this->ui->listaDeProductos->currentRow() + 1)->setNombreProducto(nombreProd);
        this->tienda->getProducto(this->ui->listaDeProductos->currentRow() + 1)->setExistenciasTotales(existenciasProd);

        QString id = QString::number(this->tienda->getProducto(this->ui->listaDeProductos->currentRow() + 1)->getIdProducto());
        QString nombre = QString::fromStdString(nombreProd);
        QString existencias = QString::number(existenciasProd);
        this->ui->listaDeProductos->currentItem()->setText("ID: " + id + ", nombre: " + nombre + ", en existencias: " + existencias);

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Felicidades!!");
        msgbox->setText("El producto seleccionado ha sido modificado exitosamente.");
        msgbox->open();

        } catch (const ExcepcionNombreProductoInvalido& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error al modificar el producto. El nombre ingresado es inválido.");
            msgBox->setText(e.what());
            msgBox->open();
            return;

        } catch (const ExcepcionExistenciasDisponibles& e) {
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->setWindowTitle("Error al modificar el producto. La cantidad de existencias ingresadas son inválidas.");
            msgBox->setText(e.what());
            msgBox->open();
            return;
        }

    }


}

