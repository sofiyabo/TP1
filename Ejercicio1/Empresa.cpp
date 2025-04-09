#include "Empresa.hpp"
#include "Departamento.hpp"

using namespace std;

Departamento Empresa::getDepByName(string nombre){
    for(const auto& dep : departamentos){
        if(dep->nombre == nombre){
            return *dep; 
        }
    }
    cout<< "No se ha encontrado un departamento con ese nombre."<< endl;
}


vector<string> Empresa::getDepNames(){
    vector<string> nombres;
    for(const auto& dep : departamentos){
        nombres.push_back(dep->nombre);
    }
    return nombres;
}