#include "EntidadOrganizativa.hpp"

void EntidadOrganizativa::agregarSubidentidad(const shared_ptr<EntidadOrganizativa> entidad){
    subentidades.push_back(entidad);
} //ver si pasar por ref o no
    


int EntidadOrganizativa::contarSubentidades(){
    return static_cast<int>(subentidades.size());
}