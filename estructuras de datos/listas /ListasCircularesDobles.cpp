#include <iostream>

using namespace std;

// Definición de la clase plantilla para una lista circular doblemente enlazada
template <typename T>
class ListaCircularDoble
{
private:
    // Estructura del nodo de la lista
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
        Nodo *anterior;
    } *Cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor
    ListaCircularDoble();
    // Destructor
    ~ListaCircularDoble();
    // Métodos para insertar y borrar nodos
    T insertar_nodo(T);
    T borrar_nodo(T);
    // Métodos para imprimir, organizar y reversar la lista
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

// Constructor: inicializa la lista vacía
template <typename T>
ListaCircularDoble<T>::ListaCircularDoble()
{
    Cabeza = NULL;
    cout << "Se ha creado una lista circular doble" << endl;
}

// Destructor: libera la memoria de todos los nodos
template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble()
{
    if (Cabeza)
    {
        Nodo *aux1 = Cabeza;
        Nodo *aux2;
        // Recorre la lista y elimina cada nodo
        while (aux1->siguiente != Cabeza)
        {
            aux2 = aux1;
            aux1 = aux1->siguiente;
            delete aux2;
        }
        delete aux1;
    }
    cout << "Se ha destruido una lista circular doble" << endl;
}

// Método para insertar un nodo con un valor dado
template <typename T>
T ListaCircularDoble<T>::insertar_nodo(T valor)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    if (!Cabeza)
    {
        // Si la lista está vacía, el nuevo nodo es el único nodo
        Cabeza = nuevo_nodo;
        Cabeza->siguiente = nuevo_nodo;
        Cabeza->anterior = nuevo_nodo;
        return valor;
    }
    Nodo *aux = Cabeza;
    // Recorre la lista hasta el último nodo
    while (aux->siguiente != Cabeza)
    {
        aux = aux->siguiente;
    }
    // Inserta el nuevo nodo al final de la lista
    aux->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = aux;
    nuevo_nodo->siguiente = Cabeza;
    Cabeza->anterior = nuevo_nodo;
    return valor;
}

// Método para borrar un nodo con un valor dado
template <typename T>
T ListaCircularDoble<T>::borrar_nodo(T valor)
{
    if (!Cabeza)
    {
        return -1; // Lista vacía
    }
    Nodo *aux1 = Cabeza;
    if (Cabeza->valor == valor)
    {
        if (Cabeza->siguiente == Cabeza)
        {
            // Si la lista tiene un solo nodo
            delete Cabeza;
            Cabeza = NULL;
            return valor;
        }
        // Recorre la lista hasta el último nodo
        while (aux1->siguiente != Cabeza)
        {
            aux1 = aux1->siguiente;
        }
        // Elimina el nodo cabeza y ajusta los punteros
        aux1->siguiente = Cabeza->siguiente;
        aux1 = Cabeza;
        Cabeza = Cabeza->siguiente;
        Cabeza->anterior = aux1->anterior;
        delete aux1;
        return valor;
    }
    Nodo *aux2;
    // Recorre la lista buscando el nodo a eliminar
    while (aux1->siguiente != Cabeza)
    {
        if (aux1->siguiente->valor == valor)
        {
            aux2 = aux1->siguiente;
            aux1->siguiente = aux2->siguiente;
            aux2->siguiente->anterior = aux1;
            delete aux2;
            return valor;
            break;
        }
        else
        {
            aux1 = aux1->siguiente;
        }
    }
    return valor;
}

// Método para imprimir los valores de la lista
template <typename T>
int ListaCircularDoble<T>::imprimir_lista()
{
    if (!Cabeza)
    {
        cout << "No hay elementos en la lista" << endl;
        return -1;
    }
    Nodo *aux = Cabeza->siguiente;
    cout << Cabeza->valor;
    // Recorre la lista e imprime cada valor
    while (aux != Cabeza)
    {
        cout << " <-> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

// Método para organizar la lista en orden ascendente
template <typename T>
int ListaCircularDoble<T>::organizar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    // Algoritmo de ordenamiento burbuja
    while (aux1->siguiente != Cabeza)
    {
        aux2 = aux1->siguiente;
        while (aux2 != Cabeza)
        {
            if (aux1->valor > aux2->valor)
            {
                T temp = aux2->valor;
                aux2->valor = aux1->valor;
                aux1->valor = temp;
            }
            aux2 = aux2->siguiente;
        }
        aux1 = aux1->siguiente;
    }
    return 1;
}

// Método para invertir el orden de la lista
template <typename T>
int ListaCircularDoble<T>::reversar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *actual = Cabeza;
    Nodo *previo = NULL;
    Nodo *siguiente = NULL;
    // Recorre la lista e invierte los punteros
    do
    {
        siguiente = actual->siguiente;
        actual->siguiente = previo;
        actual->anterior = siguiente;
        previo = actual;
        actual = siguiente;
    } while (actual != Cabeza);
    Cabeza->siguiente = previo;
    Cabeza = previo;
    return 1;
}

int main()
{
    // Crea una lista circular doble de enteros
    ListaCircularDoble<int> *listacirculardoble = new ListaCircularDoble<int>;
    // Inserta varios nodos en la lista
    listacirculardoble->insertar_nodo(1);
    listacirculardoble->insertar_nodo(3);
    listacirculardoble->insertar_nodo(7);
    listacirculardoble->insertar_nodo(5);
    listacirculardoble->insertar_nodo(6);
    listacirculardoble->insertar_nodo(4);
    listacirculardoble->insertar_nodo(2);
    // Imprime la lista
    listacirculardoble->imprimir_lista();
    // Organiza la lista
    listacirculardoble->organizar_lista();
    // Imprime la lista organizada
    listacirculardoble->imprimir_lista();
    // Invierte la lista
    listacirculardoble->reversar_lista();
    // Imprime la lista invertida
    listacirculardoble->imprimir_lista();
    // Libera la memoria de la lista
    delete listacirculardoble;

    return 0;
}