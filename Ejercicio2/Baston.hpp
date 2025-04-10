#pragma once

#include "ItemsMagicos.hpp"

class Baston : public ItemsMagicos{
    
    private:
    int longitud;
    string elemento;

    public:
    Baston();
    string get_elemento();
    int get_longitud();
    

};