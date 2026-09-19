#pragma once
#include <string>

class Persona {
protected: 
    std::string id;
    std::string nombre;
    int edad;

public:
    Persona(std::string _id, std::string _nombre, int _edad);
    std::string getId();
    std::string getNombre();
    int getEdad();
};