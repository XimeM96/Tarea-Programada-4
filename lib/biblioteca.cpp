#include "biblioteca.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;


string Biblioteca::getNombre(string nom)
{

    string nombre = {strcpy(this->nombre, nom.c_str())};

    return nombre;

}

string Biblioteca::getDireccionDeInternet(string direccionWeb)
{

    string direccionDeInternet = string {strcpy(this->direccionDeInternet, direccionWeb.c_str())};

    return direccionDeInternet;
}

string Biblioteca::getDireccionFisica(string direccionF)
{

    string direccionFisica = string {strcpy(this->direccionFisica, direccionF.c_str())};

    return direccionFisica;
}

string Biblioteca::getTelefono(string tel)
{

    string telefono = string {strcpy(this->telefono, tel.c_str())};

    return telefono;
}
