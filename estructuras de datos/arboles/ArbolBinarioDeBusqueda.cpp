#include <iostream>

using namespace std;

// Clase para representar un Árbol Binario de Búsqueda
template <typename T>
class ArbolBinarioBusqueda
{
private:
    // Estructura para representar un nodo del árbol
    struct Nodo
    {
        T valor;           // Valor del nodo
        Nodo *izquierda;   // Puntero al hijo izquierdo
        Nodo *derecha;     // Puntero al hijo derecho
        Nodo *padre;       // Puntero al nodo padre

        // Constructor del nodo
        Nodo(T valor, Nodo *p) : valor(valor), izquierda(nullptr), derecha(nullptr), padre(p) {}
    } *Raiz; // Puntero a la raíz del árbol

    // Función recursiva para insertar un nodo en el árbol
    T insertar_nodo(Nodo *&nodo, T valor, Nodo *padre)
    {
        if (!nodo)
        {
            nodo = new Nodo(valor, padre); // Crear un nuevo nodo si el actual es nulo
            return valor;
        }
        // Insertar en el subárbol izquierdo o derecho según el valor
        return valor < nodo->valor ? insertar_nodo(nodo->izquierda, valor, nodo) : insertar_nodo(nodo->derecha, valor, nodo);
    }

    // Función recursiva para imprimir el árbol en forma de árbol
    int imprimir_arbol(Nodo *nodo, int nivel)
    {
        if (!nodo)
        {
            return -1;
        }
        imprimir_arbol(nodo->derecha, nivel + 1); // Imprimir subárbol derecho
        for (int i = 0; i < nivel; i++)
        {
            cout << "   "; // Indentar según el nivel
        }
        cout << nodo->valor << endl; // Imprimir valor del nodo
        imprimir_arbol(nodo->izquierda, nivel + 1); // Imprimir subárbol izquierdo
        return 1;
    }

    // Función recursiva para recorrer el árbol en preorden
    void preorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        cout << nodo->valor << " "; // Imprimir valor del nodo
        preorden(nodo->izquierda); // Recorrer subárbol izquierdo
        preorden(nodo->derecha); // Recorrer subárbol derecho
    }

    // Función recursiva para recorrer el árbol en inorden
    void inorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        inorden(nodo->izquierda); // Recorrer subárbol izquierdo
        cout << nodo->valor << " "; // Imprimir valor del nodo
        inorden(nodo->derecha); // Recorrer subárbol derecho
    }

    // Función recursiva para recorrer el árbol en postorden
    void postorden(Nodo *nodo)
    {
        if (!nodo)
        {
            return;
        }
        postorden(nodo->izquierda); // Recorrer subárbol izquierdo
        postorden(nodo->derecha); // Recorrer subárbol derecho
        cout << nodo->valor << " "; // Imprimir valor del nodo
    }

    // Función recursiva para buscar un valor en el árbol
    bool buscar(Nodo *nodo, T valor)
    {
        if (!nodo)
        {
            return false; // Valor no encontrado
        }
        if (nodo->valor == valor)
        {
            return true; // Valor encontrado
        }
        // Buscar en el subárbol izquierdo o derecho según el valor
        return valor < nodo->valor ? buscar(nodo->izquierda, valor) : buscar(nodo->derecha, valor);
    }

    // Función recursiva para encontrar el nodo con el valor mínimo
    Nodo *minimo(Nodo *nodo)
    {
        return nodo->izquierda ? minimo(nodo->izquierda) : nodo;
    }

    // Función recursiva para borrar un nodo del árbol
    Nodo *borrar_nodo(Nodo *nodo, T valor)
    {
        if (!nodo)
        {
            return nodo;
        }
        if (valor < nodo->valor)
        {
            nodo->izquierda = borrar_nodo(nodo->izquierda, valor); // Borrar en el subárbol izquierdo
        }
        else if (valor > nodo->valor)
        {
            nodo->derecha = borrar_nodo(nodo->derecha, valor); // Borrar en el subárbol derecho
        }
        else
        {
            // Nodo encontrado
            if (!nodo->izquierda && !nodo->derecha)
            {
                delete nodo; // Nodo sin hijos
                return nullptr;
            }
            else if (!nodo->izquierda)
            {
                Nodo *aux = nodo->derecha; // Nodo con solo hijo derecho
                delete nodo;
                return aux;
            }
            else if (!nodo->derecha)
            {
                Nodo *aux = nodo->izquierda; // Nodo con solo hijo izquierdo
                delete nodo;
                return aux;
            }
            else
            {
                Nodo *aux = minimo(nodo->derecha); // Nodo con dos hijos
                nodo->valor = aux->valor;
                nodo->derecha = borrar_nodo(nodo->derecha, aux->valor);
            }
        }
        return nodo;
    }

public:
    // Constructor del árbol
    ArbolBinarioBusqueda();
    // Destructor del árbol
    ~ArbolBinarioBusqueda();
    // Función para insertar un nodo en el árbol
    T insertar_nodo(T);
    // Función para borrar un nodo del árbol
    T borrar_nodo();
    // Función para imprimir el árbol
    int imprimir_arbol();
    // Función para recorrer el árbol en preorden
    void preorden();
    // Función para recorrer el árbol en inorden
    void inorden();
    // Función para recorrer el árbol en postorden
    void postorden();
    // Función para buscar un valor en el árbol
    bool buscar(T);
};

// Implementación del constructor del árbol
template <typename T>
ArbolBinarioBusqueda<T>::ArbolBinarioBusqueda()
{
    Raiz = NULL;
    cout << "Se ha creado un arbol binario de busqueda" << endl;
}

// Implementación del destructor del árbol
template <typename T>
ArbolBinarioBusqueda<T>::~ArbolBinarioBusqueda()
{
    while (Raiz)
    {
        Raiz = borrar_nodo(Raiz, Raiz->valor);
    }
    cout << "Se ha destruido un arbol binario de busqueda" << endl;
}

// Implementación de la función para insertar un nodo en el árbol
template <typename T>
T ArbolBinarioBusqueda<T>::insertar_nodo(T valor)
{
    return insertar_nodo(Raiz, valor, NULL);
}

// Implementación de la función para imprimir el árbol
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

// Implementación de la función para recorrer el árbol en preorden
template <typename T>
void ArbolBinarioBusqueda<T>::preorden()
{
    preorden(Raiz);
    cout << endl;
}

// Implementación de la función para recorrer el árbol en inorden
template <typename T>
void ArbolBinarioBusqueda<T>::inorden()
{
    inorden(Raiz);
    cout << endl;
}

// Implementación de la función para recorrer el árbol en postorden
template <typename T>
void ArbolBinarioBusqueda<T>::postorden()
{
    postorden(Raiz);
    cout << endl;
}

// Implementación de la función para borrar un nodo del árbol
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

// Implementación de la función para buscar un valor en el árbol
template <typename T>
bool ArbolBinarioBusqueda<T>::buscar(T valor)
{
    return buscar(Raiz, valor);
}

// Función principal
int main()
{
    // Crear un nuevo árbol binario de búsqueda
    ArbolBinarioBusqueda<int> *arbolbinariobusqueda = new ArbolBinarioBusqueda<int>;
    // Insertar nodos en el árbol
    arbolbinariobusqueda->insertar_nodo(16);
    arbolbinariobusqueda->insertar_nodo(8);
    arbolbinariobusqueda->insertar_nodo(24);
    arbolbinariobusqueda->insertar_nodo(13);
    arbolbinariobusqueda->insertar_nodo(3);
    arbolbinariobusqueda->insertar_nodo(19);
    arbolbinariobusqueda->insertar_nodo(21);
    arbolbinariobusqueda->insertar_nodo(7);
    // Imprimir el árbol
    arbolbinariobusqueda->imprimir_arbol();
    // Recorrer el árbol en preorden
    arbolbinariobusqueda->preorden();
    // Recorrer el árbol en inorden
    arbolbinariobusqueda->inorden();
    // Recorrer el árbol en postorden
    arbolbinariobusqueda->postorden();
    // Borrar un nodo del árbol
    arbolbinariobusqueda->borrar_nodo();
    // Imprimir el árbol
    arbolbinariobusqueda->imprimir_arbol();
    // Recorrer el árbol en preorden
    arbolbinariobusqueda->preorden();
    // Recorrer el árbol en inorden
    arbolbinariobusqueda->inorden();
    // Recorrer el árbol en postorden
    arbolbinariobusqueda->postorden();
    // Eliminar el árbol
    delete arbolbinariobusqueda;

    return 0;
}