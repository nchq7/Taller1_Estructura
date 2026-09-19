#include "dominio/Paciente.h"

Paciente::Paciente(std::string _id, std::string _nombre, int _edad, std::string _servicio) 
    : Persona(_id, _nombre, _edad) {
    servicio = _servicio;
}

std::string Paciente::getServicio() { return servicio; }