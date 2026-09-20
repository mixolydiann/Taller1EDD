#include <iostream>
#include "Hospital.h"
using namespace std;

int main() {

    Hospital* hospitalMarmaja = new Hospital();
    string choice = "";

    while (choice != "4") {
        cout << " " << endl;
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << " " << endl;
        cout << "Seleccionar opcion: " << endl;

        cin >> choice;

        try { //el switch no worky asi que condicionales anidadas
            if (choice == "1") {
                cout << "=== wip ===" << endl;
            } else if (choice == "2") {
                cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
                hospitalMarmaja->mostrarDepartamentos();
            } else if (choice == "3") {
                cout << "=== wip ===" << endl;
            } else if (choice == "4") {
                cout << "Hasta luego :D." << endl;
            }
            else {
                throw choice;
            }
        }

        catch (string e) {
            cout << "Error: (" << e << ") no es una opcion valida. Reingrese" << endl;
        }

    }

    delete hospitalMarmaja;
    return 0;
}