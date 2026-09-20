#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dominio/Paciente.h"
#include "logica/Queue.h"
#include "logica/Hospital.h"
#include "logica/Stack.h"

using namespace std;

void cargarPacientesDesdeArchivo(Queue& cola, string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    string linea;

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, nombre, edadStr, servicio;

        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, edadStr, ';');
        getline(ss, servicio, ';');

        int edad = stoi(edadStr);
        Paciente nuevoPaciente(id, nombre, edad, servicio);
        cola.encolar(nuevoPaciente);
    }
    archivo.close();
}

void inicializarServicios(Hospital& hosp) {
    string nombres[] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};
    string* ptr = nombres;
    
    for (int i = 0; i < 8; i++) {
        hosp.agregarServicio(*(ptr + i));
    }
}

int main() {
    Queue colaEspera;
    Hospital miHospital;
    Stack historial;

    inicializarServicios(miHospital);
    cargarPacientesDesdeArchivo(colaEspera, "data/pacientes_prueba.txt");

    int opcion = 0;

    while (opcion != 4) {
        cout << "\n=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
        }

        if (opcion == 1) {
            colaEspera.mostrarCola();
            
            int cantidad;
            cout << "\nIndique la cantidad de pacientes a atender: ";
            cin >> cantidad;
            
            cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
            for (int i = 0; i < cantidad; i++) {
                if (!colaEspera.estaVacia()) {
                    Paciente p = colaEspera.desencolar();
                    miHospital.derivarPaciente(p);
                    historial.push(p);
                    cout << "ID: " << p.getId() << endl;
                    cout << "Nombre: " << p.getNombre() << endl;
                    cout << "Edad: " << p.getEdad() << endl;
                    cout << "Servicio: " << p.getServicio() << endl;
                    cout << "Paciente enviado a " << p.getServicio() << "." << endl << endl;
                } else {
                    cout << "No hay mas pacientes en la cola." << endl;
                    break;
                }
            }
        } 
        else if (opcion == 2) {
            miHospital.mostrarEstadoServicios();
        } 
        else if (opcion == 3) {
            historial.mostrarHistorial();
        } 
        else if (opcion == 4) {
            cout << "Hasta luego : D." << endl;
        } 
        else {
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}