#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dominio/Paciente.h"
#include "logica/Queue.h"
#include "logica/Hospital.h" 

using namespace std;

void cargarPacientesDesdeArchivo(Queue& cola, string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    string linea;

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo en " << rutaArchivo << endl;
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
    cout << "Pacientes cargados exitosamente." << endl << endl;
}

int main() {
    Queue colaEspera;
    
    Hospital miHospital; 

    miHospital.inicializarServiciosBase(); 

    cargarPacientesDesdeArchivo(colaEspera, "data/pacientes_prueba.txt");

    cout << "--- ESTADO INICIAL ---" << endl;
    colaEspera.mostrarCola();

    cout << "\n=== ATENDIENDO AL PRIMER PACIENTE ===" << endl;
    if (!colaEspera.estaVacia()) {
        Paciente p = colaEspera.desencolar(); 
        miHospital.derivarPaciente(p);        
        cout << "Paciente " << p.getNombre() << " derivado a " << p.getServicio() << endl;
    }

    miHospital.mostrarEstadoServicios();

    return 0;
}