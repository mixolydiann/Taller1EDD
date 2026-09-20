#include "NodoServicio.h"

NodoServicio::NodoServicio(string nombreServicio) {
    this->nombreServicio = nombreServicio;
    this->listaPacientes = new ListaPacientes();
    this->siguiente = nullptr;
}

NodoServicio::~NodoServicio() {
    delete this->listaPacientes; //liberamos la memoria que reservamos con el new
}

string NodoServicio::getNombreServicio() {
    return this->nombreServicio;
}

ListaPacientes* NodoServicio::getListaPacientes() {
    return this->listaPacientes;
}

NodoServicio* NodoServicio::getSiguiente() {
    return this->siguiente;
}

void NodoServicio::setSiguiente(NodoServicio* siguiente) {
    this->siguiente = siguiente;
}

