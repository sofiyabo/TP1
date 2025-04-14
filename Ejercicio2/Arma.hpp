#pragma once

#include "Personaje.hpp"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;



class Arma {
    
    public:
    virtual int usar(); //devuelve el dano que se le va a hacer al enemigo
    virtual string get_nombre()=0;
    virtual void mostrar_info() = 0;
    
    
};

class ItemsMagicos : public Arma{
    
    protected:
    string nombre;
    vector<string> ataques;
    int cargaMaxima; //carga maxima de magia
    int cargaMagica;
    int potenciaFija;


    public:
    ItemsMagicos(string nombre, vector<string> ataques, int cargaMaxima, int cargaMagica,  int potenciaFija); //Constructor general de items magicos
    int usar() override; //de Arma, disminuye la carga magica, sin carga magica no se puede usar, potencia depende carga magica.
    void mostrar_info() override; //de Arma
    string get_nombre() override;
    int get_cargaMagica();
    int get_cargaMaxima();
    void recargarMagia();


};   

class ArmasdeCombate : public Arma{
    
    protected:
    string nombre;
    int potencia;
    string material;


    public:

    ArmasdeCombate(string nombre, int potencia, string material) : nombre(nombre), potencia(potencia), material(material) {}
    string get_nombre() override;
    int usar() override; //de Arma
    void mostrar_info() override; //de Arma

};

class Baston : public ItemsMagicos{
    
    private:
    int longitud;
    string elemento;

    public:
    Baston() : ItemsMagicos("Baston", {}, 75, 75, 10), longitud(30), elemento("Pinches") {}
    string get_elemento();
    int get_longitud();
    

};

class LibrodeHechizos : public ItemsMagicos{
    
    private:
    int paginaActual;
    string tipo_libro;
    vector<string> hechizos;

    public:

    LibrodeHechizos(int paginaActual = 0, string tipoLibro, vector<string> hechizos, string nombre="Libro de Hechizos", vector<string> ataques = {"Hechizos"}, int cargaMaxima = 90, int cargaMagica = 90,  int potenciaFija =25) : 
    ItemsMagicos(nombre, ataques, cargaMaxima, cargaMagica, potenciaFija), paginaActual(paginaActual), tipo_libro(tipoLibro), hechizos(hechizos){}
    
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


    Amuleto() : ItemsMagicos("Amuleto", {}, 80, 80, 35), tipo("Especial"), masVida(20), masPotencia(35), inmunidad(true){}
    
    int usar_vida(); // despues de cada uso se destruye
    int usar_potencia();
    bool usar_inmunidad();
    string get_tipo();


};

class Pocion : public ItemsMagicos{
    
    private:
    string efecto;
    int cantidadRestante;
    
    public:
    Pocion::Pocion()
    : ItemsMagicos("Pocion", {}, 50, 50, 0), efecto("Invisibilidad"), cantidadRestante(100) {}

    void tomar_pocion(); //Van a haber 2 tipos, osea dos efectos, 
    string get_efecto();
    int get_cantiadRestante();
    

};

class Espada : public ArmasdeCombate{

    private:
    string tipoFilo; //Curvo, triangular, cuadrado etc

    public:

    Espada::Espada() : ArmasdeCombate("Espada", 50, "Hierro"), tipoFilo("") {}

    void afilar();
    string get_filo();

};

class Garrote : public ArmasdeCombate{

    private:
    string elemento;
    int largo;

    public:

    Garrote::Garrote() : ArmasdeCombate("Garrote", 30, "Madera"), elemento("Fuego"), largo(40) {}

    string get_material();
    int get_largo();
    void mostrar_info() override;
};

class HachaDoble : public ArmasdeCombate{

    private:
    string tipoFilo1;
    string tipoFilo2;

    public:
    HachaDoble::HachaDoble() : ArmasdeCombate("Hacha Doble", 70, "Acero"), tipoFilo1("Curvo"), tipoFilo2("Triangular") {}

    string get_filos();
    void afilar(); //como la potencia va bajando, necesita afilar
    void mostrar_info() override;

};

class Lanza : public ArmasdeCombate{

    private:
    int cantidad;
    int alcance; //en metros
    
    public:
    
    Lanza::Lanza() : ArmasdeCombate("Lanza", 40, "Madera"), cantidad(8), alcance(10) {}

    int get_cantidad();
    int get_alcance();
    void mostrar_info() override;
};

class HachaSimple : public ArmasdeCombate{
    
    private:
    float longitud; //la longitud puede determinar la potencia
    string tipoFilo;

    public:

    HachaSimple() : ArmasdeCombate("Hacha Simple", 50, "Metal"), longitud(50.5), tipoFilo("Curvo") {}

    int get_tipoFilo();
    void afilar();
    void mostrar_info() override;

};

