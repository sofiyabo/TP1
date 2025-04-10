#pragma once 

#include "ArmasdeCombate.hpp"

class HachaDoble : public ArmasdeCombate{

    private:
    string tipoFilo1;
    string tipoFilo2;

    public:
    string get_filos();
    void afilar(); //como la potencia va bajando, necesita afilar

};