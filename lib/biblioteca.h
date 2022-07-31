#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include "tienda.h"
#include "producto.h"
#include <fstream>

using namespace std;

class Biblioteca {
    
    char nombre[15];
    char direccionDeInternet[24];
    char direccionFisica[24];
    char telefono[8];

    public:

    string getNombre(string);
    string getDireccionDeInternet(string);
    string getDireccionFisica(string);
    string getTelefono(string);
    
};

#endif  