#pragma once
#include <string>
#include "logica/ListaPacientes.h"

class NodoServicio {
public:
    std::string nombreServicio;
    ListaPacientes listaPacientes; 
    NodoServicio* siguiente;

    NodoServicio(std::string nombre) {
        nombreServicio = nombre;
        siguiente = nullptr;
    }
};