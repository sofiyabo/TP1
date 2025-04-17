#include "Personaje.hpp"

#include "Arma.hpp"

void Magos::usarMagia(){
    cout<< "Esta usando 10 puntos de magia. Estos seran agregados en su potencia."<<endl;
    arma_actual->setPotencia(-10);
}

void Magos::agregar_arma(shared_ptr<Arma> arma){
    
    if(armas_combate.empty() && armas_magicas.empty()){
        arma_actual = arma;
    }
    
    if(auto itemMagico = dynamic_pointer_cast<ItemsMagicos>(arma)){
        armas_magicas.push_back(arma);
    }
    else if(auto ArmaCombate = dynamic_pointer_cast<ArmasdeCombate>(arma)){
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

string Magos::get_nombre(){
    return nombre;
}


int Magos::get_vida(){
    return vida;
}

void Magos::restarVida(int cantidad){
    vida-=cantidad;
}

string Magos::getArmaActualNombre(){
    return arma_actual->get_nombre();
}

string Magos::getNombresArmas()  {
    string resultado = "Armas: ";
    
    for (const auto& arma : armas_combate) {
        resultado += arma->get_nombre() + ", "; 
    }
    
    for (const auto& arma : armas_magicas) {
        resultado += arma->get_nombre() + ", ";  
    }

    if (resultado != "Armas: ") {
        resultado.pop_back(); // para eliminar la coma y el espacio final
        resultado.pop_back();
        resultado += ".";
    }
    else{
        resultado += "No tiene armas";
    }

    return resultado;
}

void Guerreros::agregar_arma(shared_ptr<Arma> arma){
    if(armas_combate.empty() && armas_magicas.empty()){
        arma_actual = arma;
    }

    if(auto itemMagico = dynamic_pointer_cast<ItemsMagicos>(arma)){
        armas_magicas.push_back(arma);
    }
    else if(auto ArmaCombate = dynamic_pointer_cast<ArmasdeCombate>(arma)){
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

int Guerreros::get_vida(){
    return vida;
}

void Guerreros::restarVida(int cantidad){
    vida-= cantidad;
}

string Guerreros::getArmaActualNombre(){
    return arma_actual->get_nombre();
}

void Guerreros::setVida(int cantidad){
    vida+=cantidad;
}

int Guerreros::getInteligencia(){
    return inteligencia;

}

string Guerreros::getNombresArmas()  {
    string resultado = "Armas: ";
    
    for (const auto& arma : armas_combate) {
        resultado += arma->get_nombre() + ", "; 
    }
    
    for (const auto& arma : armas_magicas) {
        resultado += arma->get_nombre() + ", "; 
    }

    if (resultado != "Armas: ") {
        resultado.pop_back(); 
        resultado.pop_back();
        resultado += ".";
    }
    else{
        resultado += "No tiene armas";
    }

    return resultado;
}

void Hechicero::lanzarHechizo(){
    cout<< hechizo<<endl;
}

string Hechicero::getTipo(){
    return tipo;
}

void Conjurador::usarConjuro(int indice){
    cout<<conjuros[indice]<<endl;
}

string Conjurador::getTipo(){
    return tipo;
}

void Brujo::usarPoder(){
    if(activado){
        cout<< "Tienes activado el poder de "<<poder<< " para las proximas 2 rondas."<< endl;
    }
    else{
        cout<< "Le han desactivado su poder."<<endl;
    }
}

void Nigromante::invocarEspectros(){
    if(eficaciaComunicacion){
        cout<< "Estas invocando el poder de "<<espectros<< ". Aprovechalos en esta ronda!"<<endl;
    }
    else{
        cout<< "No se puede comunicar con los espectros."<<endl;
    }
}

int Barbaro::getFuria(){
    return furia;
    
}

string Paladin::getHabilidad(){
    return habilidad;
}

void Paladin::curarse(){
    if(curar){
        cout<< "Te podes curar! Tienes +20 HP."<< endl;
        Guerreros::setVida(20);
    }
    else{
        cout<< "No tienes la habilidad para curarte!"<<endl;
    }
}

void Caballero::usarHonor(){
    cout<< "Gracias a tu honor, tienes +"<<honor<< " HP."<< endl;
    Guerreros::setVida(honor);
}

int Mercenario::getVictorias(){
    return victorias;
}

string Gladiador::getEstilo(){
    return estilo;
}

//implementaciones de mostrar_info en las derivadas de Magos

void Hechicero::mostrarInfo(){
    cout<<"El personaje es un Hechicero de tipo "<<tipo<<". Su lista de hechizo especial es: '"<<hechizo<<"'";
}

void Conjurador::mostrarInfo(){
    cout<<" El conjurador es de tipo "<<tipo<< ". Sus conjuros son:";
    for(string conj : conjuros){
        cout<<conj<<". "<<endl;
    }
}

void Brujo::mostrarInfo(){
    cout<< "El personaje es un brujo. Su poder es "<< poder<<". ";
    if(activado){
        cout<<"Se encuentra activado.";
    }
    else{
        cout<< "No se encuentra activado.";
    }
}

void Nigromante::mostrarInfo(){
    cout<< "El Nigromante tiene "<< espectros<< " espectros a su disposicion.";
    if(eficaciaComunicacion){
        cout<<"Puede comunicarse con ellos";
    }
    else{
        cout<<"No puede comunicarse con ellos";
    }
}

//implementaciones de estrategia en las derivadas de Guerreros
void Barbaro::estrategia(){
    if(getInteligencia() >= 70){
        furia+= 15;
        cout<<"El barbaro usa su inteligencia, y ataca con mas furia."<<endl;
    }
    else{
        cout<<" El barbaro no es capaz de implementar una estrategia"<<endl;
    }
}

void Paladin::estrategia() {
    if (getInteligencia() >= 70) {
        curar = true;
        cout << "El paladín usa su inteligencia y puede curarse." << endl;
    } else {
        curar = false;
        cout << "El paladín no tiene la inteligencia para curarse" << endl;
    }
}

void Caballero::estrategia() {
    if (getInteligencia() >= 70) {
        honor += 5;
        cout << "El caballero usa su inteligencia para reforzar su honor." << endl;
    } else {
        cout << "El caballero no tiene suficiente inteligencia." << endl;
    }
}

void Mercenario::estrategia() {
    if (getInteligencia() >= 70) {
        cout << "El mercenario usa su especialidad de "<<especialidad<< "y mejora su estrategia." << endl;
    } else {
        cout << "El mercenario pelea por dinero, sin preocuparse demasiado por la táctica." << endl;
    }
}

void Gladiador::estrategia() {
    if (getInteligencia() >= 70) {
        cout << "El gladiador ajusta su estilo "<< estilo<< "para ganar ventaja!" << endl;
    } else {
        cout << "El gladiador se aferra a su técnica defensiva, sin cambiar su estrategia." << endl;
    }
}