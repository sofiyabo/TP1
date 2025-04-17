#include <iostream>

#include "PersonajeFactory.hpp"
#include "Personaje.hpp"
#include "Arma.hpp"

using namespace std;

//Recibe el nombre del personaje y crea un shared_ptr a el
shared_ptr<Personaje> PersonajeFactory::crearPersonaje(string tipo){
    if (tipo == "Hechicero") {
        return make_shared<Hechicero>();
    }if (tipo == "Conjurador") {
        return make_shared<Conjurador>();
    }
    if (tipo == "Brujo") {
        return make_shared<Brujo>();
    } 
    if (tipo == "Nigromante") {
        return make_shared<Nigromante>();     
    }
    if (tipo == "Barbaro") {
        return make_shared<Barbaro>();
    }
    if (tipo == "Paladin") {
        return make_shared<Paladin>();
    } 
    if (tipo == "Caballero") {
        return make_shared<Caballero>();     
    }
    if (tipo == "Mercenario") {
        return make_shared<Mercenario>();
    } 
    if (tipo == "Gladiador") {
        return make_shared<Gladiador>();     
    }
    else{
        throw invalid_argument("Ingrese un personaje valido.");
    }

}

//Devuelve un shared_ptr a un arma, y luego a este puntero se le hace pushback en las armas del personaje (conserva composicion)
shared_ptr<Arma> PersonajeFactory::crearArma(string tipo){
    if (tipo == "Baston") {
        return make_shared<Baston>();
    }if (tipo == "LibrodeHechizos") {
        return make_shared<LibrodeHechizos>();
    }
    if (tipo == "Amuleto") {
        return make_shared<Amuleto>();
    } 
    if (tipo == "Pocion") {
        return make_shared<Pocion>();     
    }
    if (tipo == "Espada") {
        return make_shared<Espada>();
    }
    if (tipo == "Garrote") {
        return make_shared<Garrote>();
    } 
    if (tipo == "HachaDoble") {
        return make_shared<HachaDoble>();     
    }
    if (tipo == "Lanza") {
        return make_shared<Lanza>();
    } 
    if (tipo == "HachaSimple") {
        return make_shared<HachaSimple>();     
    }
    else{
        throw invalid_argument("Ingrese un arma valida.");
    }


}

shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(string tipo_personaje, vector<string> armas){
    shared_ptr<Personaje> personaje = crearPersonaje(tipo_personaje);

    for(const string& tipo_arma : armas){
        shared_ptr<Arma> arma = crearArma(tipo_arma);
        personaje->agregar_arma(arma);
    }
    return personaje;
}

