#pragma once

#include "ItemsMagicos.hpp"

class Pocion : public ItemsMagicos{
    
    private:
    string efecto;
    int cantidadRestante;
    string color;
    
    public:
    Pocion();
    void tomar_pocion();
    string get_efecto();
    int get_cantiadRestante();
    

};