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
    virtual void elegir_arma(string nombre);
    virtual void get_vida(); //NO IMPLEMENTADO
    virtual void agregar_arma(shared_ptr<Arma> arma);
    virtual void restarVida(int cantidad);
    virtual string get_nombre();

    virtual void GolpeRapido(int potencia);
    virtual void GolpeFuerte(int potencia);
    virtual void DefensaYGolpe(int potencia);
};

class Magos : public Personaje{

    private:
    string nombre;
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; //ver si hacer puntero a clase abstracta o a arma
    shared_ptr<Arma> arma_actual;

    protected:
    int vida;

    public:

    Magos(string nombre) : nombre(nombre), armas_combate({}), armas_magicas({}), vida(100), arma_actual(nullptr) {}
    
    void elegir_arma(string nombre); // pone al arma como arma actual
    string get_nombre() override;
    void mostrarInfo() override;
    void restarVida(int cantidad) override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    
/*
    void GolpeRapido() override;
    void GolpeFuerte() override;
    void DefensaYGolpe() override;
*/
};

class Guerreros : public Personaje{

    private:
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; 
    string nombre;
    shared_ptr<Arma> arma_actual;

    public:
    int vida;

    Guerreros(string nombre) : armas_combate({}), armas_magicas({}), nombre(nombre), arma_actual(nullptr) {}
    void elegir_arma(string nombre) override;
    string get_nombre() override;
    void mostrarInfo() override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    void restarVida(int cantidad) override;
    /*
    void GolpeRapido() override;
    void GolpeFuerte() override;
    void DefensaYGolpe() override;
    */
};

//TANTO PARA ARMAS COMO PERSONAJES, van a haber tipos fijos de cada uno, aunque potencialmente se podrian hacer muchos diferentes

class Hechicero : public Magos{

    private:
    string tipo;
    int nivelMagia;

    public:

    Hechicero() : Magos("Mago"), tipo("Sabio"){}
    void hechizar();
    void masMagia();


};

class Conjurador : public Magos{
    private:
    vector<string> conjuros;
    string tipo;

    public:

    Conjurador() : Magos("Conjurador"), conjuros({}) {}
    void usarConjuro();
    void getTipo();


};

class Brujo : public Magos{
    
    private:
    string poder;

    public:

    Brujo() : Magos("Brujo"), poder("Volar") {}

};

class Nigromante : public Magos{

    private:
    int eficaciaComunicacion;

    public:

    Nigromante() : Magos("Nigromante"), eficaciaComunicacion(75){}

};

class Barbaro : public Guerreros{

    private:
    int resistencia;

    public:

    Barbaro() : Guerreros("Barbaro"), resistencia(50) {}

};

class Paladin : public Guerreros{
    private:
    string habilidad;

    public:
    Paladin() : Guerreros("Paladin"), habilidad("Teletransportacion") {}
    void getHabilidad();

};

class Caballero : public Guerreros{
    private:
    int honor;

    public:

    Caballero() : Guerreros("Caballero"), honor(65) {}

};

class Mercenario : public Guerreros{
    private:
    string especialidad;

    public:

    Mercenario() : Guerreros("Mercenario"), especialidad("Hachas"){}

};

class Gladiador : public Guerreros{
    private:
    string estilo;

    public:

    Gladiador() : Guerreros("Gladiador"), estilo("Defensivo") {}
};