#include <iostream>
#include "Hospital.h"
#include "ColaPacientes.h"
#include "PilaHistorial.h"
#include <fstream>

using namespace std;

void cargarPacientes(ColaPacientes* cola) {
    ifstream archivo("pacientes.txt"); 
    
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        // ignorar lineas vacias por seguridad
        if (linea.empty()) continue; 

        // convertimos a arreglo de caracteres
        const char* ptr = linea.c_str(); // Cstring (arreglo primitivo de caracteres basicos) xq string (como es un objeto) no deja moverse x la memoria
        const char* inicio = ptr; 
        
        string datos[4]; 
        int contador = 0;

        // siendo \0 el final de la cadena
        while (*ptr != '\0') {
            if (*ptr == ';') {
                // desde el inicio hasta donde esta el puntero actual
                datos[contador] = string(inicio, ptr - inicio); 
                contador++;
                inicio = ptr + 1; // nuevo inicio despuds del ;
            }
            // aritmetica de punteros para moverse en la memory
            ptr++; 
        }
        
        // guardamos el ultimo dato (el depto)
        datos[3] = string(inicio, ptr - inicio);

        // si el ultimo dato tiene un salto de linea \r lo sacamos
        if (!datos[3].empty() && datos[3].back() == '\r') {
            datos[3].pop_back();
        }
 
        // stoi = string to int (banger)
        int edad = stoi(datos[2]);
        
        // creamos el paciente y va a la fila
        Paciente* nuevoPaciente = new Paciente(datos[0], datos[1], edad, datos[3]);
        cola->goIn(nuevoPaciente);
    }
    
    archivo.close();
    cout << "Archivo cargado exitosamente." << endl;
}

void atenderPacientes(ColaPacientes* fila, Hospital* hospital, PilaHistorial* historial) {
    if (fila->estaVacia()) {
        cout << "\nNo hay pacientes en la fila de espera." << endl;
        return;
    }

    cout << "\n=== PACIENTES EN ESPERA ===" << endl;
    fila->mostrarCola();

    string cantidadStr;
    cout << "\nIndique la cantidad de pacientes a atender: ";
    cin >> cantidadStr;

    try {
        int cantidad = stoi(cantidadStr); // convertimos el texto a numero
        
        if (cantidad <= 0) {
            cout << "Debe ingresar una cantidad mayor a 0." << endl;
            return;
        }

        cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
        
        for (int i = 0; i < cantidad; i++) {
            if (fila->estaVacia()) {
                cout << "Ya no hay mas pacientes en la fila." << endl;
                break;
            }

            // sacamos al paciente de la cola (fifo)
            Paciente* p = fila->goOut();
            
            cout << "\nID: " << p->getId() << endl;
            cout << "Nombre: " << p->getNombre() << endl;
            cout << "Edad: " << p->getEdad() << endl;
            cout << "Servicio: " << p->getServicio() << endl;

            // buscamos el depto
            NodoServicio* depto = hospital->buscarServicio(p->getServicio());
            
            if (depto != nullptr) {
                // lo metemos en la lista del depto
                depto->getListaPacientes()->agregarPaciente(p);
                cout << "Paciente enviado a " << p->getServicio() << "." << endl;
                historial->push(p->getNombre(), p->getEdad(), p->getServicio());
            } else {
                cout << "ERROR: El servicio '" << p->getServicio() << "' no existe en el hospital." << endl;
                // si el depto no existe liberar memory
                delete p; 
            }
        }
    } catch (...) {
        cout << "Error: Ingrese un numero valido." << endl;
    }
}

int main() {

    Hospital* hospitalMarmaja = new Hospital();
    ColaPacientes* filaEspera = new ColaPacientes();
    cargarPacientes(filaEspera);
    PilaHistorial* historial = new PilaHistorial();

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
                atenderPacientes(filaEspera, hospitalMarmaja, historial);
            } else if (choice == "2") {
                cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
                hospitalMarmaja->mostrarDepartamentos();
            } else if (choice == "3") {
                cout << "=== HISTORIAL DE ATENCIONES (LIFO) ===" << endl;
                historial->mostrarHistorial();
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