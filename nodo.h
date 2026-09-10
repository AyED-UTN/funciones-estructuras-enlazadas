#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <cstddef>

using namespace std;

/**
 * @struct Nodo
 * @brief Estructura que representa un nodo de una lista enlazada
 *
 * Contiene un valor entero y un puntero al siguiente nodo
 */
struct Nodo
{
    int info;  // Información almacenada en el nodo
    Nodo *sig; // Puntero al siguiente nodo
};

/**
 * @function crearNodo
 * @brief Crea un nuevo nodo con un valor inicial
 *
 * @param valor El valor entero a almacenar en el nodo
 * @return Puntero al nuevo nodo creado
 */
Nodo *crearNodo(int valor)
{
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->info = valor;
    nuevoNodo->sig = nullptr;
    return nuevoNodo;
}

#endif // NODO_H
