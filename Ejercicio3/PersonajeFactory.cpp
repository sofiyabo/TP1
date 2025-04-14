#include <iostream>

#include "PersonajeFactory.hpp"
#include "Personaje.hpp"
#include "Armas.hpp"

//PODRIA HACER LAS PRIMERAS DOS PRIVADAS???

shared_ptr<Personaje> PersonajeFactory::crearPersonaje(string tipo){
    if (tipo == "Hechicero") {
        return std::make_shared<Hechicero>();
    }if (tipo == "Conjurador") {
        return std::make_shared<Conjurador>();
    }
    if (tipo == "Brujo") {
        return std::make_shared<Brujo>();
    } 
    if (tipo == "Nigromante") {
        return std::make_shared<Nigromante>();     
    }
    if (tipo == "Barbaro") {
        return std::make_shared<Barbaro>();
    }
    if (tipo == "Paladin") {
        return std::make_shared<Paladin>();
    } 
    if (tipo == "Caballero") {
        return std::make_shared<Caballero>();     
    }
    if (tipo == "Mercenario") {
        return std::make_shared<Mercenario>();
    } 
    if (tipo == "Gladiador") {
        return std::make_shared<Gladiador>();     
    }
    else{
        throw std::invalid_argument("Ingrese un personaje valido.");
    }

}

shared_ptr<Arma> PersonajeFactory::crearArma(string tipo){
    if (tipo == "Baston") {
        return std::make_shared<Baston>();
    }if (tipo == "LibrodeHechizos") {
        return std::make_shared<LibrodeHechizos>();
    }
    if (tipo == "Amuleto") {
        return std::make_shared<Amuleto>();
    } 
    if (tipo == "Pocion") {
        return std::make_shared<Pocion>();     
    }
    if (tipo == "Espada") {
        return std::make_shared<Espada>();
    }
    if (tipo == "Garrote") {
        return std::make_shared<Garrote>();
    } 
    if (tipo == "HachaDoble") {
        return std::make_shared<HachaDoble>();     
    }
    if (tipo == "Lanza") {
        return std::make_shared<Lanza>();
    } 
    if (tipo == "HachaSimple") {
        return std::make_shared<HachaSimple>();     
    }


}

shared_ptr<Personaje> PersonajeFactory::crearPersonajeArmado(string tipo_personaje, vector<string> armas){
    shared_ptr<Personaje> personaje = crearPersonaje(tipo_personaje);

    for(const string& tipo_arma : armas){
        shared_ptr<Arma> arma = crearArma(tipo_arma);
        personaje->agregar_arma(arma)
    }
    return personaje;
}

