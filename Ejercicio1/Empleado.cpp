#include "Empleado.hpp"

int Empleado::getAntiguedad(){
    return antiguedad;
}


bool Empleado::updateSalario(float salario_nuevo){
    salario = salario_nuevo;
    return true;
}


float Empleado::getSalario(){
    return salario;
}