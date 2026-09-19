#include <iostream>
#include "dominio/Paciente.h"

using namespace std;

int main() {
    // instanciamos un paciente de prueba
    Paciente p1("001", "Juan Perez", 25, "Cardiologia");

    cout << "Paciente creado exitosamente: " << p1.getNombre() << " - " << p1.getServicio() << endl;

    return 0;
}