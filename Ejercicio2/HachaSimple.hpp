#pragma once 

#include "ArmasdeCombate.hpp"

class HachaSimple : public ArmasdeCombate{
    
    private:
    float longitud; //la longitud puede determinar la potencia
    string tipoFilo;

    public:
    int get_tipoFilo();
    void afilar();
    void usar() override;
    void mostrar_info() override;

};