#include "ColaPacientes.h"

ColaPacientes::ColaPacientes() {
    this->frente = nullptr;
    this->finalCola = nullptr;
}

ColaPacientes::~ColaPacientes() {
    while (this->frente != nullptr) {
        NodoPaciente* temporal = this->frente->getSiguiente();
        delete this->frente->getPaciente();
        delete this->frente;
        this->frente = temporal;
    }
}

// agregar al final
void ColaPacientes::goIn(Paciente* paciente) {
    NodoPaciente* nuevoNodo = new NodoPaciente(paciente);

    if (this->estaVacia()) {
        this->frente = nuevoNodo;
        this->finalCola = nuevoNodo;
    } else {
        this->finalCola->setSiguiente(nuevoNodo);
        this->finalCola = nuevoNodo;
    }
}

// eliminar al inicio
Paciente* ColaPacientes::goOut() {
    if (this->estaVacia()) {
        return nullptr;
    }

    NodoPaciente* nodoSalida = this->frente;
    Paciente* pacienteAtendido = nodoSalida->getPaciente();

    this->frente = this->frente->getSiguiente();
    
    // si queda vacia
    if (this->frente == nullptr) {
        this->finalCola = nullptr;
    }

    // aislamos el nodo para no borrar en cadena al hacer delete
    nodoSalida->setSiguiente(nullptr); 
    // y dps borramos el nodo pero no al paciente
    delete nodoSalida; 

    return pacienteAtendido;
}

bool ColaPacientes::estaVacia() {
    return (this->frente == nullptr);
}

void ColaPacientes::mostrarCola() {
    NodoPaciente* actual = this->frente;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << contador << ". " << actual->getPaciente()->getId() << " - " << actual->getPaciente()->getNombre() << std::endl;
        actual = actual->getSiguiente();
        contador++;
    }
}