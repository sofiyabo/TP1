#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Personaje.hpp"
#include "Arma.hpp"

using namespace std;

class PersonajeFactory{
    
    public:
    static shared_ptr<Personaje> crearPersonaje(string tipo);
    static shared_ptr<Arma> crearArma(string tipo);
    static shared_ptr<Personaje> crearPersonajeArmado(string tipo, string arma)

};

