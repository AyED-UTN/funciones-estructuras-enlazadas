# Funciones y Estructuras Enlazadas

Repositorio con implementaciones de funciones para operar con estructuras de datos enlazadas fundamentales: **Pila**, **Cola** y **Lista Enlazada Simple**.

## 📋 Descripción

Este proyecto proporciona implementaciones completas y documentadas de tres estructuras de datos clásicas en C++:

- **Pila (Stack)**: Estructura LIFO (Last In, First Out)
- **Cola (Queue)**: Estructura FIFO (First In, First Out)  
- **Lista Enlazada (Linked List)**: Estructura lineal con acceso secuencial

---

## 📁 Estructura del Proyecto

```
funciones-estructuras-enlazadas/
├── nodo.h                 # Definición de la estructura Nodo
├── pila.cpp              # Implementación de Pila (Stack)
├── cola.cpp              # Implementación de Cola (Queue)
├── lista.cpp             # Implementación de Lista Enlazada
└── README.md             # Este archivo
```

---

## 🔧 Requisitos

- **Compilador C++**: g++, clang++ o MSVC (C++11 o superior)
- **Sistema Operativo**: Windows, Linux o macOS

---

## 📦 Componentes

### nodo.h
Estructura base para todos los datos:
```cpp
struct Nodo {
    int info;           // Valor almacenado
    Nodo *sig;          // Puntero al siguiente nodo
};

Nodo *crearNodo(int valor);  // Función para crear nodos
```

### pila.cpp
Implementación de **Pila (Stack)** - LIFO:

**Funciones:**
- `void push(Nodo *&pila, int valor)` - Inserta elemento en la cima
- `int pop(Nodo *&pila)` - Extrae elemento de la cima
- `bool estaVacia(Nodo *pila)` - Verifica si está vacía
- `int main()` - Ejemplo de uso

**Características:**
- Operaciones en O(1)
- Manejo automático de memoria
- Validación de pila vacía

### cola.cpp
Implementación de **Cola (Queue)** - FIFO:

**Funciones:**
- `void agregar(Nodo *&p, Nodo *&q, int valor)` - Inserta al final
- `int desencolar(Nodo *&p, Nodo *&q)` - Extrae del frente
- `bool estaVacia(Nodo *p)` - Verifica si está vacía
- `int main()` - Ejemplo de uso

**Características:**
- Operaciones en O(1)
- Mantiene punteros a frente y final
- Actualización automática de punteros

### lista.cpp
Implementación de **Lista Enlazada Simple**:

**Funciones Básicas:**
- `void imprimirLista(Nodo *inicio)` - Imprime todos los elementos
- `Nodo *cargarLista(Nodo *inicio, int valor)` - Inserta al final
- `Nodo *buscarElemento(Nodo *inicio, int valor)` - Busca por valor
- `void recorrerLista(Nodo *inicio)` - Recorre e imprime
- `Nodo *eliminarNodo(Nodo *inicio, int valor)` - Elimina un nodo
- `Nodo *insertarOrdenado(Nodo *inicio, int valor)` - Inserta ordenado

**Funciones Avanzadas:**
- `int contarElementos(Nodo *inicio)` - Cuenta total de nodos
- `int obtenerElemento(Nodo *inicio, int posicion)` - Accede por índice
- `Nodo *destruirLista(Nodo *inicio)` - Libera toda la memoria
- `int buscarIndice(Nodo *inicio, int valor)` - Encuentra la posición
- `Nodo *invertirLista(Nodo *inicio)` - Invierte el orden

---

## 🚀 Cómo Compilar

### Usando g++ (Linux/macOS/MinGW)
```bash
# Compilar pila.cpp
g++ -o pila pila.cpp -Wall -std=c++11

# Compilar cola.cpp
g++ -o cola cola.cpp -Wall -std=c++11

# Compilar lista.cpp
g++ -o lista lista.cpp -Wall -std=c++11
```

### Usando MSVC (Visual Studio)
```bash
cl pila.cpp
cl cola.cpp
cl lista.cpp
```

### Usar Clang
```bash
clang++ -o pila pila.cpp -Wall -std=c++11
clang++ -o cola cola.cpp -Wall -std=c++11
clang++ -o lista lista.cpp -Wall -std=c++11
```

---

## 📖 Ejemplos de Uso

### Pila
```cpp
Nodo *pila = nullptr;
push(pila, 10);
push(pila, 20);
push(pila, 30);

while (!estaVacia(pila)) {
    cout << pop(pila) << " ";  // Salida: 30 20 10
}
```

### Cola
```cpp
Nodo *frente = nullptr, *final = nullptr;
agregar(frente, final, 10);
agregar(frente, final, 20);
agregar(frente, final, 30);

while (!estaVacia(frente)) {
    cout << desencolar(frente, final) << " ";  // Salida: 10 20 30
}
```

### Lista Enlazada
```cpp
Nodo *lista = nullptr;
lista = cargarLista(lista, 10);
lista = cargarLista(lista, 20);
lista = cargarLista(lista, 30);

cout << "Elementos: ";
imprimirLista(lista);  // Salida: 10 20 30

cout << "Total: " << contarElementos(lista);  // Salida: 3

lista = eliminarNodo(lista, 20);
cout << "Después de eliminar: ";
imprimirLista(lista);  // Salida: 10 30

lista = destruirLista(lista);  // Libera memoria
```

---

## 🎯 Diferencias entre Estructuras

| Aspecto | Pila | Cola | Lista |
|---------|------|------|-------|
| **Orden** | LIFO | FIFO | Variable |
| **Inserción** | Solo cima | Solo final | Cualquier posición |
| **Eliminación** | Solo cima | Solo frente | Cualquier nodo |
| **Acceso** | Solo cima | Solo frente | Acceso secuencial |
| **Caso de Uso** | Recursión, deshacer | Colas de espera | Iteración general |