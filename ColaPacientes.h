#pragma once
#include "NodoPaciente.h"
#include <iostream>

class ColaPacientes {
private:
    NodoPaciente* frente;
    NodoPaciente* finalCola;
public:
    ColaPacientes();
    ~ColaPacientes();

    void goIn(Paciente* paciente); // fi
    Paciente* goOut(); // fo
    bool estaVacia();
    void mostrarCola();
    
};