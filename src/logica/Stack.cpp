#include "logica/Stack.h"

Stack::Stack() {
    tope = nullptr;
}

Stack::~Stack() {
    while (!estaVacia()) {
        pop();
    }
}

bool Stack::estaVacia() {
    return tope == nullptr;
}

void Stack::push(Paciente p) {
    Nodo* nuevo = new Nodo(p);
    nuevo->siguiente = tope;
    tope = nuevo;
}

void Stack::pop() {
    if (!estaVacia()) {
        Nodo* aux = tope;
        tope = tope->siguiente;
        delete aux;
    }
}

void Stack::mostrarHistorial() {
    Nodo* actual = tope;
    std::cout << "=== HISTORIAL DE ÚLTIMAS ATENCIONES ===" << std::endl;
    while (actual != nullptr) {
        std::cout << "Nombre: " << actual->paciente.getNombre() 
                  << " | Edad: " << actual->paciente.getEdad() 
                  << " | Departamento: " << actual->paciente.getServicio() << std::endl;
        actual = actual->siguiente;
    }
    std::cout << "--" << std::endl;
}