#include "Arma.hpp"

//Metodos de ItemsMagicos
void ItemsMagicos::setPotencia(int cantidad){
    potenciaFija+= cantidad;

}

float ItemsMagicos::usar() {
    float restar = (potenciaFija + cargaMagica) / 10;

    return restar;
} 

string ItemsMagicos::get_nombre(){
    return nombre;
}

void ItemsMagicos::mostrar_info() {
    cout<< "Nombre: " << nombre << ", Carga Magica: " << cargaMagica << "."<<endl;

} 

int ItemsMagicos::get_cargaMagica(){
    return cargaMagica;
}

int ItemsMagicos::get_cargaMaxima(){
    return cargaMaxima;
}

void ItemsMagicos::recargarMagia(){
    cargaMagica = cargaMaxima;
}

//Metodos de ArmasdeCombate
void ArmasdeCombate::setPotencia(int cantidad){
    potencia+= cantidad;

}

float ArmasdeCombate::usar(){
    float restar = potencia / 10;

    return restar;
} 

string ArmasdeCombate::get_nombre(){
    return nombre;
}

//Derivadas de ItemsMagicos
string Baston::get_elemento(){
    return elemento;
}

int Baston::get_longitud(){
    return longitud;
}

void Baston::mostrar_info() {
    cout << "El Baston es del elemento "<<elemento<<" tiene longitud "<< longitud;
}

void LibrodeHechizos::leer_hechizo(){
    cout << hechizos[paginaActual] << endl;
}

void LibrodeHechizos::cambiar_pagina(int pag){
    paginaActual = pag;
}

void LibrodeHechizos::mostrar_info() {
    cout << "El Libro de Hechizos es de tipo "<<tipo_libro<< "y esta abierto en la pagina "<<paginaActual;
}

int Amuleto::usar_vida(){
    return masVida;
}

int Amuleto::usar_potencia(){
    return masPotencia;
}

string Amuleto::get_tipo(){
    return tipo;
}

void Amuleto::mostrar_info() {
    cout << "El Amuleto es "<<tipo<<", Adicional Vida = "<< masVida<< " , Adicional Potencia = "<<masPotencia;
}

void Pocion::tomar_pocion(){
    if(cantidadRestante>=10)
    {   cout<< "Ahora tienes el poder de "<< efecto<< " y ha disminuido la cantidad restante (-10)"<<endl;
        cantidadRestante-=10;
    }
    else{
        cout<< "No tiene la cantidad restante necesaria."<< endl;
    }

}

string Pocion::get_efecto(){
    return efecto;
}

int Pocion::get_cantidadRestante(){
    return cantidadRestante;
}

void Pocion::mostrar_info() {
    cout << "La pocion tiene efecto de "<<efecto<<", le queda cantidad restante = "<<cantidadRestante;
}


//Derivadas de ArmasdeCombate
string Espada::get_filo(){
    return tipoFilo;
}

string Garrote::get_elemento(){
    return elemento;
}

int Garrote::get_largo(){
    return largo;
}

string HachaDoble::get_filos(){

    return tipoFilo1;
}

int Lanza::get_cantidad(){
    return cantidad;
}

int Lanza::get_alcance(){
    return alcance;
}

string HachaSimple::get_tipoFilo(){
    return tipoFilo;
}

//Las armas de combate tambien tienen como metodo virtual puro mostrar_info()

void Espada::mostrar_info() {
    cout << "La espada tiene el filo "<<tipoFilo<<" y un largo de "<< largo<< "cm.";
}

void Garrote::mostrar_info() {
    cout << "El garrote es de elemento "<<elemento<<" y tiene un largo de "<< largo<< "cm.";
}

void HachaDoble::mostrar_info() {
    cout << "Los dos tipos de filos del Hacha Doble son "<<tipoFilo1<<" y "<< tipoFilo2<<".";
}

void Lanza::mostrar_info() {
    cout << "Tenes "<<cantidad<<" de lanzas disponibles, con un alcance de "<< alcance<< "m";
}

void HachaSimple::mostrar_info() {
    cout << "El Hacha Simple mide "<<longitud<<"cm y su tipo de filo es "<<tipoFilo;
}