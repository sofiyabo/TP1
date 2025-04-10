#pragma once 

#include "ArmasdeCombate.hpp"

class Lanza : public ArmasdeCombate{

    private:
    int cantidad;
    int alcance;
    
    public:
    int get_cantidad();
    int get_alcance();
    void usar() override;
    void mostrar_info() override;
};