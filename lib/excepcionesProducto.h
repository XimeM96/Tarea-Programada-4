#ifndef ExcepcionesProducto_H
#define ExcepcionesProducto_H

#include <exception>
#include <iostream>

using namespace std;

class ExcepcionNombreProductoInvalido : public exception{

    public:

        ExcepcionNombreProductoInvalido() noexcept = default;
        ~ExcepcionNombreProductoInvalido() = default;

    virtual const char* what() const noexcept {
        return "Ingrese un nombre valido. El nombre del producto no debe ser 0 ni exceder los 20 caracteres.";
    }

};

class ExcepcionIDProducto : public exception{

    public:

    ExcepcionIDProducto() noexcept = default;
    ~ExcepcionIDProducto() = default;

    virtual const char* what() const noexcept {
        return "No es permitido ingresar numero igual o menores a cero en los ID de los productos.";
    }

};

class ExcepcionExistenciasDisponibles : public exception{

    public:

    ExcepcionExistenciasDisponibles() noexcept = default;
    ~ExcepcionExistenciasDisponibles() = default;

    virtual const char* what() const noexcept {
        return "No es permitido ingresar numeros negativos para las existencias disponibles.";
    }

};

#endif