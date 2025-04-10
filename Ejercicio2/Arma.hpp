#pragma once

#include <iostream>
#include <memory>

using namespace std;

class Personaje;

// Interfaz; todos metodos virtuales, osea que todas las derivadas implementan


class Arma {
    
    public:
    virtual void usar() = 0; //al personaje se la asigna como arma actual
    virtual void mostrar_info() = 0;
    
    

};