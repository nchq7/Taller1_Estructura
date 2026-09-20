# Taller 1: Estructura de Datos - Hospital Marmaja

Este sistema es una simulación de gestión hospitalaria desarrollada en C++. El proyecto aplica conceptos de Programación Orientada a Objetos (POO), administración de memoria dinámica mediante punteros y construcción manual de estructuras de datos (Listas Enlazadas, Colas y Pilas)

## Integrantes

* **Nombre:** Ignacio Valdivia
* **RUT:** 22.179.357-9
* **Nombre en GitHub:** @nchq7
* **Carrera:** ICCI

## Arquitectura del Proyecto

El código está organizado en carpetas distintas para separar la estructura de las clases de su funcionamiento real:
* `include/`: Archivos de cabecera (`.h`) organizados en los subdirectorios `dominio/` y `logica/`.
* `src/`: Implementación del código (`.cpp`), incluyendo la lógica del sistema y el archivo de entrada `main.cpp`.
* `data/`: Almacena el archivo de texto base necesario para las pruebas (`pacientes_prueba.txt`).

## Instrucciones de Compilación y Ejecución

Para evaluar el sistema, abra la terminal en la raíz del proyecto y asegúrese de contar con el compilador `g++` (estándar C++17).

### 1. Compilación
Ejecute la siguiente instrucción para enlazar las cabeceras y compilar todos los archivos en un ejecutable unificado:

`g++ -std=c++17 -Iinclude src/dominio/*.cpp src/logica/*.cpp src/main.cpp -o hospital.exe`

### 2. Ejecución
Una vez que el archivo `.exe` se genere sin errores, inicie el sistema de gestión con:

.\hospital.exe

### 3. Consideraciones importantes
El programa lee automáticamente la ruta `data/pacientes_prueba.txt`. Asegúrese de que esa carpeta y archivo existan en la raíz del proyecto antes de iniciar la ejecución.
