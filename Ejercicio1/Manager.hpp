#pragma once

#include "Empleado.hpp"

class Manager : public Empleado{
    private:
    float bono;
    string level;

    public:
    Manager(float b, string nivel) : bono(b), level(nivel){}
    bool updateBono(float nuevo_bono);
    float getBono();
    bool setLevel(string nivel);
};