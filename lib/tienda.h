#ifndef TIENDA_H
#define TIENDA_H
#include "producto.h"
#include "biblioteca.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Tienda {

    private:

    char nombre[15];
    char direccionDeInternet[24];
    char direccionFisica[24];
    char telefono[8];
    vector <Producto*> arregloDeProductos;

    public:

    Tienda();
    Tienda(string, string, string , string);
    ~Tienda();
    
    string getNombre(string);
    string getDireccionDeInternet(string);
    string getDireccionFisica(string);
    string getTelefono(string);
    Producto *getProducto(int idProducto);

    void setNombre(string);
    void setDireccionDeInternet(string);
    void setDireccionFisica(string);
    void setTelefono(string);

    void agregarProducto(Producto*);
    void modificarProducto(int,string,int);
    void eliminarProducto(int);
    void guardar();
    void generarStreamBinario(ostream *streamSalida);
    void cargarStreamBinario(istream *streamEntrada);
    void crearTienda(string,string,string,string);
    string consultarInventario();
    friend ostream& operator << (ostream &o, const Tienda *tienda);

};

#endif
