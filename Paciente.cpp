#include "Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente(string id, string nombre, int edad, string servicio) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

Paciente::~Paciente() {}

// Getters
string Paciente::getId() {
    return this->id;
}

string Paciente::getNombre() {
    return this->nombre;
}

int Paciente::getEdad() {
    return this->edad;
}

string Paciente::getServicio() {
    return this->servicio;
}