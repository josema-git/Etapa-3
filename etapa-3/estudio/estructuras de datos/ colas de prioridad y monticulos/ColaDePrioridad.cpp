#include <iostream>

using namespace std;

// Cola de prioridad
template <typename T>
class ColaDePrioridad
{
private:
    // Estructura del nodo que contiene el valor y la prioridad
    struct Nodo
    {
        T valor;
        int prioridad;
        Nodo *siguiente;
    } *Cabeza; // Puntero a la cabeza de la cola

public:
    ColaDePrioridad(); // Constructor
    ~ColaDePrioridad(); // Destructor
    void insertar_nodo(T, int); // Método para insertar un nodo
    T borrar_nodo(); // Método para borrar un nodo
    int imprimir_cola(); // Método para imprimir la cola
};

// Constructor: inicializa la cabeza de la cola a NULL
template <typename T>
ColaDePrioridad<T>::ColaDePrioridad()
{
    Cabeza = NULL;
}

// Destructor: libera la memoria de todos los nodos
template <typename T>
ColaDePrioridad<T>::~ColaDePrioridad()
{
    Nodo *aux1 = Cabeza;
    while (Cabeza)
    {
        aux1 = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux1;
    }
}

// Método para insertar un nodo en la cola de prioridad
template <typename T>
void ColaDePrioridad<T>::insertar_nodo(T valor, int prioridad)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    nuevo_nodo->prioridad = prioridad;
    nuevo_nodo->siguiente = NULL;

    // Si la cola está vacía, el nuevo nodo se convierte en la cabeza
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        return;
    }

    // Si la prioridad del nuevo nodo es menor que la de la cabeza, se inserta al principio
    if (Cabeza->prioridad > prioridad)
    {
        nuevo_nodo->siguiente = Cabeza;
        Cabeza = nuevo_nodo;
        return;
    }

    // Busca la posición correcta para insertar el nuevo nodo
    Nodo *aux1 = Cabeza;
    while (aux1->siguiente && aux1->siguiente->prioridad <= prioridad)
    {
        aux1 = aux1->siguiente;
    }
    nuevo_nodo->siguiente = aux1->siguiente;
    aux1->siguiente = nuevo_nodo;
}

// Método para imprimir la cola de prioridad
template <typename T>
int ColaDePrioridad<T>::imprimir_cola()
{
    if (!Cabeza)
    {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    Nodo *aux = Cabeza;
    while (aux)
    {
        cout << aux->valor << " ";
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

// Método para borrar el nodo con la mayor prioridad (el primero en la cola)
template <typename T>
T ColaDePrioridad<T>::borrar_nodo()
{
    if (Cabeza)
    {
        Nodo *aux1 = Cabeza;
        T valor = Cabeza->valor;
        Cabeza = Cabeza->siguiente;
        delete aux1;
        return valor;
    }
    else
    {
        return -1; // Si la cola está vacía, retorna -1
    }
}

int main()
{
    // Crear una cola de prioridad de enteros
    ColaDePrioridad<int> *coladeprioridad = new ColaDePrioridad<int>;
    coladeprioridad->insertar_nodo(1, 1);
    coladeprioridad->insertar_nodo(3, 3);
    coladeprioridad->insertar_nodo(7, 7);
    coladeprioridad->insertar_nodo(5, 5);
    coladeprioridad->insertar_nodo(6, 6);
    coladeprioridad->insertar_nodo(4, 4);
    coladeprioridad->insertar_nodo(2, 2);

    // Imprimir la cola de prioridad
    coladeprioridad->imprimir_cola();

    // Borrar el nodo con la mayor prioridad y volver a imprimir la cola
    coladeprioridad->borrar_nodo();
    coladeprioridad->imprimir_cola();

    // Liberar la memoria de la cola de prioridad
    delete coladeprioridad;

    return 0;
}