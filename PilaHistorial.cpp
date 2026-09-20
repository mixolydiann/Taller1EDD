#include "PilaHistorial.h"

PilaHistorial::PilaHistorial() {
    this->tope = nullptr;
}

PilaHistorial::~PilaHistorial() {
    while (this->tope != nullptr) {
        NodoHistorial* temporal = this->tope->siguiente;
        delete this->tope;
        this->tope = temporal;
    }
}

// LIFO
void PilaHistorial::push(string nombre, int edad, string departamento) {
    NodoHistorial* nuevoNodo = new NodoHistorial(nombre, edad, departamento);
    nuevoNodo->siguiente = this->tope;
    this->tope = nuevoNodo;
}

// muestra desde el tope
void PilaHistorial::mostrarHistorial() {
    if (this->tope == nullptr) {
        cout << "El historial esta vacio." << endl;
        return;
    }

    NodoHistorial* actual = this->tope;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << " | Edad: " << actual->edad 
             << " | Departamento: " << actual->departamento << endl;
        cout << "--" << endl; // separation in the nation
        actual = actual->siguiente;
    }
}