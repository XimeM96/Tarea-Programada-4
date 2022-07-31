#include "producto.h"
#include "excepcionesProducto.h"
#include <string>
#include <string.h>
#include <iostream>
#include <regex>

Producto::Producto(){

    this->idProducto = 0;
    strcpy(this->nombreProducto, "");
    this->existenciasTotales = 0;

}

Producto::Producto(int i,string n,int e){

    if (i <= 0){

        throw ExcepcionIDProducto();

    }
    if (n.size() == 0 || n.size() > 20){

        throw ExcepcionNombreProductoInvalido();

    }
    if (e < 0){

        throw ExcepcionExistenciasDisponibles();

    }  

    this->setIdProducto(i);
    strcpy(this->nombreProducto, n.c_str());
    this->setExistenciasTotales(e);
}

int Producto::getIdProducto(){

    return this->idProducto;

}

string Producto::getNombreProducto(){

    return this->nombreProducto;

}

int Producto::getExistenciasTotales(){

    return this->existenciasTotales;

}

void Producto::setIdProducto(int iP){

    this->idProducto = iP;

}

 void Producto::setNombreProducto(string nP){

    if (nP.size() == 0 || nP.size() > 20){

        throw ExcepcionNombreProductoInvalido();

    }  

    string nombreProducto = {strcpy(this->nombreProducto, nP.c_str())};

 
}

void Producto::setExistenciasTotales(int eT){

    this->existenciasTotales = eT;

}

ostream& operator << (ostream &streamSalida, const Producto *producto)
{
    streamSalida << "ID: " << producto->idProducto << ", " << "nombre: " << producto->nombreProducto << ", " << "en existencias: " << producto->existenciasTotales;

    return streamSalida;
}

