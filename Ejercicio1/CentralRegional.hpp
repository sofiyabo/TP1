#pragma once

#include "EntidadOrganizativa.hpp"
#include "Empresa.hpp"
#include <set>

class GerenteAlto;
class GerenteMedio;
//Estas clases tienen una relacion de composicion con CR

class CentralRegional : public EntidadOrganizativa{
    private:
    int cantEmpleados;
    vector<shared_ptr<GerenteAlto>> gerentesAlto; //de 1 a 5
    vector<shared_ptr<GerenteMedio>> gerentesMedio; // de 1 a 20
    set<unique_ptr<Empresa>> empresas; // no tiene limite, ordenados y unicos
    //Hace falta sobrecargar operador de comparacion???

    public:
    //ver si override de Entidadorganizativo o no hace falta
    set<string> paises; //ilimitado, ordenados

    CentralRegional(){};
    int getCantEmpleados();
    vector<string> getEmpNames() const; //nombres de empresas!!
    vector<shared_ptr<GerenteAlto>> getGerentesAltos();
    vector<shared_ptr<GerenteMedio>> getGerentesMedios();

};