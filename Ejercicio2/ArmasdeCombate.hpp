#pragma once

#include "Arma.hpp"

class ArmasdeCombate : public Arma{
    
    protected:
    string nombre;
    int potencia;
    string material;


    public:
    void usar() override; //de Arma
    void mostrar_info() override; //de Arma
    void restaurar();

    
};