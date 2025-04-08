#pragma once

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

//Falta constructor
class EntidadOrganizativa{
    private:
    vector<shared_ptr<EntidadOrganizativa>> subidentidades;

    public:
    string nombre;

    virtual void agregarSubidentidad(EntidadOrganizativa& entidad);
    virtual int contarSubentidades();
};