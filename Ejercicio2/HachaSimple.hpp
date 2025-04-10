#pragma once 

#include "ArmasdeCombate.hpp"

class HachaSimple : public ArmasdeCombate{
    
    private:
    float longitud;
    string tipoFilo;

    public:
    int get_tipoFilo();
    void afilar();


};