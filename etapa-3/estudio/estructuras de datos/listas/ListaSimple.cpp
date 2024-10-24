#include <iostream>

using namespace std;
// lista simple

template <typename T>
class ListaSimple
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
    } *Cabeza;

public:
    ListaSimple();
    ~ListaSimple();
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename T>
ListaSimple<T>::ListaSimple()
{
    Cabeza = NULL;
    cout << "Se ha creado una lista simple" << endl;
}

template <typename T>
ListaSimple<T>::~ListaSimple()
{
    while (Cabeza)
    {
        Nodo *aux = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux;
    }
    cout << "Se ha destruido una lista simple" << endl;
}

template <typename T>
T ListaSimple<T>::insertar_nodo(T x)
{
    Nodo *NuevoNodo = new Nodo;
    NuevoNodo->valor = x;
    NuevoNodo->siguiente = NULL;
    if (!Cabeza)
    {
        Cabeza = NuevoNodo;
        return NuevoNodo->valor;
    }
    else
    {
        Nodo *aux = Cabeza;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = NuevoNodo;
        return NuevoNodo->valor;
    }
}

template <typename T>
int ListaSimple<T>::imprimir_lista()
{
    if (!Cabeza)
    {
        cout << "No hay elementos en esta lista" << endl;
        return -1;
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
        return 1;
    }
}

template <typename T>
T ListaSimple<T>::borrar_nodo(T x)
{
    if (!Cabeza)
    {
        return -1;
    }
    if (Cabeza->siguiente == NULL)
    {
        if (Cabeza->valor == x)
        {
            delete Cabeza;
            Cabeza = NULL;
            return x;
        }
        else
        {
            return 0;
        }
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    while (aux1->siguiente != NULL)
    {
        if (aux1->siguiente->valor == x)
        {
            aux2 = aux1->siguiente;
            aux1->siguiente = aux2->siguiente;
            delete aux2;
            return x;
            break;
        }
        else
        {
            aux1 = aux1->siguiente;
        }
    }
    return 0;
}

template <typename T>
int ListaSimple<T>::organizar_lista()
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

template <typename T>
int ListaSimple<T>::reversar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2 = Cabeza->siguiente;
    for (int i = 0; aux1->siguiente; i++)
    {
        aux1->siguiente = aux2->siguiente;
        aux2->siguiente = Cabeza;
        Cabeza = aux2;
        aux2 = aux1->siguiente;
    }
    return 1;
}

int main()
{
    ListaSimple<int> *lista = new ListaSimple<int>;
    lista->insertar_nodo(1);
    lista->insertar_nodo(3);
    lista->insertar_nodo(7);
    lista->insertar_nodo(5);
    lista->insertar_nodo(6);
    lista->insertar_nodo(4);
    lista->insertar_nodo(2);
    lista->imprimir_lista();
    lista->organizar_lista();
    lista->imprimir_lista();
    lista->reversar_lista();
    lista->imprimir_lista();
    delete lista;

    return 0;
}