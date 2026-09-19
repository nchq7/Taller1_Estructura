#pragma once
#include "logica/Nodo.h"
#include <iostream>

class Queue {
private:
    Nodo* frente; // puntero al primer paciente de la fila
    Nodo* final;  // puntero al último paciente de la fila

public:
    Queue();
    ~Queue(); // destructor 
    
    void encolar(Paciente p);   
    Paciente desencolar();      
    bool estaVacia();
    void mostrarCola();         
};