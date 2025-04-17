#include "../PersonajeFactory.hpp"


const vector<string> personajes = {"Nigromante", "Hechicero", "Conjurador", "Brujo", "Gladiador", "Mercenario", "Caballero", "Paladin", "Barbaro"};
const vector<string> armas = {"Espada", "HachaDoble", "Lanza", "HachaSimple", "LibrodeHechizos", "Baston", "Amuleto", "Pocion", "Garrote"};
const vector<string> golpes = {"Golpe Fuerte", "Golpe Rapido", "Defensa y Golpe"};

int main(){

    srand(time(nullptr));

    string tipoJugador1;
    string tipoArma1;

    //Le pido al usuario que ingrese su personaje y su arma
    cout<<"Ingrese su personaje: ";
    cin>> tipoJugador1;

    cout << "Ingrese su arma:";
    cin >> tipoArma1;

    //Uso PersonajeFactory para crear a los jugadores
    shared_ptr<Personaje> jugador1 = PersonajeFactory::crearPersonajeArmado(tipoJugador1, {tipoArma1});

    string tipoJugador2 = personajes[rand() % personajes.size()];
    string armaJugador2 = armas[rand() % armas.size()];

    shared_ptr<Personaje> jugador2 = PersonajeFactory::crearPersonajeArmado(tipoJugador2, {armaJugador2}); //Jugador 2 hecho de manera random

    bool pierde;

    while(true){ //Uso un loop de while para hacer las rondas del combate, hasta que alguno de los dos jugadores lleguen a 0
        
        pierde = false;
        
        cout<< "El " << jugador1->get_nombre() << " tiene " << jugador1->get_vida() << "HP y el " << jugador2->get_nombre() << " tiene "<< jugador2->get_vida() << "HP"<<endl;
        int eleccionGolpe;
        cout<< "Su opcion: (1) Golpe Fuerte, () Golpe Rápido, (3) Defensa y Golpe:";
        cin>> eleccionGolpe;

        string golpeRandom = golpes[rand() % golpes.size()];
        
        if(golpes[eleccionGolpe -1] == golpeRandom){
            cout<< "Han elegido el mismo golpe, se pasa a la siguiente ronda."<<endl;
            continue;
        }
        else if(eleccionGolpe == 1 && golpeRandom == "Golpe Rapido"){
            jugador2->restarVida(10);
        }
        else if(eleccionGolpe == 2 && golpeRandom == "Golpe Fuerte"){
            jugador1->restarVida(10);
            pierde = true;
        }
        else if(eleccionGolpe == 2 && golpeRandom == "Defensa y Golpe"){
            jugador2->restarVida(10);
        }
        else if(eleccionGolpe == 3 && golpeRandom == "Golpe Rapido"){
            jugador1->restarVida(10);
            pierde = true;
        }
        else if(eleccionGolpe == 3 && golpeRandom == "Golpe Fuerte"){
            jugador2->restarVida(10);
        }
        else if(eleccionGolpe == 1 && golpeRandom == "Defensa y Golpe"){
            jugador1->restarVida(10);
            pierde = true;
        }
        
        if(pierde){
            cout<< "El " << jugador2->get_nombre() << " ataca con " << jugador2->getArmaActualNombre() << " y hace 10 puntos de daño.\n"<< endl;
        }
        else{
            cout<< "El " << jugador1->get_nombre() << " ataca con " << jugador1->getArmaActualNombre() << " y hace 10 puntos de daño.\n"<< endl;
        }

        if(jugador1->get_vida() <= 0 || jugador2->get_vida() <=0){
            break;
        }

    }
    if(pierde){
        cout<< "Ha ganado el jugador 2"<<endl;
    }
    else{
        cout<< "Felicitaciones! Has ganado.";
    }

    return 0;

}

