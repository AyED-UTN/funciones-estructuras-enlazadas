#include "nodo.h"
#include <iostream>
using namespace std;

/**
 * @function agregar
 * @brief Añade un nuevo elemento al final de la cola
 *
 * Crea un nuevo nodo con el valor especificado y lo inserta al final
 * de la cola. Si la cola está vacía, actualiza tanto el frente (p)
 * como el final (q) para que apunten al nuevo nodo.
 *
 * @param p Referencia al puntero del frente de la cola (se modifica si estaba vacía)
 * @param q Referencia al puntero del final de la cola (siempre se modifica)
 * @param valor Valor entero a insertar en la cola
 * @return void
 *
 */
void agregar(Nodo *&p, Nodo *&q, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);
    if (p == nullptr)
    { // la cola estaba vacia
        p = q = nuevoNodo;
    }
    else
    {
        q->sig = nuevoNodo;
        q = nuevoNodo;
    }
}

/**
 * @function desencolar
 * @brief Elimina y devuelve el elemento del frente de la cola
 *
 * Obtiene el valor del nodo que se encuentra en el frente de la cola,
 * lo elimina de la memoria y actualiza el puntero del frente (p).
 * Si la cola queda vacía después de la eliminación, también actualiza
 * el puntero del final (q).
 *
 * @param p Referencia al puntero del frente de la cola (se modifica)
 * @param q Referencia al puntero del final de la cola (se modifica si queda vacía)
 * @return int El valor del nodo eliminado, o -1 si la cola está vacía
 *
 * Nota: Si la cola está vacía, imprime un mensaje de error y retorna -1
 */
int desencolar(Nodo *&p, Nodo *&q)
{
    if (p == nullptr)
    {
        cout << "La cola esta vacia." << endl;
        return -1; // valor de error
    }
    int valor = p->info;
    Nodo *temp = p;
    p = p->sig;
    if (p == nullptr)
    { // si saque el ultimo, actualizo q
        q = nullptr;
    }
    delete temp;
    return valor;
}

/**
 * @function estaVacia
 * @brief Verifica si la cola está vacía
 *
 * Comprueba si el puntero del frente de la cola es nulo, lo que indica
 * que no hay ningún elemento en la cola.
 *
 * @param p Puntero al frente de la cola
 * @return bool true si la cola está vacía, false en caso contrario
 *
 */
bool estaVacia(Nodo *p)
{
    return p == nullptr;
}

/**
 * @function main
 * @brief Función principal que demuestra el uso de la cola (FIFO)
 *
 * Crea una cola vacía, inserta tres elementos (10, 20, 30)
 * y luego los extrae uno a uno del frente hacia el final,
 * demostrando el comportamiento FIFO (First In, First Out).
 *
 * @return int Código de salida del programa (0 si se ejecutó correctamente)
 */
int main()
{
    Nodo *p = nullptr; // frente
    Nodo *q = nullptr; // final
    agregar(p, q, 10);
    agregar(p, q, 20);
    agregar(p, q, 30);
    cout << "Elementos de la cola (del frente al final):" << endl;
    while (!estaVacia(p))
    {
        cout << desencolar(p, q) << " ";
    }
    cout << endl;
    return 0;
}
