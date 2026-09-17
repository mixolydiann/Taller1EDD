#pragma once
#include "Paciente.h"

class NodoPaciente {
private:
    Paciente* paciente;
    NodoPaciente* siguiente;
public:
    NodoPaciente(Paciente* paciente);

    ~NodoPaciente();

    Paciente* getPaciente();
    NodoPaciente* getSiguiente();
    void setSiguiente(NodoPaciente* siguiente);
};