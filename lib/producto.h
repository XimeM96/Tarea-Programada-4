#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Producto{

    private:

    int idProducto;
    char nombreProducto[20];
    int existenciasTotales;   

    public:

    Producto();
    Producto(int,string,int);
    int getIdProducto();
    string getNombreProducto();
    int getExistenciasTotales();
    void setIdProducto(int);
    void setNombreProducto(string);
    void setExistenciasTotales(int);
    friend ostream& operator << (ostream &streamSalida, const Producto *producto);



};

#endif