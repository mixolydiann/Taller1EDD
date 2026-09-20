#pragma once
#include "NodoServicio.h"

class Hospital {
private:
    NodoServicio* inicio;
public:
    Hospital();
    ~Hospital();

    void agregarServicio(string nombre);
    NodoServicio* buscarServicio(string nombre);
    void mostrarDepartamentos();

};