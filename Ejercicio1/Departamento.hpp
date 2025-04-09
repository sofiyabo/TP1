#pragma once

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Empleado;

class Departamento{
    private:
    vector<shared_ptr<Empleado>> empleados;
    static int cantEmpleadosDepts; 

    public:
    string nombre;
    string ubicacion;

    Departamento(){}
    static int contarEmpleados(); 
    vector<shared_ptr<Empleado>> getEmployees();
    bool contratarEmpleado(shared_ptr<Empleado>);
    bool despedirEmpleado(shared_ptr<Empleado>);
};