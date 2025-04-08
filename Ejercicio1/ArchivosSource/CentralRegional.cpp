#include "CentralRegional.hpp"

int CentralRegional::getCantEmpleados(){
    return cantEmpleados;
}

vector<string> CentralRegional::getEmpNames() const{
    vector<string> nombres;
    for(const auto& empresa:empresas){
        nombres.push_back(empresa->nombre); //Como ya estan ordenados alfabeticamente, se van a guardar ordenados
    }
}

