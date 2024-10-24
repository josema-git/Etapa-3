#include <iostream>

using namespace std;

// Definición de la clase plantilla ListaCircular
template <typename T>
class ListaCircular
{
private:
    // Definición de la estructura Nodo
    struct Nodo
    {
        T valor;         // Valor almacenado en el nodo
        Nodo *siguiente; // Puntero al siguiente nodo
    } *Cabeza;           // Puntero al primer nodo de la lista

public:
    // Constructor y destructor de la lista
    ListaCircular();
    ~ListaCircular();

    // Métodos para manipular la lista
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

// Constructor de la lista circular
template <typename T>
ListaCircular<T>::ListaCircular()
{
    Cabeza = NULL; // Inicializa la cabeza como NULL
    cout << "se ha creado una lista circular" << endl;
}

// Destructor de la lista circular
template <typename T>
ListaCircular<T>::~ListaCircular()
{
    if (Cabeza)
    {
        Nodo *aux1 = Cabeza;
        Nodo *aux2;
        // Elimina todos los nodos de la lista
        while (aux1->siguiente != Cabeza)
        {
            aux2 = aux1;
            aux1 = aux1->siguiente;
            delete aux2;
        }
        delete aux1;
    }
    cout << "Se ha destruido una lista circular" << endl;
}

// Método para insertar un nodo en la lista
template <typename T>
T ListaCircular<T>::insertar_nodo(T valor)
{
    Nodo *nuevo_nodo = new Nodo; // Crea un nuevo nodo
    nuevo_nodo->valor = valor;   // Asigna el valor al nuevo nodo
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;         // Si la lista está vacía, el nuevo nodo es la cabeza
        Cabeza->siguiente = nuevo_nodo; // El siguiente del nuevo nodo es él mismo
        return valor;
    }
    Nodo *aux = Cabeza;
    // Recorre la lista hasta encontrar el último nodo
    while (aux->siguiente != Cabeza)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevo_nodo; // Inserta el nuevo nodo al final de la lista
    nuevo_nodo->siguiente = Cabeza; // El siguiente del nuevo nodo es la cabeza
    return valor;
}

// Método para borrar un nodo de la lista
template <typename T>
T ListaCircular<T>::borrar_nodo(T valor)
{
    if (!Cabeza)
    {
        return -1; // Si la lista está vacía, retorna -1
    }
    Nodo *aux1 = Cabeza;
    // Si el nodo a borrar es la cabeza
    if (Cabeza->valor == valor)
    {
        if (Cabeza->siguiente == Cabeza)
        {
            delete Cabeza; // Si solo hay un nodo, lo elimina y pone la cabeza en NULL
            Cabeza = NULL;
            return valor;
        }
        while (aux1->siguiente != Cabeza)
        {
            aux1 = aux1->siguiente;
        }
        aux1->siguiente = Cabeza->siguiente;
        aux1 = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux1;
        return valor;
    }
    Nodo *aux2;
    // Recorre la lista buscando el nodo a borrar
    while (aux1->siguiente != Cabeza)
    {
        if (aux1->siguiente->valor == valor)
        {
            aux2 = aux1->siguiente;
            aux1->siguiente = aux2->siguiente;
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

// Método para imprimir la lista
template <typename T>
int ListaCircular<T>::imprimir_lista()
{
    if (!Cabeza)
    {
        cout << "No hay elementos en la lista" << endl;
        return -1;
    }
    Nodo *aux = Cabeza->siguiente;
    cout << Cabeza->valor;
    // Recorre la lista imprimiendo los valores
    while (aux != Cabeza)
    {
        cout << " -> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

// Método para organizar la lista en orden descendente
template <typename T>
int ListaCircular<T>::organizar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    // Ordena la lista usando el algoritmo de burbuja
    while (aux1->siguiente != Cabeza)
    {
        aux2 = aux1->siguiente;
        while (aux2 != Cabeza)
        {
            if (aux1->valor < aux2->valor)
            {
                int temp = aux2->valor;
                aux2->valor = aux1->valor;
                aux1->valor = temp;
            }
            aux2 = aux2->siguiente;
        }
        aux1 = aux1->siguiente;
    }
    return 1;
}

// Método para reversar la lista
template <typename T>
int ListaCircular<T>::reversar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    // Reversa la lista
    while (aux1->siguiente != aux1)
    {
        aux2 = aux1->siguiente;
        aux1->siguiente = aux2->siguiente;
        aux2->siguiente = Cabeza;
        Cabeza = aux2;
    }
    aux1->siguiente = Cabeza;
    return 1;
}

int main()
{
    // Crea una lista circular de enteros
    ListaCircular<int> *listacircular = new ListaCircular<int>;
    // Inserta nodos en la lista
    listacircular->insertar_nodo(1);
    listacircular->insertar_nodo(3);
    listacircular->insertar_nodo(7);
    listacircular->insertar_nodo(5);
    listacircular->insertar_nodo(6);
    listacircular->insertar_nodo(4);
    listacircular->insertar_nodo(2);
    // Imprime la lista
    listacircular->imprimir_lista();
    // Organiza la lista
    listacircular->organizar_lista();
    // Imprime la lista organizada
    listacircular->imprimir_lista();
    // Reversa la lista
    listacircular->reversar_lista();
    // Imprime la lista reversada
    listacircular->imprimir_lista();
    // Elimina la lista
    delete listacircular;

    return 0;
}