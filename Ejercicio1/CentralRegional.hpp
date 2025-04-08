#pragma once

#include "EntidadOrganizativa.hpp"
#include <set>

class GerenteAlto;
class GerenteMedio;
class Empresa;

//Faltan constructores y destructores
class CentralRegional : public EntidadOrganizativa{
    private:
    int cantEmpleados;
    vector<shared_ptr<GerenteAlto>> gerentesAlto; //de 1 a 5
    vector<shared_ptr<GerenteMedio>> gerentesMedio; // de 1 a 20
    set<unique_ptr<Empresa>> empresas; // no tiene limite, ordenados y unicos

    public:
    //ver si override de Entidadorganizativo o no hace falta
    set<string> paises; //ilimitado, ordenados
    int getCantEmpleados();
    string getEmpNames();
    vector<shared_ptr<GerenteAlto>> getGerentesAltos();
    vector<shared_ptr<GerenteMedio>> getGerentesMedios();

};