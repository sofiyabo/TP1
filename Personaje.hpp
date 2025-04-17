#pragma once 

#include "Arma.hpp"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;


class Personaje{ //Interfaz

    public:
    virtual void elegir_arma(string nombre) = 0;
    virtual int get_vida() = 0;
    virtual void agregar_arma(shared_ptr<Arma> arma) = 0;
    virtual void restarVida(int cantidad) = 0;
    virtual string get_nombre() = 0;
    virtual string getArmaActualNombre() =0;
    virtual string getNombresArmas() =0;



};


class Magos : public Personaje{

    private:
    string nombre;
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas;
    shared_ptr<Arma> arma_actual;
    int nivelMagia;
    int vida;

    public:

    Magos(string nombre) : nombre(nombre), armas_combate({}), armas_magicas({}), arma_actual(nullptr), nivelMagia(50), vida(100){}
    ~Magos() {}    
 
    virtual void mostrarInfo() = 0;
    void usarMagia();


    void elegir_arma(string nombre) override; // pone al arma como arma actual
    string get_nombre() override;
    int get_vida() override;
    void restarVida(int cantidad) override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    string getArmaActualNombre() override;
    string getNombresArmas() override;

};

class Guerreros : public Personaje{

    private:
    string nombre;
    vector<shared_ptr<Arma>> armas_combate;  
    vector<shared_ptr<Arma>> armas_magicas; 
    shared_ptr<Arma> arma_actual;
    int inteligencia;
    int vida;

    public:
    Guerreros(string nombre, int inteligencia) : nombre(nombre), armas_combate({}), armas_magicas({}), arma_actual(nullptr), vida(100), inteligencia(inteligencia) {}
    ~Guerreros() {}

    virtual void estrategia() = 0;
    void setVida(int cantidad);
    int getInteligencia();

    void elegir_arma(string nombre) override;
    string get_nombre() override;
    int get_vida() override;
    void agregar_arma(shared_ptr<Arma> arma) override;
    void restarVida(int cantidad) override;
    string getArmaActualNombre() override;
    string getNombresArmas() override;

};

//Derivadas de Magos

class Hechicero : public Magos{

    private:
    string tipo;
    string hechizo;

    public:

    Hechicero() : Magos("Hechicero"), tipo("Sabio"), hechizo("Una tormenta bloquea la vista del enemigo, haciendo que pierda su próximo ataque. Podes atacar de nuevo!"){}
    void lanzarHechizo();
    string getTipo();
    void mostrarInfo() override;



};

class Conjurador : public Magos{
    private:
    vector<string> conjuros;
    string tipo;

    public:

    Conjurador() : Magos("Conjurador"), conjuros({"Espejismo: Creas una ilusion optica, multiplicandote muchas veces en el campo de batalla. Tu enemigo queda desconcertado y falla el ataque.", "Creas un tornado a tu alrededor, haciendo que te cubras del ataque.", "Paralizas a tu enemigo, podes atacar 2 veces mas!"}) {}
    void usarConjuro(int indice);
    string getTipo();
    void mostrarInfo() override;



};

class Brujo : public Magos{
    
    private:
    string poder;
    bool activado;

    public:

    Brujo() : Magos("Brujo"), poder("Volar"), activado(true) {}

    void usarPoder();
    void mostrarInfo() override;


};

class Nigromante : public Magos{

    private:
    bool eficaciaComunicacion;
    int espectros;

    public:

    Nigromante() : Magos("Nigromante"), eficaciaComunicacion(true), espectros(4){}
    void invocarEspectros();
    void mostrarInfo() override;


};


//Derivadas Guerreros
class Barbaro : public Guerreros{

    private:
    int furia;

    public:

    Barbaro() : Guerreros("Barbaro", 75), furia(30) {}

    int getFuria();
    void estrategia() override;


};

class Paladin : public Guerreros{
    private:
    string habilidad;
    bool curar;

    public:
    Paladin() : Guerreros("Paladin", 45), habilidad("Teletransportacion"), curar(true) {}
    string getHabilidad();
    void curarse();
    void estrategia() override;

};

class Caballero : public Guerreros{
    private:
    int honor;

    public:

    Caballero() : Guerreros("Caballero", 40), honor(8) {}
    void usarHonor();
    void estrategia() override;

};

class Mercenario : public Guerreros{
    private:
    string especialidad;
    int victorias;

    public:

    Mercenario() : Guerreros("Mercenario", 60), especialidad("Hachas"), victorias(4){}
    int getVictorias();
    void estrategia() override;


};

class Gladiador : public Guerreros{
    private:
    string estilo;
    int victorias;

    public:

    Gladiador() : Guerreros("Gladiador", 20), estilo("Defensivo"), victorias(7) {}
    string getEstilo();    
    void estrategia() override;

};