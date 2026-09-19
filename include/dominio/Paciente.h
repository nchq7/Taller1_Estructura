#pragma once
#include "dominio/Persona.h"
#include <string>

class Paciente : public Persona {
private:
    std::string servicio;

public:
    Paciente(std::string _id, std::string _nombre, int _edad, std::string _servicio);
    std::string getServicio();
};