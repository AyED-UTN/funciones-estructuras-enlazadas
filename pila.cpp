#include "nodo.h"
#include <iostream>
using namespace std;

/**
 * @function push
 * @brief Inserta un nuevo elemento en la cima de la pila
 *
 * Crea un nuevo nodo con el valor especificado y lo coloca al frente
 * de la pila, convirtiéndolo en el nuevo nodo de la cima.
 *
 * @param pila Referencia al puntero de la pila (se modifica)
 * @param valor Valor entero a insertar en la pila
 * @return void
 */
void push(Nodo *&pila, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    nuevoNodo->sig = pila;
    pila = nuevoNodo;
}

/**
 * @function pop
 * @brief Elimina y devuelve el elemento de la cima de la pila
 *
 * Obtiene el valor del nodo que se encuentra en la cima de la pila,
 * elimina ese nodo de la memoria y actualiza el puntero de la pila
 * para que apunte al siguiente nodo.
 *
 * @param pila Referencia al puntero de la pila (se modifica)
 * @return int El valor del nodo eliminado, o -1 si la pila está vacía
 *
 * Nota: Si la pila está vacía, imprime un mensaje de error y retorna -1
 */
int pop(Nodo *&pila)
{
    if (pila == nullptr)
    {
        cout << "La pila esta vacia." << endl;
        return -1; // valor de error
    }
    int valor = pila->info;
    Nodo *temp = pila;
    pila = pila->sig;
    delete temp;
    return valor;
}

/**
 * @function estaVacia
 * @brief Verifica si la pila está vacía
 *
 * Comprueba si el puntero de la pila es nulo, lo que indica
 * que no hay ningún elemento en la pila.
 *
 * @param pila Puntero al primer nodo de la pila
 * @return bool true si la pila está vacía, false en caso contrario
 *
 */
bool estaVacia(Nodo *pila)
{
    return pila == nullptr;
}

/**
 * @function main
 * @brief Función principal que demuestra el uso de la pila
 *
 * Crea una pila vacía, inserta tres elementos (10, 20, 30)
 * y luego los extrae uno a uno de la cima hacia el fondo,
 * mostrándolos en pantalla.
 *
 * @return int Código de salida del programa (0 si se ejecutó correctamente)
 */
int main()
{
    Nodo *pila = nullptr; // pila vacia
    push(pila, 10);
    push(pila, 20);
    push(pila, 30);
    cout << "Elementos de la pila (de la cima al fondo):" << endl;
    while (!estaVacia(pila))
    {
        cout << pop(pila) << " ";
    }
    cout << endl;
    return 0;
}