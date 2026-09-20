#include "logica/Hospital.h"

Hospital::Hospital() { cabeza = nullptr; }

Hospital::~Hospital() {
    NodoServicio* actual = cabeza;
    while (actual != nullptr) {
        NodoServicio* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Hospital::agregarServicio(std::string nombre) {
    NodoServicio* nuevo = new NodoServicio(nombre);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoServicio* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void Hospital::inicializarServiciosBase() {
    agregarServicio("Urgencias");
    agregarServicio("Medicina General");
    agregarServicio("Cardiologia");
    agregarServicio("Neurologia");
    agregarServicio("Traumatologia");
    agregarServicio("Cirugia");
    agregarServicio("Pediatria");
    agregarServicio("Hospitalizacion");
}

void Hospital::derivarPaciente(Paciente p) {
    NodoServicio* actual = cabeza;
    while (actual != nullptr) {
        
        if (actual->nombreServicio == p.getServicio()) {
            actual->listaPacientes.insertarPaciente(p);
            return;
        }
        actual = actual->siguiente;
    }
    std::cout << "Error: Servicio " << p.getServicio() << " no encontrado para " << p.getNombre() << std::endl;
}

void Hospital::mostrarEstadoServicios() {
    NodoServicio* actual = cabeza;
    std::cout << "\n=== ESTADO DE DEPARTAMENTOS ===" << std::endl;
    while (actual != nullptr) {
        int cantidad = actual->listaPacientes.contarPacientes();
        std::cout << actual->nombreServicio << " - Pacientes: " << cantidad << std::endl;
        actual->listaPacientes.mostrarPacientes();
        actual = actual->siguiente;
    }
}