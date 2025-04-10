#pragma once 
#include <iostream>


/*

Metodos:
    Cambiar arma: da las opciones de armas
    Agregar arma:
    get vida
    get nombre

*/

class Personaje{

    public:
    virtual void mostrarInfo();
    virtual void GolpeRapido();
    virtual void GolpeFuerte();
    virtual void DefensaYGolpe();


};