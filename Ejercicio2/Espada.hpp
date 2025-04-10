#pragma once 

#include "ArmasdeCombate.hpp"

class Espada : public ArmasdeCombate{

    private:
    int filo;
    string elemento;

    public:
    void afilar();
    string get_elemento();
    void usar() override;
    void mostrar_info() override;

};