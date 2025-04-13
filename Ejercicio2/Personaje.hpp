#pragma once 

#include "Arma.hpp"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Personaje{

    //SE PUEDEN AGREGAR ELEGIR ARMA Y AGREGAR ARMA
    public:
    virtual void mostrarInfo();
    virtual void GolpeRapido(int potencia);
    virtual void GolpeFuerte(int potencia);
    virtual void DefensaYGolpe(int potencia);
    virtual void get_vida(); //NO IMPLEMENTADO
    virtual void agregar_arma(shared_ptr<Arma> arma) = 0;
};

class Magos : public Personaje{

    private:
    string tipo;
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; //ver si hacer puntero a clase abstracta o a arma
    shared_ptr<Arma> arma_actual;

    protected:
    int vida;

    public:


    Magos(string tipo, vector<shared_ptr<Arma>> armas_combate, vector<shared_ptr<Arma>> armas_magicas, int vida);
    void agregar_arma(shared_ptr<Arma> arma) override;
    void elegir_arma(string nombre); // pone al arma como arma actual
    string get_tipo();
    void mostrarInfo() override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    void GolpeRapido() override;
    void GolpeFuerte() override;
    void DefensaYGolpe() override;

};

class Guerreros : public Personaje{

    private:
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; //ver si hacer puntero a clase abstracta o a arma
    string nombre;
    //agregar bool inmune??

    shared_ptr<Arma> arma_actual;


    public:
    int vida;

    void elegir_arma(string nombre);
    string get_nombre();
    void mostrarInfo() override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    void GolpeRapido() override;
    void GolpeFuerte() override;
    void DefensaYGolpe() override;

};

class Hechicero : public Magos{

    private:
    string tipo;

    public:


};

class Conjurador : public Magos{


};

class Brujo : public Magos{


};

class Nigromante : public Magos{

};

class Barbaro : public Guerreros{

};

class Paladin : public Guerreros{

};

class Caballero : public Guerreros{

};

class Mercenario : public Guerreros{

};

class Gladiador : public Guerreros{

};