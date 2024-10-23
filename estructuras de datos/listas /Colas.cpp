#include <iostream>

using namespace std;

// Colas

template <typename T>
class Cola
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
    } *Cabeza;

public:
    Cola();
    ~Cola();
    T insertar_nodo(T);
    T borrar_nodo();
    int imprimir_cola();
};

template <typename T>
Cola<T>::Cola()
{
    Cabeza = NULL;
    cout << "Se ha creado una cola" << endl;
}

template <typename T>
Cola<T>::~Cola()
{
    while (Cabeza)
    {
        Nodo *aux = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux;
    }
    cout << "Se ha destruido una cola" << endl;
}

template <typename T>
T Cola<T>::insertar_nodo(T x)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = x;
    nuevo_nodo->siguiente = NULL;
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        return x;
    }
    Nodo *aux = Cabeza;
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevo_nodo;
    return x;
}

template <typename T>
T Cola<T>::borrar_nodo()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux = Cabeza;
    Cabeza = Cabeza->siguiente;
    T valor = aux->valor;
    delete aux;
    return valor;
}

template <typename T>
int Cola<T>::imprimir_cola()
{
    if (!Cabeza)
    {
        cout << "La cola esta vacia" << endl;
        return -1;
    }
    Nodo *aux = Cabeza;
    while (aux != NULL)
    {
        cout << aux->valor << " ";
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

int main()
{

    Cola<int> *cola = new Cola<int>;
    cola->insertar_nodo(1);
    cola->insertar_nodo(3);
    cola->insertar_nodo(7);
    cola->insertar_nodo(5);
    cola->insertar_nodo(6);
    cola->insertar_nodo(4);
    cola->insertar_nodo(2);
    cola->imprimir_cola();
    cola->borrar_nodo();
    cola->imprimir_cola();
    delete cola;

    return 0;

}