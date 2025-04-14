#include "Arma.hpp"

int ItemsMagicos::usar() {

    return;
} 

void ItemsMagicos::mostrar_info() {

} //de Arma

string ItemsMagicos::get_nombre(){
    return nombre;
}

int ItemsMagicos::get_cargaMagica(){
    return cargaMagica;
}

int ItemsMagicos::get_cargaMaxima(){
    return cargaMaxima;
}


int ArmasdeCombate::usar(){


} //de Arma

string ArmasdeCombate::get_nombre(){
    return nombre;
}

void ArmasdeCombate::mostrar_info(){} //de Arma



string Baston::get_elemento(){
    return elemento;
}
int Baston::get_longitud(){
    return longitud;
}

void LibrodeHechizos::leer_hechizo(){
    cout << hechizos[paginaActual] << endl;
}

void LibrodeHechizos::cambiar_pagina(int pag){
    paginaActual = pag;
}

void LibrodeHechizos::usar_hechizo(){} //lo quiero? tendria que tener potencia particular


int Amuleto::usar_vida(){

}

int Amuleto::usar_potencia(){}

bool Amuleto::usar_inmunidad(){}

string Amuleto::get_tipo(){
    return tipo;
}


void Pocion::tomar_pocion(){}

string Pocion::get_efecto(){
    return efecto;
}

int Pocion::get_cantiadRestante(){
    return cantidadRestante;
}


void Espada::afilar(){}

string Espada::get_filo(){
    return tipoFilo;
}


string Garrote::get_material(){
    return material;
}

int Garrote::get_largo(){
    return largo;
}


string HachaDoble::get_filos(){
    

    return;
}

void HachaDoble::afilar(){}


int Lanza::get_cantidad(){}

int Lanza::get_alcance(){}


int HachaSimple::get_tipoFilo(){}

void HachaSimple::afilar(){}