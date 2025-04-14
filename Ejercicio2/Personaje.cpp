#include "Personaje.hpp"

Magos::Magos(string tipo, int vida) 
: tipo(tipo), armas_combate{}, armas_magicas{}, vida(vida) {} //Las armas se van agregando en diferentes instancias, no al crear el objeto

void Magos::agregar_arma(shared_ptr<Arma> arma){
    if(auto itemMagico = std::dynamic_pointer_cast<ItemsMagicos>(arma)){
        armas_magicas.push_back(arma);
    }
    else if(auto ArmaCombate = std::dynamic_pointer_cast<ArmasdeCombate>(arma)){
        armas_magicas.push_back(arma);
    }
    return;
}

void Magos::elegir_arma(string nombre){
    string tipo_arma;

    cout<< "De que tipo es el arma que desea? (ItemMagico o ArmadeCombate):"<< endl;
    cin >> tipo_arma;

    if(tipo_arma == "ItemMagico"){
        for(const auto& arma : armas_magicas){
            if(arma->get_nombre() == nombre){
                arma_actual = arma;
            }
        }
    }else if(tipo_arma == "ArmadeCombate"){
        for(const auto& arma : armas_combate){
            if(arma->get_nombre() == nombre){
                arma_actual = arma;
            }
        }
    }else{
        cout<< "No tenes ese arma en tu armamento.";
    }

}

string Magos::get_tipo(){
    return tipo;
}

void Magos::mostrarInfo() {
    cout<< "Tipo: " << tipo << ". Vida: " << vida << ". Arma actual: "<< arma_actual << endl;
}

void Magos::GolpeRapido() {

}

void Magos::GolpeFuerte(){

}

void Magos::DefensaYGolpe(){

}

void Guerreros::agregar_arma(shared_ptr<Arma> arma){
    if(auto itemMagico = std::dynamic_pointer_cast<ItemsMagicos>(arma)){
        armas_magicas.push_back(arma);
    }
    else if(auto ArmaCombate = std::dynamic_pointer_cast<ArmasdeCombate>(arma)){
        armas_magicas.push_back(arma);
    }
    return;
}

void Guerreros::elegir_arma(string nombre){
    string tipo_arma;

    cout<< "De que tipo es el arma que desea? (ItemMagico o ArmadeCombate):"<< endl;
    cin >> tipo_arma;

    if(tipo_arma == "ItemMagico"){
        for(const auto& arma : armas_magicas){
            if(arma->get_nombre() == nombre){
                arma_actual = arma;
            }
        }
    }else if(tipo_arma == "ArmadeCombate"){
        for(const auto& arma : armas_combate){
            if(arma->get_nombre() == nombre){
                arma_actual = arma;
            }
        }
    }else{
        cout<< "No tenes ese arma en tu armamento.";
    }

}

string Guerreros::get_nombre(){
    return nombre;
}

void Guerreros::mostrarInfo() {
    cout<< "Nombre: " << nombre << ". Vida: " << vida << ". Arma actual: "<< arma_actual << endl;
}

void Guerreros::GolpeRapido(){

}

void Guerreros::GolpeFuerte() {}

void Guerreros::DefensaYGolpe() {}

