#pragma once

#include "Arma.hpp"
#include <iostream>
#include <vector>
using namespace std;

//Clase abstracta de Arma
class ItemsMagicos : public Arma{
    
    protected:
    //NO SE SI ME SIRVE vector<string> ataques; // tipos de ataque que tiene el arma
    string nombre;
    vector<string> ataques;
    int cargaMaxima; //carga maxima de magia
    int cargaMagica;


    public:
    void usar() override; //de Arma
    void mostrar_info() override; //de Arma
    int get_cargaMagica();
    int get_cargaMagica();
    void elegir_ataque();
    //void recargar_magia(); //virtual o general? porque cada arma tiene niveles maximos de magia
    //Cada ataque baja el nivel de magia, y se puede recargar solo si ya se gasto la mitad. 



};