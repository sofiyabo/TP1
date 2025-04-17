#pragma once

#include <iostream>
#include <memory>
#include <vector>

using namespace std;



class Arma {
    
    public:
    virtual float usar()=0; //devuelve el dano que se le va a hacer al enemigo
    virtual string get_nombre()=0;
    virtual void setPotencia(int cantidad)= 0;
    
};

class ItemsMagicos : public Arma{
    
    private:
    string nombre;
    vector<string> ataques;
    int cargaMaxima;
    int cargaMagica;
    int potenciaFija;


    public:
    ItemsMagicos(string nombre, vector<string> ataques, int cargaMaxima, int cargaMagica,  int potenciaFija) :
    Arma(), nombre(nombre), ataques(ataques), cargaMaxima(cargaMaxima), cargaMagica(cargaMagica), potenciaFija(potenciaFija) {} //Constructor general de items magicos
    ~ItemsMagicos(){}
    virtual void mostrar_info()=0;

    float usar() override; 

    string get_nombre() override;
    void setPotencia(int cantidad) override;
    int get_cargaMagica();
    int get_cargaMaxima();
    void recargarMagia();


};   

class ArmasdeCombate : public Arma{
    
    private:
    string nombre;
    int potencia;
    string material;


    public:

    ArmasdeCombate(string nombre, int potencia, string material) : Arma(), nombre(nombre), potencia(potencia), material(material) {}
    ~ArmasdeCombate(){}
    void setMaterial(string nuevoMaterial);
    virtual void mostrar_info()=0;


    float usar() override; 
    void setPotencia(int cantidad) override;
    string get_nombre() override;


};

class Baston : public ItemsMagicos{
    
    private:
    int longitud;
    string elemento;

    public:
    Baston() : ItemsMagicos("Baston", {}, 75, 75, 10), longitud(30), elemento("Pinches") {}
    ~Baston(){}

    void mostrar_info() override;
    string get_elemento();
    int get_longitud();
    

};

class LibrodeHechizos : public ItemsMagicos{
    
    private:
    int paginaActual;
    string tipo_libro;
    vector<string> hechizos;

    public:

    LibrodeHechizos() : 
    ItemsMagicos("Libro de Hechizos", {}, 90, 90, 25), paginaActual(0), tipo_libro("Libro oscuro"), hechizos({"Lianas crecen del piso del enemigo, atandole los pies a la tierra sin poder moverse.", "Un rayo del cielo le quita 15 HP a tu enemigo.", "El ataque de tu enemigo rebota y lo golpea a el."}){}
    
    void mostrar_info() override;
    void leer_hechizo();
    void cambiar_pagina(int pag);
    
};

class Amuleto : public ItemsMagicos{
    
    private:
    string tipo;
    int masVida;
    int masPotencia;

    public:
    Amuleto() : ItemsMagicos("Amuleto", {}, 80, 80, 35), tipo("Especial"), masVida(20), masPotencia(35) {}
    ~Amuleto(){}
    
    void mostrar_info() override;
    int usar_vida();
    int usar_potencia();
    string get_tipo();


};

class Pocion : public ItemsMagicos{
    
    private:
    string efecto;
    int cantidadRestante;
    
    public:
    Pocion()
    : ItemsMagicos("Pocion", {}, 50, 50, 0), efecto("Invisibilidad"), cantidadRestante(100) {}
    ~Pocion(){}

    void mostrar_info() override;
    void tomar_pocion(); 
    string get_efecto();
    int get_cantidadRestante();
    

};

class Espada : public ArmasdeCombate{

    private:
    string tipoFilo;
    int largo; //Curvo, triangular, cuadrado etc

    public:

    Espada() : ArmasdeCombate("Espada", 50, "Hierro"), tipoFilo("Triangular"), largo(27) {}
    ~Espada(){}
    void mostrar_info() override;

    string get_filo();

};

class Garrote : public ArmasdeCombate{

    private:
    string elemento;
    int largo;

    public:

    Garrote() : ArmasdeCombate("Garrote", 30, "Madera"), elemento("Fuego"), largo(40) {}
    ~Garrote(){}
    void mostrar_info() override;

    string get_elemento();
    int get_largo();
};

class HachaDoble : public ArmasdeCombate{

    private:
    string tipoFilo1;
    string tipoFilo2;

    public:
    HachaDoble() : ArmasdeCombate("Hacha Doble", 70, "Acero"), tipoFilo1("Curvo"), tipoFilo2("Triangular") {}
    ~HachaDoble(){}
    void mostrar_info() override;

    string get_filos();

};

class Lanza : public ArmasdeCombate{

    private:
    int cantidad;
    int alcance; 
    
    public:
    Lanza() : ArmasdeCombate("Lanza", 40, "Madera"), cantidad(8), alcance(10) {}
    void mostrar_info() override;

    int get_cantidad();
    int get_alcance();
};

class HachaSimple : public ArmasdeCombate{
    
    private:
    float longitud; 
    string tipoFilo;

    public:
    HachaSimple() : ArmasdeCombate("Hacha Simple", 50, "Metal"), longitud(50.5), tipoFilo("Curvo") {}
    void mostrar_info() override;

    string get_tipoFilo();
};

