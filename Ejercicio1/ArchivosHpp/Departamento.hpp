#pragma once

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Empleado;

class Departamento{
    private:
    vector<shared_ptr<Empleado>> empleados;
    int cantEmpleadosDepts; //estatico

    public:
    string nombre;
    string ubicacion;

    int contarEmpleados(); //estatico
    vector<shared_ptr<Empleado>> getEmployees();
    bool contratarEmpleado(Empleado);
    bool despedirEmpleado(Empleado);
};