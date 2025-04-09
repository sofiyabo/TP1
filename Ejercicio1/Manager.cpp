#include "Manager.hpp"

bool Manager::updateBono(float nuevo_bono){
    bono = nuevo_bono;
    return true;
}

float Manager::getBono(){
    return bono;
}

bool Manager::setLevel(string nivel){
    level = nivel;
    return true;
}