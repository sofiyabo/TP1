#pragma once

#include "Empleado.hpp"

class Manager : public Empleado{
    private:
    float bono;
    string level;

    public:
    bool updateBono(float);
    float getBono();
    bool setLevel(string);
};