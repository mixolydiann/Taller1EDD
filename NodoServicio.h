#pragma once
#include <string>
#include "ListaPacientes.h"

class NodoServicio {
private:
    string nombreServicio;
    ListaPacientes* listaPacientes;
    NodoServicio* siguiente;
public:
    NodoServicio(string nombreServicio);
    ~NodoServicio();

    string getNombreServicio();
    ListaPacientes* getListaPacientes();
    NodoServicio* getSiguiente();

    void setSiguiente(NodoServicio* siguiente);
};