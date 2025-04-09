#include "Empresa.hpp"
#include "CentralRegional.hpp"
#include "Departamento.hpp"
#include "Empleado.hpp"
#include "Manager.hpp"

int main(){
    shared_ptr<Empleado> empleado1 = make_shared<Empleado>(3, 50, "Juan", "Contador");
}