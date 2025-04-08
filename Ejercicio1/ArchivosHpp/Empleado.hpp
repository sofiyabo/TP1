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

    int getAntiguedad();
    bool updateSalario(float);
    float getSalario();
};