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

// lista doble

template <typename T>
class ListaDoble
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
        Nodo *anterior;
    } *Cabeza;

public:
    ListaDoble();
    ~ListaDoble();
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename T>
ListaDoble<T>::ListaDoble()
{
    Cabeza = NULL;
}

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

template <typename T>
T ListaDoble<T>::insertar_nodo(T x)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = x;
    nuevo_nodo->siguiente = NULL, nuevo_nodo->anterior = NULL;
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

template <typename T>
T ListaDoble<T>::borrar_nodo(T x)
{
    Nodo *aux1 = Cabeza;
    if (!Cabeza)
    {
        return -1;
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
            aux1->siguiente->anterior = aux1->anterior;
            delete aux1;
            return x;
        }
        aux1 = aux1->siguiente;
    }
    return 0;
}

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

// Lista Circular

template <typename T>
class ListaCircular
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
    } *Cabeza;

public:
    ListaCircular();
    ~ListaCircular();
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename T>
ListaCircular<T>::ListaCircular()
{
    Cabeza = NULL;
    cout << "se ha creado una lista circular" << endl;
}

template <typename T>
ListaCircular<T>::~ListaCircular()
{
    if (Cabeza)
    {
        Nodo *aux1 = Cabeza;
        Nodo *aux2;
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

template <typename T>
T ListaCircular<T>::insertar_nodo(T valor)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        Cabeza->siguiente = nuevo_nodo;
        return valor;
    }
    Nodo *aux = Cabeza;
    while (aux->siguiente != Cabeza)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevo_nodo;
    nuevo_nodo->siguiente = Cabeza;
    return valor;
}

template <typename T>
T ListaCircular<T>::borrar_nodo(T valor)
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    if (Cabeza->valor == valor)
    {
        if (Cabeza->siguiente == Cabeza)
        {
            delete Cabeza;
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
    while (aux != Cabeza)
    {
        cout << " -> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

template <typename T>
int ListaCircular<T>::organizar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
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

template <typename T>
int ListaCircular<T>::reversar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
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

// lista circular dobvle

template <typename T>
class ListaCircularDoble
{
private:
    struct Nodo
    {
        T valor;
        Nodo *siguiente;
        Nodo *anterior;
    } *Cabeza;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    T insertar_nodo(T);
    T borrar_nodo(T);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename T>
ListaCircularDoble<T>::ListaCircularDoble()
{
    Cabeza = NULL;
}

template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble()
{
    if (Cabeza)
    {
        Nodo *aux1 = Cabeza;
        Nodo *aux2;
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

template <typename T>
T ListaCircularDoble<T>::insertar_nodo(T valor)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        Cabeza->siguiente = nuevo_nodo;
        Cabeza->anterior = nuevo_nodo;
        return valor;
    }
    Nodo *aux = Cabeza;
    while (aux->siguiente != Cabeza)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevo_nodo;
    nuevo_nodo->anterior = aux;
    nuevo_nodo->siguiente = Cabeza;
    Cabeza->anterior = nuevo_nodo;
    return valor;
}

template <typename T>
T ListaCircularDoble<T>::borrar_nodo(T valor)
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    if (Cabeza->valor == valor)
    {
        if (Cabeza->siguiente == Cabeza)
        {
            delete Cabeza;
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
        Cabeza->anterior = aux1->anterior;
        delete aux1;
        return valor;
    }
    Nodo *aux2;
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
    while (aux != Cabeza)
    {
        cout << " <-> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
    return 1;
}

template <typename T>
int ListaCircularDoble<T>::organizar_lista()
{
    if (!Cabeza)
    {
        return -1;
    }
    Nodo *aux1 = Cabeza;
    Nodo *aux2;
    while (aux1->siguiente != Cabeza)
    {
        aux2 = aux1->siguiente;
        while (aux2 != Cabeza)
        {
            if (aux1->valor < aux2->valor)
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

// Cola de prioridad

template <typename T>
class ColaDePrioridad
{
private:
    struct Nodo
    {
        T valor;
        int prioridad;
        Nodo *siguiente;
    } *Cabeza;

public:
    ColaDePrioridad();
    ~ColaDePrioridad();
    void insertar_nodo(T, int);
    T borrar_nodo();
    int imprimir_cola();
};

template <typename T>
ColaDePrioridad<T>::ColaDePrioridad()
{
    Cabeza = NULL;
}

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

template <typename T>
void ColaDePrioridad<T>::insertar_nodo(T valor, int prioridad)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->valor = valor;
    nuevo_nodo->prioridad = prioridad;
    nuevo_nodo->siguiente = NULL;
    if (!Cabeza)
    {
        Cabeza = nuevo_nodo;
        return;
    }
    if (Cabeza->prioridad > prioridad)
    {
        nuevo_nodo->siguiente = Cabeza;
        Cabeza = nuevo_nodo;
        return;
    }
    Nodo *aux1 = Cabeza;
    while (aux1->siguiente && aux1->siguiente->prioridad <= prioridad)
    {
        aux1 = aux1->siguiente;
    }
    nuevo_nodo->siguiente = aux1->siguiente;
    aux1->siguiente = nuevo_nodo;
}

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
        return -1;
    }
}

// Arbol Binario de Busqueda

template <typename T>
class ArbolBinarioBusqueda
{
private:
    struct Nodo
    {
        T valor;
        Nodo *izquierda;
        Nodo *derecha;
        Nodo *padre;

        Nodo(T valor, Nodo *p) : valor(valor), izquierda(nullptr), derecha(nullptr), padre(p) {}
    } *Raiz;

    T insertar_nodo(Nodo *&nodo, T valor, Nodo *padre)
    {
        if (!nodo)
        {
            nodo = new Nodo(valor, padre);
            return valor;
        }
        return valor < nodo->valor ? insertar_nodo(nodo->izquierda, valor, nodo) : insertar_nodo(nodo->derecha, valor, nodo);
    }

    int imprimir_arbol(Nodo *nodo, int nivel)
    {
        if (!nodo)
        {
            return -1;
        }
        imprimir_arbol(nodo->derecha, nivel + 1);
        for (int i = 0; i < nivel; i++)
        {
            cout << "   ";
        }
        cout << nodo->valor << endl;
        imprimir_arbol(nodo->izquierda, nivel + 1);
        return 1;
    }

    void preorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        cout << nodo->valor << " ";
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }

    void inorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        inorden(nodo->izquierda);
        cout << nodo->valor << " ";
        inorden(nodo->derecha);
    }

    void postorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        cout << nodo->valor << " ";
    }

    bool buscar(Nodo *nodo, T valor)
    {
        if (!nodo)
        {
            return false;
        }
        if (nodo->valor == valor)
        {
            return true;
        }
        if (valor < nodo->valor)
        {
            return buscar(nodo->izquierda, valor);
        }
        else
        {
            return buscar(nodo->derecha, valor);
        }
    }

    Nodo *minimo(Nodo *nodo)
    {
        return nodo->izquierda ? minimo(nodo->izquierda) : nodo;
    }

    Nodo *borrar_nodo(Nodo *nodo, T valor)
    {
        cout << "Borrando " << valor << endl;
        if (!nodo)
        {
            return nodo;
        }
        if (valor < nodo->valor)
        {
            nodo->izquierda = borrar_nodo(nodo->izquierda, valor);
        }
        else if (valor > nodo->valor)
        {
            nodo->derecha = borrar_nodo(nodo->derecha, valor);
        }
        else
        {
            if (!nodo->izquierda && !nodo->derecha)
            {
                delete nodo;
                return nullptr;
            }
            else if (!nodo->izquierda)
            {
                Nodo *aux = nodo->derecha;
                delete nodo;
                return aux;
            }
            else if (!nodo->derecha)
            {
                Nodo *aux = nodo->izquierda;
                delete nodo;
                return aux;
            }
            else
            {
                Nodo *aux = minimo(nodo->derecha);
                nodo->valor = aux->valor;
                nodo->derecha = borrar_nodo(nodo->derecha, aux->valor);
            }
        }
        return nodo;
    }

public:
    ArbolBinarioBusqueda();
    ~ArbolBinarioBusqueda();
    T insertar_nodo(T);
    T borrar_nodo();
    int imprimir_arbol();
    void preorden();
    void inorden();
    void postorden();
    bool buscar(T);
};

template <typename T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda()
{
    Raiz = NULL;
    cout << "Se ha creado un arbol binario de busqueda" << endl;
}

template <typename T>
ArbolBinarioBusqueda<T>::~ArbolBinarioBusqueda()
{
    while (Raiz)
    {
        Raiz = borrar_nodo(Raiz, Raiz->valor);
    }
    cout << "Se ha destruido un arbol binario de busqueda" << endl;
}

template <typename T>
T ArbolBinarioBusqueda<T>::insertar_nodo(T valor)
{
    return insertar_nodo(Raiz, valor, NULL);
}

template <typename T>
int ArbolBinarioBusqueda<T>::imprimir_arbol()
{
    if (!Raiz)
    {
        cout << "El arbol esta vacio" << endl;
        return -1;
    }
    
    return imprimir_arbol(Raiz, 0);
}

template <typename T>
void ArbolBinarioBusqueda<T>::preorden()
{
    preorden(Raiz);
    cout << endl;
}

template <typename T>
void ArbolBinarioBusqueda<T>::inorden()
{
    inorden(Raiz);
    cout << endl;
}

template <typename T>
void ArbolBinarioBusqueda<T>::postorden()
{
    postorden(Raiz);
    cout << endl;
}

template <typename T>
T ArbolBinarioBusqueda<T>::borrar_nodo()
{
    if (!Raiz)
    {
        return -1;
    }
    T valor = Raiz->valor;
    Raiz = borrar_nodo(Raiz, valor);
    return valor;
}

template <typename T>
bool ArbolBinarioBusqueda<T>::buscar(T valor)
{
    return buscar(Raiz, valor);
}

// monticulo minimo

template <typename T>
class MonticuloMinimo
{
    private:
        struct Nodo
        {
            T valor;
            Nodo *izquierda;
            Nodo *derecha;
            Nodo *padre;

            Nodo(T valor, Nodo *p) : valor(valor), izquierda(nullptr), derecha(nullptr), padre(p) {}
        } *Raiz;

        void insertar(Nodo*& arbol, T valor, Nodo* padre){
            if(!arbol){
                arbol = new Nodo(valor, padre);
                heapifyUp(arbol);
            }else{
                if(!arbol->izquierda){
                    insertar(arbol->izquierda, valor, arbol);
                }else if(!arbol->derecha){
                    insertar(arbol->derecha, valor, arbol);
                }else{
                    if(altura(arbol.izquierda) <= altura(arbol.derecha)){
                        insertar(arbol.izquierda, valor, arbol);
                    }else{
                        insertar(arbol.derecha, valor, arbol);
                    }
                }
            }
        }

        void heapifyUp(Nodo* arbol){
            if(arbol->padre){
                if(arbol->valor < arbol->padre->valor){
                    T temp = arbol->valor;
                    arbol->valor = arbol->padre->valor;
                    arbol->padre->valor = temp;
                    heapifyUp(arbol->padre);
                }
            }
        }

        void mostrar(Nodo* arbol, int contador){
            if(!arbol->padre)return;
            mostrar(arbol->derecha, contador + 1);
            for(int i = 0; i < contador; i++)cout << "   ";
            cout << arbol->valor << endl;
            mostrar(arbol->izquierda, contador + 1);
        }

        Nodo *minimo(Nodo *arbol){
            return arbol->izquierda ? minimo(arbol->izquierda) : arbol;
        }

        void reemplazar(Nodo* arbol, Nodo* nuevo){
            if(arbol->padre){
                if(arbol->padre->izquierda == arbol){
                    arbol->padre->izquierda = nuevo;
                }else{
                    arbol->padre->derecha = nuevo;
                }
            }
            if(nuevo){
                nuevo->padre = arbol->padre;
            }
        }

        void eliminar_nodo(Nodo* nodo_eliminar){
            if(!nodo_eliminar->izquierda && !nodo_eliminar->derecha){
                reemplazar(nodo_eliminar, NULL);
                delete nodo_eliminar;
            }else{
                Nodo* menor = minimo(nodo_eliminar->derecha);
                nodo_eliminar->valor = menor->valor;
                eliminar_nodo(menor);
            }
        }

        void heapifyDown(Nodo* arbol){
            if (!arbol)return;
            else return;
        }

    public:

        MonticuloMinimo();
        ~MonticuloMinimo();
        void insertar_nodo(T);
        T borrar_nodo();
        bool buscar(T);
        int imprimir_monticulo();

    };

    // main (ejecucion)

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

        ListaCircular<int> *listacircular = new ListaCircular<int>;
        listacircular->insertar_nodo(1);
        listacircular->insertar_nodo(3);
        listacircular->insertar_nodo(7);
        listacircular->insertar_nodo(5);
        listacircular->insertar_nodo(6);
        listacircular->insertar_nodo(4);
        listacircular->insertar_nodo(2);
        listacircular->imprimir_lista();
        listacircular->organizar_lista();
        listacircular->imprimir_lista();
        listacircular->reversar_lista();
        listacircular->imprimir_lista();
        delete listacircular;

        ListaCircularDoble<int> *listacirculardoble = new ListaCircularDoble<int>;
        listacirculardoble->insertar_nodo(1);
        listacirculardoble->insertar_nodo(3);
        listacirculardoble->insertar_nodo(7);
        listacirculardoble->insertar_nodo(5);
        listacirculardoble->insertar_nodo(6);
        listacirculardoble->insertar_nodo(4);
        listacirculardoble->insertar_nodo(2);
        listacirculardoble->imprimir_lista();
        listacirculardoble->organizar_lista();
        listacirculardoble->imprimir_lista();
        listacirculardoble->reversar_lista();
        listacirculardoble->imprimir_lista();
        delete listacirculardoble;

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

        ColaDePrioridad<int> *coladeprioridad = new ColaDePrioridad<int>;
        coladeprioridad->insertar_nodo(1, 1);
        coladeprioridad->insertar_nodo(3, 3);
        coladeprioridad->insertar_nodo(7, 7);
        coladeprioridad->insertar_nodo(5, 5);
        coladeprioridad->insertar_nodo(6, 6);
        coladeprioridad->insertar_nodo(4, 4);
        coladeprioridad->insertar_nodo(2, 2);
        coladeprioridad->imprimir_cola();
        coladeprioridad->borrar_nodo();
        coladeprioridad->imprimir_cola();
        delete coladeprioridad;

        ArbolBinarioBusqueda<int> *arbolbinariobusqueda = new ArbolBinarioBusqueda<int>;
        arbolbinariobusqueda->insertar_nodo(16);
        arbolbinariobusqueda->insertar_nodo(8);
        arbolbinariobusqueda->insertar_nodo(24);
        arbolbinariobusqueda->insertar_nodo(13);
        arbolbinariobusqueda->insertar_nodo(3);
        arbolbinariobusqueda->insertar_nodo(19);
        arbolbinariobusqueda->insertar_nodo(21);
        arbolbinariobusqueda->insertar_nodo(7);
        arbolbinariobusqueda->imprimir_arbol();
        arbolbinariobusqueda->preorden();
        arbolbinariobusqueda->inorden();
        arbolbinariobusqueda->postorden();
        arbolbinariobusqueda->borrar_nodo();
        arbolbinariobusqueda->imprimir_arbol();
        arbolbinariobusqueda->preorden();
        arbolbinariobusqueda->inorden();
        arbolbinariobusqueda->postorden();
        delete arbolbinariobusqueda;


        // MonticuloMinimo<int> *monticulominimo = new MonticuloMinimo<int>;
        // monticulominimo->insertar_nodo(5);
        // monticulominimo->insertar_nodo(3);
        // monticulominimo->insertar_nodo(7);
        // monticulominimo->insertar_nodo(2);
        // monticulominimo->insertar_nodo(6);
        // monticulominimo->imprimir_monticulo();
        // monticulominimo->borrar_nodo();
        // monticulominimo->imprimir_monticulo();
        // delete monticulominimo;

        return 0;
    }
