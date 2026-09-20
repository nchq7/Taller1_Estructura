#include "logica/ListaPacientes.h"

ListaPacientes::ListaPacientes() { cabeza = nullptr; }

ListaPacientes::~ListaPacientes() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaPacientes::insertarPaciente(Paciente p) {
    Nodo* nuevo = new Nodo(p);
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

int ListaPacientes::contarPacientes() {
    int contador = 0;
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void ListaPacientes::mostrarPacientes() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << " - " << actual->paciente.getNombre() << " (" << actual->paciente.getEdad() << " años)" << std::endl;
        actual = actual->siguiente;
    }
}