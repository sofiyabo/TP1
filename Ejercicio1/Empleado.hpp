#pragma once

#include <iostream>
using namespace std;


class Empleado{
    private:
    int antiguedad;
    float salario;

    public:
    string nombre;
    string puesto;

    Empleado(){}
    Empleado(int ant, float sal, string nomb, string puest) : antiguedad(ant), salario(sal), nombre(nomb), puesto(puest){}
    int getAntiguedad();
    bool updateSalario(float salario_nuevo);
    float getSalario();
};