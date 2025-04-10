#include "Departamento.hpp"
#include "Empleado.hpp"

int Departamento::cantEmpleadosDepts = 0;

int Departamento::contarEmpleados(){
    return cantEmpleadosDepts;
} 

vector<shared_ptr<Empleado>> Departamento::getEmployees(){
    return empleados;
}

bool Departamento::contratarEmpleado(shared_ptr<Empleado> empleado){
    //Uso un iterador para verificar que el empleado no esta ya contratado
    vector<shared_ptr<Empleado>>::iterator iterador;
    for(iterador = empleados.begin(); iterador != empleados.end(); iterador++){
        if((*iterador)= empleado){
            cout<< "El empleado ya se encontraba contratado."<<endl;
            return false;
        }
    }
    empleados.push_back(empleado);
    cantEmpleadosDepts++;
    return true;
    //que no esta ya contratado
}

bool Departamento::despedirEmpleado(shared_ptr<Empleado> empleado){
    //Puedo usar un iterador para buscar en el vector
    vector<shared_ptr<Empleado>>::iterator iterador;
    for(iterador = empleados.begin(); iterador != empleados.end(); iterador++){
        if((*iterador)= empleado){
            empleados.erase(iterador);
            cout<< "El empleado ha sido despedido."<<endl;
            return true;
        }
    }
    return false;
}