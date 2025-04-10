#pragma once 

#include "ArmasdeCombate.hpp"

class Garrote : public ArmasdeCombate{

    private:
    string material;
    int largo;

    public:
    string get_material();
    int get_largo();
    void usar() override;
    void mostrar_info() override;
};