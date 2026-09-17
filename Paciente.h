#pragma once
#include <string>

using namespace std;

class Paciente {
    private:
        string id;
        string nombre;
        int edad;
        string servicio;
    public:
        Paciente(string id, string nombre, int edad, string servicio);

        ~Paciente();

        string getId();
        string getNombre();
        int getEdad();
        string getServicio();

};