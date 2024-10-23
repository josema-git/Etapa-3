#include <iostream>

using namespace std;

// Definición de la clase ListaDoble
template <typename T>
class ListaDoble
{
private:
    // Estructura del nodo de la lista doblemente enlazada
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
        Nodo *anterior;
    } *Cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor y destructor de la clase
    ListaDoble();
    ~ListaDoble();

    // Métodos para manipular la lista
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

// Constructor: inicializa la lista vacía
template <typename T>
ListaDoble<T>::ListaDoble()
{
    Cabeza = NULL;
    cout << "Se ha creado una lista doble" << endl;
}

// Destructor: libera la memoria de todos los nodos
template <typename T>
ListaDoble<T>::~ListaDoble()
{
    while (Cabeza)
    {
        Nodo *aux = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux;
    }
    cout << "Se ha destruido una lista doble" << endl;
}

// Método para insertar un nodo al final de la lista
template <typename T>
T ListaDoble<T>::insertar_nodo(T x)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = x;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = NULL;

    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        return nuevo_nodo->valor;
    }

    Nodo *aux = Cabeza;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = aux;
    return nuevo_nodo->valor;
}

// Método para borrar un nodo con un valor específico
template <typename T>
T ListaDoble<T>::borrar_nodo(T x)
{
    Nodo *aux1 = Cabeza;

    if (!Cabeza)
    {
        return -1; // Lista vacía
    }
    else if (Cabeza->valor == x)
    {
        Cabeza = Cabeza->siguiente;
        delete aux1;
        return x;
    }

    while (aux1 != NULL)
    {
        if (aux1->valor == x)
        {
            aux1->anterior->siguiente = aux1->siguiente;
            if (aux1->siguiente != NULL)
            {
                aux1->siguiente->anterior = aux1->anterior;
            }
            delete aux1;
            return x;
        }
        aux1 = aux1->siguiente;
    }
    return 0; // Nodo no encontrado
}

// Método para imprimir la lista
template <typename T>
int ListaDoble<T>::imprimir_lista()
{
    if (!Cabeza)
    {
        cout << "La lista esta vacia" << endl;
        return -1;
    }

    Nodo *aux = Cabeza;
    cout << aux->valor;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
        cout << " <-> " << aux->valor;
    }
    cout << endl;
    return 1;
}

// Método para organizar la lista en orden ascendente
template <typename T>
int ListaDoble<T>::organizar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }

    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    while (aux1->siguiente != NULL)
    {
        aux2 = aux1->siguiente;
        while (aux2 != NULL)
        {
            if (aux1->valor > aux2->valor)
            {
                T temp = aux1->valor;
                aux1->valor = aux2->valor;
                aux2->valor = temp;
            }
            aux2 = aux2->siguiente;
        }
        aux1 = aux1->siguiente;
    }
    return 1;
}

// Método para invertir la lista
template <typename T>
int ListaDoble<T>::reversar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }

    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    while (aux1->siguiente != NULL)
    {
        aux2 = aux1->siguiente;
        aux1->siguiente->anterior = aux1;
        aux1->siguiente = aux2->siguiente;
        aux2->siguiente = Cabeza;
        Cabeza->anterior = aux2;
        Cabeza = aux2;
        Cabeza->anterior = NULL;
    }
    return 1;
}

// Función principal para probar la clase ListaDoble
int main(){
    ListaDoble<int> *listadoble = new ListaDoble<int>;
    listadoble->insertar_nodo(1);
    listadoble->insertar_nodo(3);
    listadoble->insertar_nodo(7);
    listadoble->insertar_nodo(5);
    listadoble->insertar_nodo(6);
    listadoble->insertar_nodo(4);
    listadoble->insertar_nodo(2);
    listadoble->imprimir_lista();
    listadoble->organizar_lista();
    listadoble->imprimir_lista();
    listadoble->reversar_lista();
    listadoble->imprimir_lista();
    listadoble->borrar_nodo(4);
    listadoble->imprimir_lista();
    delete listadoble;

    return 0;
}