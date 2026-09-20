#pragma once
#include "logica/NodoServicio.h"

class Hospital {
private:
    NodoServicio* cabeza;
public:
    Hospital();
    ~Hospital();
    void agregarServicio(std::string nombre);
    void inicializarServiciosBase(); 
    void derivarPaciente(Paciente p);
    void mostrarEstadoServicios();
};