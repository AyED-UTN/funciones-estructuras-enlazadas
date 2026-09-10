#include "nodo.h"
#include <iostream>
using namespace std;

/**
 * @function imprimirLista
 * @brief Recorre e imprime todos los elementos de una lista enlazada
 *
 * Inicia en el nodo especificado y recorre secuencialmente todos los
 * nodos de la lista enlazada, imprimiendo el valor de información
 * de cada uno en una sola línea, separados por espacios.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @return void
 *
 */
void imprimirLista(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        cout << actual->info << " ";
        actual = actual->sig;
    }
    cout << endl;
}

/**
 * @function cargarLista
 * @brief Inserta un nuevo elemento al final de la lista
 *
 * Crea un nuevo nodo con el valor especificado y lo inserta
 * al final de la lista enlazada. Si la lista está vacía,
 * el nuevo nodo se convierte en el inicio de la lista.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param valor Valor entero a insertar al final
 * @return Nodo* Puntero al inicio de la lista actualizada
 */
Nodo *cargarLista(Nodo *inicio, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    if (inicio == nullptr)
    {
        inicio = nuevoNodo;
    }
    else
    {
        Nodo *actual = inicio;
        while (actual->sig != nullptr)
        {
            actual = actual->sig;
        }
        actual->sig = nuevoNodo;
    }
    return inicio;
}

/**
 * @function buscarElemento
 * @brief Busca un elemento en la lista por su valor
 *
 * Recorre la lista enlazada comparando cada nodo con el valor
 * buscado. Retorna el puntero al nodo que contiene el valor,
 * o nullptr si no se encuentra.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param valor Valor entero a buscar
 * @return Nodo* Puntero al nodo encontrado, o nullptr si no existe
 */
Nodo *buscarElemento(Nodo *inicio, int valor)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        if (actual->info == valor)
        {
            return actual; // devuelve el nodo que contiene el valor
        }
        actual = actual->sig;
    }
    return nullptr; // no se encontro
}

/**
 * @function recorrerLista
 * @brief Recorre e imprime todos los elementos de la lista
 *
 * Itera a través de todos los nodos de la lista, mostrando
 * el valor de información de cada uno separados por espacios.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @return void
 */
void recorrerLista(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        cout << actual->info << " ";
        actual = actual->sig;
    }
    cout << endl;
}

/**
 * @function eliminarNodo
 * @brief Elimina el primer nodo con un valor especificado
 *
 * Busca y elimina el primer nodo que contiene el valor especificado.
 * Si el nodo a eliminar es el primero, actualiza el inicio de la lista.
 * Libera la memoria del nodo eliminado.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param valor Valor del nodo a eliminar
 * @return Nodo* Puntero al inicio de la lista actualizada
 */
Nodo *eliminarNodo(Nodo *inicio, int valor)
{
    if (inicio == nullptr)
    {
        return nullptr; // lista vacia
    }
    if (inicio->info == valor)
    { // el valor esta en el primer nodo
        Nodo *temp = inicio;
        inicio = inicio->sig;
        delete temp;
        return inicio;
    }
    Nodo *actual = inicio;
    while (actual->sig != nullptr)
    {
        if (actual->sig->info == valor)
        {
            Nodo *temp = actual->sig;
            actual->sig = actual->sig->sig;
            delete temp;
            return inicio;
        }
        actual = actual->sig;
    }
    return inicio; // valor no encontrado
}

/**
 * @function insertarOrdenado
 * @brief Inserta un elemento manteniendo la lista en orden ascendente
 *
 * Crea un nuevo nodo y lo inserta en la posición correcta para
 * mantener la lista ordenada de menor a mayor. Funciona correctamente
 * con listas vacías.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param valor Valor entero a insertar en orden
 * @return Nodo* Puntero al inicio de la lista actualizada
 */
Nodo *insertarOrdenado(Nodo *inicio, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    // Caso especial: lista vacia o el valor va primero
    if (inicio == nullptr || valor < inicio->info)
    {
        nuevoNodo->sig = inicio;
        return nuevoNodo;
    }
    Nodo *actual = inicio;
    while (actual->sig != nullptr && actual->sig->info < valor)
    {
        actual = actual->sig;
    }
    nuevoNodo->sig = actual->sig;
    actual->sig = nuevoNodo;
    return inicio;
}

/**
 * @function contarElementos
 * @brief Cuenta la cantidad total de elementos en la lista
 *
 * Recorre toda la lista enlazada contando cada nodo desde
 * el inicio hasta el final.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @return int Número total de elementos en la lista
 */
int contarElementos(Nodo *inicio)
{
    int contador = 0;
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        contador++;
        actual = actual->sig;
    }
    return contador;
}

/**
 * @function obtenerElemento
 * @brief Obtiene el valor del elemento en una posición específica
 *
 * Accede al elemento ubicado en la posición indicada (basado en 0).
 * Si la posición es inválida, retorna -1.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param posicion Índice del elemento a obtener (comienza en 0)
 * @return int Valor del elemento o -1 si la posición es inválida
 */
int obtenerElemento(Nodo *inicio, int posicion)
{
    int indice = 0;
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        if (indice == posicion)
        {
            return actual->info;
        }
        indice++;
        actual = actual->sig;
    }
    return -1; // posición no encontrada
}

/**
 * @function destruirLista
 * @brief Libera toda la memoria asignada a la lista
 *
 * Recorre la lista enlazada eliminando todos los nodos
 * y liberando su memoria. Al terminar, la lista está vacía.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @return Nodo* nullptr (lista destruida)
 */
Nodo *destruirLista(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        Nodo *temp = actual;
        actual = actual->sig;
        delete temp;
    }
    return nullptr;
}

/**
 * @function buscarIndice
 * @brief Encuentra el índice (posición) de un elemento por su valor
 *
 * Busca el elemento con el valor especificado y retorna su posición
 * en la lista (basado en 0). Si no se encuentra, retorna -1.
 *
 * @param inicio Puntero al primer nodo de la lista
 * @param valor Valor a buscar
 * @return int Índice del elemento o -1 si no existe
 */
int buscarIndice(Nodo *inicio, int valor)
{
    int indice = 0;
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        if (actual->info == valor)
        {
            return indice;
        }
        indice++;
        actual = actual->sig;
    }
    return -1; // no encontrado
}

/**
 * @function invertirLista
 * @brief Invierte el orden de todos los elementos de la lista
 *
 * Reorganiza los punteros de los nodos de manera que la lista
 * queda en orden inverso. El último nodo se convierte en el primero.
 *
 * @param inicio Puntero al primer nodo de la lista original
 * @return Nodo* Puntero al nuevo inicio de la lista invertida
 */
Nodo *invertirLista(Nodo *inicio)
{
    Nodo *anterior = nullptr;
    Nodo *actual = inicio;
    Nodo *siguiente = nullptr;

    while (actual != nullptr)
    {
        siguiente = actual->sig; // guardar siguiente nodo
        actual->sig = anterior;  // invertir el enlace
        anterior = actual;       // avanzar anterior
        actual = siguiente;      // avanzar actual
    }
    return anterior; // nuevo inicio
}

/**
 * @function main
 * @brief Función principal que demuestra el uso de una lista enlazada
 *
 * Crea una lista enlazada con tres nodos (10, 20, 30), la imprime
 * en pantalla y luego libera toda la memoria asignada dinámicamente
 * en orden inverso.
 *
 * @return int Código de salida del programa (0 si se ejecutó correctamente)
 */
int main()
{
    Nodo *lista = crearNodo(10);
    lista->sig = crearNodo(20);
    lista->sig->sig = crearNodo(30);
    cout << "Lista: ";
    imprimirLista(lista);
    // Liberar la memoria al final
    delete lista->sig->sig;
    delete lista->sig;
    delete lista;
    return 0;
}
