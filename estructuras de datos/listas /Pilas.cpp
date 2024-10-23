#include <iostream>

using namespace std;
// Pilas

template <typename T>
class Pila
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
    } *Cabeza;

public:
    Pila();
    ~Pila();
    T insertar_nodo(T);
    T borrar_nodo();
    int imprimir_pila();
};

template <typename T>
Pila<T>::Pila()
{
    Cabeza = NULL;
    cout << "Se ha creado una pila" << endl;
}

template <typename T>
Pila<T>::~Pila()
{
    while (Cabeza)
    {
        Nodo *aux = Cabeza;
        Cabeza = Cabeza->siguiente;
        delete aux;
    }
    cout << "Se ha destruido una pila" << endl;
}

template <typename T>
T Pila<T>::insertar_nodo(T x)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = x;
    nuevo_nodo->siguiente = Cabeza;
    Cabeza = nuevo_nodo;
    return x;
}

template <typename T>
T Pila<T>::borrar_nodo()
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
int Pila<T>::imprimir_pila()
{
    if (!Cabeza)
    {
        cout << "La pila esta vacia" << endl;
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

    Pila<int> *pila = new Pila<int>;
    pila->insertar_nodo(1);
    pila->insertar_nodo(3);
    pila->insertar_nodo(7);
    pila->insertar_nodo(5);
    pila->insertar_nodo(6);
    pila->insertar_nodo(4);
    pila->insertar_nodo(2);
    pila->imprimir_pila();
    pila->borrar_nodo();
    pila->imprimir_pila();
    delete pila;
    
    return 0;
}