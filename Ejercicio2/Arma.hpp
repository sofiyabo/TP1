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
    int potenciaFija;


    public:
    ItemsMagicos(string nombre, vector<string> ataques, int cargaMaxima, int cargaMagica,  int potenciaFija); //Constructor general de items magicos
    void usar(shared_ptr<Personaje> enemigo) override; //de Arma, disminuye la carga magica, sin carga magica no se puede usar, potencia depende carga magica.
    void mostrar_info() override; //de Arma
    string get_nombre() override;
    int get_cargaMagica();
    int get_cargaMaxima();
    void recargarEnergia();
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

    ArmasdeCombate(string nombre, int potencia, string material) : nombre(nombre), potencia(potencia), material(material) {}
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
    Baston(int longitud, string elemento, string nombre="Baston", vector<string> ataques, int cargaMaxima = 75, int cargaMagica = 75,  int potenciaFija =10):
    ItemsMagicos(nombre, ataques, cargaMaxima, cargaMagica, potenciaFija), longitud(longitud), elemento(elemento) {}
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


    Amuleto(string nombre="Amuleto", vector<string> ataques, int cargaMaxima = 80, int cargaMagica = 80,  int potenciaFija =35, string tipo, int masVida, int masPotencia, bool inmunidad) : 
    ItemsMagicos(nombre, ataques, cargaMaxima, cargaMagica, potenciaFija), tipo(tipo), masVida(masVida), masPotencia(masPotencia), inmunidad(inmunidad){}
    
    void usar_vida(shared_ptr<Personaje> personaje); // despues de cada uso se destruye
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
    Pocion::Pocion(string efecto, int cantidadRestante = 100, string color, string nombre = "Poción", vector<string> ataques = {}, int cargaMaxima = 50, int cargaMagica = 50, int potencia = 0)
    : ItemsMagicos(nombre, ataques, cargaMaxima, cargaMagica, potencia), efecto(efecto), cantidadRestante(cantidadRestante), color(color) {}

    void tomar_pocion(); //Van a haber 2 tipos, osea dos efectos, 
    string get_efecto();
    int get_cantiadRestante();
    

};

class Espada : public ArmasdeCombate{

    private:
    int filo;
    string tipoFilo; //Curvo, triangular, cuadrado etc

    public:

    Espada::Espada(int filo, string tipoFilo, string nombre = "Espada", int potencia = 50, string material = "Hierro")
    : ArmasdeCombate(nombre, potencia, material), filo(filo), tipoFilo(tipoFilo) {}

    void afilar();
    string get_elemento();

};

class Garrote : public ArmasdeCombate{

    private:
    string elemento;
    int largo;

    public:

    Garrote::Garrote(string elemento, int largo = 50, string nombre = "Garrote", int potencia = 30, string material = "Madera")
    : ArmasdeCombate(nombre, potencia, material), elemento(elemento), largo(largo) {}

    string get_material();
    int get_largo();
    void mostrar_info() override;
};

class HachaDoble : public ArmasdeCombate{

    private:
    string tipoFilo1;
    string tipoFilo2;

    public:
    HachaDoble::HachaDoble(string tipoFilo1, string tipoFilo2, string nombre = "Hacha Doble", int potencia = 70, string material = "Acero")
    : ArmasdeCombate(nombre, potencia, material), tipoFilo1(tipoFilo1), tipoFilo2(tipoFilo2) {}

    string get_filos();
    void afilar(); //como la potencia va bajando, necesita afilar
    void mostrar_info() override;

};

class Lanza : public ArmasdeCombate{

    private:
    int cantidad;
    int alcance;
    
    public:
    
    Lanza::Lanza(int cantidad, int alcance, string nombre = "Lanza", int potencia = 40, string material = "Madera") // hace falta que los ponga aca si son fijos???
    : ArmasdeCombate(nombre, potencia, material), cantidad(cantidad), alcance(alcance) {}

    int get_cantidad();
    int get_alcance();
    void mostrar_info() override;
};

class HachaSimple : public ArmasdeCombate{
    
    private:
    float longitud; //la longitud puede determinar la potencia
    string tipoFilo;

    public:
    int get_tipoFilo();
    void afilar();
    void mostrar_info() override;

};

