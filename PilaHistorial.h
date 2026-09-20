#pragma once
#include <string>
#include <iostream>
using namespace std;

class NodoHistorial {
public:
    string nombre;
    int edad;
    string departamento;
    NodoHistorial* siguiente;

    NodoHistorial(string n, int e, string d) {
        this->nombre = n;
        this->edad = e;
        this->departamento = d;
        this->siguiente = nullptr;
    }
};

// la pila wey
class PilaHistorial {
private:
    NodoHistorial* tope; // top

public:
    PilaHistorial();
    ~PilaHistorial();
    void push(string nombre, int edad, string departamento);
    void mostrarHistorial();
};