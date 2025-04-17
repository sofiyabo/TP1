#include <iostream>
#include "../PersonajeFactory.hpp"

using namespace std;


const vector<string> magos = {"Nigromante", "Hechicero", "Conjurador", "Brujo"};
const vector<string> guerreros = {"Gladiador", "Mercenario", "Caballero", "Paladin", "Barbaro"};
const vector<string> armasFijas = {"Espada", "HachaDoble", "Lanza", "HachaSimple", "LibrodeHechizos", "Baston", "Amuleto", "Pocion", "Garrote"};



int main(){
    
    srand(time(nullptr)); //Semilla para la funcion rand()

    int cantMagos = 3 + (rand() % (7 - 3 + 1));  //Minimo 3, maximo 7  
    cout<< "Cantidad de Magos a crear: " << cantMagos << endl;
    int cantGuerreros = 3 + (rand() % (7 - 3 + 1));
    cout<< "Cantidad de Guerreros a crear: " << cantGuerreros << endl;    

    vector<shared_ptr<Personaje>> personajes;

    for(int i = 0; i<cantMagos; i++){
        
        string tipo_mago = magos[rand() % magos.size()];

        int cantArmas = rand() % 3; // cant random de armas que va a tener el mago
        vector<string> armas;

        for(int j = 0; j < cantArmas; j++){
            string tipo_arma = armasFijas[rand() % armasFijas.size()];
            armas.push_back(tipo_arma);

        }

        personajes.push_back(PersonajeFactory::crearPersonajeArmado(tipo_mago, armas));

    }
    for(int i = 0; i<cantGuerreros; i++){
        
        string tipo_guerrero = guerreros[rand() % guerreros.size()];

        int cantArmas = rand() % 3;
        vector<string> armas; 

        for(int j = 0; j < cantArmas; j++){
            string tipo_arma = armasFijas[rand() % armasFijas.size()];
            armas.push_back(tipo_arma);
        }

        personajes.push_back(PersonajeFactory::crearPersonajeArmado(tipo_guerrero, armas));

    }
    
    cout << "Personajes creados: \n";
    for (shared_ptr<Personaje> per : personajes) {
        cout << per->get_nombre() << ", "<< per->getNombresArmas()<<"\n";
    }
    cout << endl;


}