#ifndef EXECPCIONESTIENDA_H
#define EXECPCIONESTIENDA_H

#include "excepcionesProducto.h"
#include <exception>
#include <iostream>

using namespace std;

class ExcepcionNombreTienda : public exception{

    public:
    ExcepcionNombreTienda() noexcept = default;
    ~ExcepcionNombreTienda() = default;

    virtual const char* what() const noexcept {
        return "Ingrese un nombre valido. El nombre de la tienda no debe ser 0 ni exceder los 15 caracteres.";
    }
};

class ExcepcionDireccionInternet : public exception{

    public:

    ExcepcionDireccionInternet() noexcept = default;
    ~ExcepcionDireccionInternet() = default;

    virtual const char* what() const noexcept {
        return "Ingrese una direccion valida. La direccion web no debe ser 0 ni exceder los 20 caracteres.";
    }
};

class ExcepcionDireccionFisica : public exception{

    public:

    ExcepcionDireccionFisica() noexcept = default;
    ~ExcepcionDireccionFisica() = default;

    virtual const char* what() const noexcept {
        return "Ingrese una direccion valida. La direccion fisica no debe ser 0 ni exceder los 24 caracteres.";
    }
};

class ExcepcionTelefono : public exception{

    public:

    ExcepcionTelefono() noexcept = default;
    ~ExcepcionTelefono() = default;

    virtual const char* what() const noexcept {
        return "Ingrese un telefono valido. Debe contener 8 caracteres.";
    }
};

class ExcepcionNegativo : public exception{

    public:
    ExcepcionNegativo() noexcept = default;
    ~ExcepcionNegativo() = default;

    virtual const char* what() const noexcept {

        return "No hay productos con IDs iguales o menores que cero";
        
    }
};

#endif