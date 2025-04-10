#pragma once
#include "ItemsMagicos.hpp"

//Un amuleto le va a traer mejoras al personaje en diferentes aspectos
class Amuleto : public ItemsMagicos{
    
    private:
    string tipo;
    int masVida;
    int masPotencia;
    bool inmunidad;

    public:
    void usar_vida();
    void usar_potencia();
    void usar_inmunidad();
    string get_tipo();

};