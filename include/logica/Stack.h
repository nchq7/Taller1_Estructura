#pragma once
#include "logica/Nodo.h"
#include <iostream>

class Stack {
private:
    Nodo* tope;
public:
    Stack();
    ~Stack();
    void push(Paciente p);
    void pop();
    void mostrarHistorial();
    bool estaVacia();
};