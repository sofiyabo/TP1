#include "Arma.hpp"

void ItemsMagicos::usar(shared_ptr<Personaje> enemigo) {
    if(auto guerrero = dynamic_pointer_cast<Guerreros>(enemigo)){
        guerrero->vida = guerrero->vida - potencia;
    }else if
    (auto mago = dynamic_pointer_cast<Guerreros>(enemigo)){
        mago->vida = guerrero->vida - potencia;
    }
    return;
} 
void ItemsMagicos::mostrar_info() {
    cout<<
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

void ItemsMagicos::elegir_ataque(){}

void ArmasdeCombate::usar(shared_ptr<Personaje> enemigo){
    if(auto guerrero = dynamic_pointer_cast<Guerreros>(enemigo)){
        guerrero->vida = guerrero->vida - potencia;
    }else if
    (auto mago = dynamic_pointer_cast<Guerreros>(enemigo)){
        mago->vida = guerrero->vida - potencia;
    }
    return;

} //de Arma

string ArmasdeCombate::get_nombre(){
    return nombre;
}

void ArmasdeCombate::mostrar_info(){} //de Arma

void ArmasdeCombate::restaurar(){}

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


void Amuleto::usar_vida(shared_ptr<Personaje> personaje){
    if(auto guerrero = dynamic_pointer_cast<Guerreros>(personaje)){
        if()
    }else if
    (auto mago = dynamic_pointer_cast<Guerreros>([personaje])){
        mago->vida = guerrero->vida - potencia;
    }
    return;
}

void Amuleto::usar_potencia(shared_ptr<Personaje> personaje){}

void Amuleto::usar_inmunidad(shared_ptr<Personaje> personaje){}

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

string Espada::get_elemento(){
    return elemento;
}


string Garrote::get_material(){
    return material;
}

int Garrote::get_largo(){
    return largo;
}


string HachaDoble::get_filos(){
    
    string filos = "Filo 1: ", tipoFilo1, ", Filo 2: ", tipoFilo2<< ".\n"<< endl;
    
    return
}

void HachaDoble::afilar(){}


int Lanza::get_cantidad(){}

int Lanza::get_alcance(){}


int HachaSimple::get_tipoFilo(){}

void HachaSimple::afilar(){}