#pragma once
#include "NodoPaciente.h"
#include <iostream>

using namespace std;

class ListaPacientes { // esta lista va a estar adentro de la lista maestra de los dept del hospital
private:
    NodoPaciente* inicio;
    int cantidadPacientes; // contador aka no un fixed size
public:
    ListaPacientes();
    ~ListaPacientes();

    void agregarPaciente(Paciente* paciente);
    void mostrarPacientes();
    int getCantidadPacientes();

    void limpiar();
};