#pragma once

#include "ItemsMagicos.hpp"


class LibrodeHechizos : public ItemsMagicos{
    
    private:
    int paginaActual;
    string tipo_libro;
    vector<string> hechizo;

    public:
    string leer_hechizo();
    void cambiar_pagina(int pag);
    void usar_hechizo();
    
};
/*
Atributos:
    lista de hechizos: 
    tipo de libro: defensa, ataque, pociones etc. 
    pagina actual
    cantidad de paginas


Metodos:
    leer hechizo de pagina actual
    cambiar de pagina: al proximo o anterior
    get cantidad de paginas
    get hechizo: busca un hechizo por su nombre
    usar hechizo


*/