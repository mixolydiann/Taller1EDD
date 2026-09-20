#include "NodoPaciente.h"

NodoPaciente::NodoPaciente(Paciente* paciente){
    this->paciente = paciente;
    this->siguiente = nullptr;
}

NodoPaciente::~NodoPaciente(){ //se limpia en listapacientes limpiar() y ColaPacientes
}

Paciente* NodoPaciente::getPaciente() {
    return this->paciente;
}

NodoPaciente* NodoPaciente::getSiguiente() {
    return this->siguiente;
}

void NodoPaciente::setSiguiente(NodoPaciente* siguiente) {
    this->siguiente = siguiente;
}
