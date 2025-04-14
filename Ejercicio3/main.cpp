#include <iostream>
#include "PersonajeFactory.hpp"

using namespace std;

//const vector<string> nombresMagos = {"Hechicero", "Conjurador"}

//le voy a pedir al usuario que ingrese los tipos de personajes y de armas
int main(){
    
    srand(time(nullptr)); //entender bien esto

    int cantMagos = 3 + (rand() % (7 - 3 + 1));    
    int cantGuerreros = 3 + (rand() % (7 - 3 + 1));    

    vector<shared_ptr<Personaje>> personajes;

    for(int i = 0; i<cantMagos; i++){
        
        string tipo_mago;

        cout << "Ingrese el tipo de mago: "<< endl;
        cin>> tipo_mago;

        int cantArmas = rand() % 3; // cant random de armas que va a tener el mago
        vector<string> armas;

        for(int j = 0; j < cantArmas; j++){
            string tipo_arma;

            cout<<"Ingrese el tipo de arma: "<<endl;
            cin >> tipo_arma;
            armas.push_back(tipo_arma);
        }

        personajes.push_back(PersonajeFactory::crearPersonajeArmado(tipo_mago, armas));

    }
    for(int i = 0; i<cantGuerreros; i++){
        
        string tipo_guerrero;

        cout << "Ingrese el tipo de guerrero: "<< endl;
        cin>> tipo_guerrero;

        int cantArmas = rand() % 3; //ver si se sobreescribe variable
        vector<string> armas; //ver si se puede repetir variable

        for(int j = 0; j < cantArmas; j++){
            string tipo_arma;

            cout<<"Ingrese el tipo de arma: "<<endl;
            cin >> tipo_arma;
            armas.push_back(tipo_arma);
        }

        personajes.push_back(PersonajeFactory::crearPersonajeArmado(tipo_guerrero, armas));

    }
    //Aca ya tengo un vector con todos los personajes armados creados
}