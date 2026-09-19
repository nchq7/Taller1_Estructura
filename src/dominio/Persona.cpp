#include "dominio/Persona.h"

Persona::Persona(std::string _id, std::string _nombre, int _edad) {
    id = _id;
    nombre = _nombre;
    edad = _edad;
}

std::string Persona::getId() { return id; }
std::string Persona::getNombre() { return nombre; }
int Persona::getEdad() { return edad; }