#include "ListaPacientes.h"

ListaPacientes::ListaPacientes() {
    this->inicio = nullptr;
    this->cantidadPacientes = 0;
}

ListaPacientes::~ListaPacientes(){
    this->limpiar();
}

void ListaPacientes::limpiar() {
    while (this->inicio != nullptr) {
        NodoPaciente* temp = this->inicio->getSiguiente(); // ponemos q sea el segundo
        delete this->inicio; // ahora que borramos el inicio queda segundo el temp
        this->inicio = temp; // lo declaramos como inicio -> al terminar el cycle queda solo el puntero nulo
    }
}

void ListaPacientes::agregarPaciente(Paciente* paciente) { // añade al final
    NodoPaciente* nuevoPaciente = new NodoPaciente(paciente);

    if (this->inicio == nullptr){
        this->inicio = nuevoPaciente;
    } else {
        NodoPaciente* iterator = this->inicio;

        while (iterator->getSiguiente() != nullptr) {
            iterator = iterator->getSiguiente();
        }
        iterator->setSiguiente(nuevoPaciente);
    }
    this->cantidadPacientes++; // yea
}

void ListaPacientes::mostrarPacientes() {
    NodoPaciente* iterator = this->inicio;

    while (iterator != nullptr){
        Paciente* p = iterator->getPaciente();
        cout << p->getNombre() << " (" << p->getEdad() << ")" << endl;
        iterator = iterator->getSiguiente();
    }
}

int ListaPacientes::getCantidadPacientes() {
    return this->cantidadPacientes;
}

