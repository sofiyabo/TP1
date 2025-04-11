#pragma once

#include "Personaje.hpp"
#include "Arma.hpp"
#include <memory>
#include <vector>


class Guerreros : public Personaje{

    private:
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; //ver si hacer puntero a clase abstracta o a arma

    public:
    void agregar_arma();
    void elegir_arma();
    void mostrarInfo() override;
    void GolpeRapido() override;
    void GolpeFuerte() override;
    void DefensaYGolpe() override;

};