#include "NodoPaciente.h"

NodoPaciente::NodoPaciente(Paciente* paciente){
    this->paciente = paciente;
    this->siguiente = nullptr;
}

NodoPaciente::~NodoPaciente(){
    delete this->paciente;
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
