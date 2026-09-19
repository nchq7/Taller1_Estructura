#include "logica/Queue.h"

// Constructor
Queue::Queue() {
    frente = nullptr;
    final = nullptr;
}

// Destructor
Queue::~Queue() {
    while (!estaVacia()) {
        desencolar(); 
    }
}

bool Queue::estaVacia() {
    return frente == nullptr;
}

// Agregar un paciente a la fila
void Queue::encolar(Paciente p) {
    Nodo* nuevoNodo = new Nodo(p); 
    
    if (estaVacia()) {
        frente = nuevoNodo;
        final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo; 
        final = nuevoNodo;            
    }
}

Paciente Queue::desencolar() {
    if (estaVacia()) {
        throw std::runtime_error("La cola esta vacia");
    }
    
    Nodo* nodoAuxiliar = frente;     
    Paciente pacienteAtendido = frente->paciente; 
    
    frente = frente->siguiente;      
    
    if (frente == nullptr) {
        final = nullptr; 
    }
    
    delete nodoAuxiliar; 
    return pacienteAtendido;
}

void Queue::mostrarCola() {
    Nodo* actual = frente;
    int contador = 1;
    std::cout << "=== PACIENTES EN ESPERA ===" << std::endl;
    while (actual != nullptr) {
        std::cout << contador << ". " << actual->paciente.getId() << " " << actual->paciente.getNombre() << std::endl;
        actual = actual->siguiente; 
        contador++;
    }
}