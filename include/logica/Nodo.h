#pragma once
#include "dominio/Paciente.h"

class Nodo {
public:
    Paciente paciente; // La carga
    Nodo* siguiente;   // puntero

    // Constructor del nodo
    Nodo(Paciente p) : paciente(p), siguiente(nullptr) {}
};