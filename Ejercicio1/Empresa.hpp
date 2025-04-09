#pragma once

#include "EntidadOrganizativa.hpp"

class Departamento;

//Composicion con CentralRegional

class Empresa : public EntidadOrganizativa{
    private:
    vector<shared_ptr<Departamento>> departamentos; //ilimitado

    public:
    string direccion;

    Empresa(){}
    Departamento getDepByName(string nombre);
    vector<string> getDepNames(); //ver como es de hacer un vector de departamentos si solo quiero los nombres
    
};