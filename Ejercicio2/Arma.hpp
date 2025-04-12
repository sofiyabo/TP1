#pragma once

#include "Personaje.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;



class Arma {
    
    public:
    virtual void usar(shared_ptr<Personaje> enemigo) = 0; //da el golpe
    virtual string get_nombre()=0;
    virtual void mostrar_info() = 0;
    
    
};

class ItemsMagicos : public Arma{
    
    protected:
    string nombre;
    vector<string> ataques;
    int cargaMaxima; //carga maxima de magia
    int cargaMagica;
    int potencia;


    public:
    void usar(shared_ptr<Personaje> enemigo) override; //de Arma
    void mostrar_info() override; //de Arma
    string get_nombre() override;
    int get_cargaMagica();
    int get_cargaMaxima();
    //void elegir_ataque();
    //void recargar_magia(); //virtual o general? porque cada arma tiene niveles maximos de magia
    //Cada ataque baja el nivel de magia, y se puede recargar solo si ya se gasto la mitad. 


};   

class ArmasdeCombate : public Arma{
    
    protected:
    string nombre;
    int potencia;
    string material;


    public:
    string get_nombre() override;
    void usar(shared_ptr<Personaje> enemigo) override; //de Arma
    void mostrar_info() override; //de Arma
    void restaurar();

};

class Baston : public ItemsMagicos{
    
    private:
    int longitud;
    string elemento;

    public:
    Baston();
    string get_elemento();
    int get_longitud();
    

};

class LibrodeHechizos : public ItemsMagicos{
    
    private:
    int paginaActual;
    string tipo_libro;
    vector<string> hechizos;

    public:
    void leer_hechizo();
    void cambiar_pagina(int pag);
    void usar_hechizo(); //no se si hace falta
    
};

class Amuleto : public ItemsMagicos{
    
    private:
    string tipo;
    int masVida;
    int masPotencia;
    bool inmunidad;

    public:
    void usar_vida(shared_ptr<Personaje> personaje);
    void usar_potencia(shared_ptr<Personaje> personaje);
    void usar_inmunidad(shared_ptr<Personaje> personaje);
    string get_tipo();

};

class Pocion : public ItemsMagicos{
    
    private:
    string efecto;
    int cantidadRestante;
    string color;
    
    public:
    Pocion();
    void tomar_pocion();
    string get_efecto();
    int get_cantiadRestante();
    

};

class Espada : public ArmasdeCombate{

    private:
    int filo;
    string elemento;

    public:
    void afilar();
    string get_elemento();

};

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

class HachaDoble : public ArmasdeCombate{

    private:
    string tipoFilo1;
    string tipoFilo2;

    public:
    string get_filos();
    void afilar(); //como la potencia va bajando, necesita afilar
    void usar() override;
    void mostrar_info() override;

};

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

