#include "Hospital.h"

Hospital::Hospital() {
    this->inicio = nullptr;

    this->agregarServicio("Urgencias");
    this->agregarServicio("Medicina General");
    this->agregarServicio("Cardiologia");
    this->agregarServicio("Neurologia");
    this->agregarServicio("Traumatologia");
    this->agregarServicio("Cirugia");
    this->agregarServicio("Pediatria");
    this->agregarServicio("Hospitalizacion");

}

Hospital::~Hospital() {
    while (this->inicio != nullptr) {
        NodoServicio* temp = this->inicio->getSiguiente();
        delete this->inicio;
        this->inicio = temp;
    }
}

void Hospital::agregarServicio(string nombre) {
    NodoServicio* nuevoServicio = new NodoServicio(nombre);

    if (this->inicio == nullptr) {
        this->inicio = nuevoServicio;
    } else {
        NodoServicio* iterator = inicio;
        while (iterator->getSiguiente() != nullptr) {
            iterator = iterator->getSiguiente();
        }
        iterator->setSiguiente(nuevoServicio);
    }
}

NodoServicio* Hospital::buscarServicio(string nombre) {
    NodoServicio* iterator = this->inicio;
    while (iterator!=nullptr) {
        if (iterator->getNombreServicio() == nombre) {
            return iterator;
        }
        iterator = iterator->getSiguiente();
    }
    return nullptr;
}

void Hospital::mostrarDepartamentos() {
    NodoServicio* iterator = this->inicio;
    int count = 1;
    while(iterator != nullptr) {
        std::cout << count<<". " << iterator->getNombreServicio() << std::endl;
        iterator = iterator->getSiguiente();
        count++;
    }
}

