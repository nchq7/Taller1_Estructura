#pragma once
#include "logica/Nodo.h"
#include <iostream>

class ListaPacientes {
private:
    Nodo* cabeza;
public:
    ListaPacientes();
    ~ListaPacientes();
    void insertarPaciente(Paciente p);
    void mostrarPacientes();
    int contarPacientes();
};