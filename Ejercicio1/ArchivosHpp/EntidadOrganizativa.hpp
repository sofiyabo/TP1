#pragma once

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//Falta constructor
class EntidadOrganizativa{
    private:
    vector<shared_ptr<EntidadOrganizativa>> subentidades;

    public:
    string nombre;

    //Voy a implementar estos metodos desde esta clase
    virtual void agregarSubidentidad(const shared_ptr<EntidadOrganizativa> entidad); //ver si pasar por ref o no
    virtual int contarSubentidades();
};

