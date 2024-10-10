#include <iostream>

using namespace std;

class ListaSimple
{
private:
    struct Nodo
    {
        int valor;
        Nodo *siguiente;
    };
    Nodo *Cabeza;

public:
    ListaSimple();             // constructor: acciones que se ejecutan en la creacion de cada lista
    ~ListaSimple();            // destructor: acciones que se ejecutan cuando se acaba el ciclo de vida de la lista
    void insertar_nodo(int x); // inserta un nodo en la ultima posicion
    void borrar_ultimo_nodo(); // borra el ultimo nodo
    void imprimir_lista();     // imprime los valores de todos los nodos de la lista
    void organizar_lista();    // organiza la lista de menor a mayor
};

ListaSimple::ListaSimple()
{
    Cabeza = NULL;
}

ListaSimple::~ListaSimple()
{
    cout << "Se ha destruido una lista simple" << endl;
}

void ListaSimple::insertar_nodo(int x)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->valor = x;
    NuevoNodo->siguiente = NULL;
    if (Cabeza == NULL)
    {
        Cabeza = NuevoNodo;
    }
    else
    {
        Nodo *aux = Cabeza;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = NuevoNodo;
    }
}

void ListaSimple::imprimir_lista()
{
    if (Cabeza == NULL)
    {
        cout << "No hay elementos en esta lista" << endl;
    }
    else
    {
        Nodo *aux = Cabeza;
        cout << aux->valor;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
            cout << " -> " << aux->valor;
        }
        cout << endl;
    }
}

void ListaSimple::borrar_ultimo_nodo()
{
    if (Cabeza == NULL)
    {
    }
    else if (Cabeza->siguiente == NULL)
    {
        delete Cabeza;
        Cabeza = NULL;
    }
    else
    {
        Nodo *aux = Cabeza;
        while (aux->siguiente->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        delete aux->siguiente;
        aux->siguiente = NULL;
    }
}

int main()
{
    ListaSimple *lista = new ListaSimple;
    lista->insertar_nodo(1);
    lista->insertar_nodo(2);
    lista->imprimir_lista();
    lista->borrar_ultimo_nodo();
    lista->imprimir_lista();
}