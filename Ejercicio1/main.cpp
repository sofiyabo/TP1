#include "Empresa.hpp"
#include "CentralRegional.hpp"
#include "Departamento.hpp"
#include "Empleado.hpp"
#include "Manager.hpp"

//REVISAR RELACIONES ENTRE VARIABLES

int main(){
    shared_ptr<Empleado> empleado1 = make_shared<Empleado>(3, 50, "Juan", "Contador");
    Departamento dept;
    dept.contratarEmpleado(empleado1); //ANDA BIEN 
    vector<shared_ptr<Empleado>> empleados = dept.getEmployees(); //ANDA BIEN
    cout << empleados[0]->getAntiguedad() << endl;


}