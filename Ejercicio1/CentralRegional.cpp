#include "CentralRegional.hpp"

int CentralRegional::getCantEmpleados(){
    return cantEmpleados;
}

vector<string> CentralRegional::getEmpNames() const{
    vector<string> nombres;
    for(const auto& empresa:empresas){
        nombres.push_back(empresa->nombre); //Como ya estan ordenados alfabeticamente, se van a guardar ordenados

    }
    return nombres;
}

vector<shared_ptr<GerenteAlto>> CentralRegional::getGerentesAltos(){
    return gerentesAlto;
}

vector<shared_ptr<GerenteMedio>> CentralRegional::getGerentesMedios(){
    return gerentesMedio;
}
