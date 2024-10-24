#include <iostream>
#include <vector>
#include <functional> // Para std::hash, que se usará para generar los índices en la tabla hash

using namespace std;

// Definición de la clase plantilla para la tabla hash. Esta clase permitirá usar diferentes tipos de claves (K) y valores (V)
template <typename K, typename V>
class TablaHash
{
private:
    // Definición de la estructura Nodo, que representa cada elemento almacenado en la tabla hash
    struct Nodo
    {
        K clave;       // Clave del nodo
        V valor;       // Valor asociado a la clave
        Nodo *siguiente; // Puntero al siguiente nodo, se usa para manejar colisiones con listas enlazadas

        // Constructor para inicializar la clave y el valor del nodo
        Nodo(K clave, V valor) : clave(clave), valor(valor), siguiente(nullptr) {}
    };

    vector<Nodo *> tabla; // Vector que contiene punteros a los nodos. Representa la tabla hash.
    int tamano;           // Tamaño de la tabla hash (cantidad de "cubos" o slots)

    // Función hash que calcula el índice basado en la clave. Utiliza std::hash para diferentes tipos de claves.
    int hash(K clave) const {
        // Aplica la función hash a la clave y luego toma el módulo del tamaño para obtener un índice dentro de los límites de la tabla.
        return std::hash<K>()(clave) % tamano;
    }

public:
    // Constructor de la clase TablaHash, que inicializa el tamaño de la tabla y la redimensiona
    TablaHash(int tamano)
    {
        this->tamano = tamano;        // Se asigna el tamaño de la tabla
        tabla.resize(tamano, nullptr); // Se inicializan los slots con punteros nulos (nullptr)
    }

    // Método para insertar un par clave-valor en la tabla hash
    void insertar(K clave, V valor)
    {
        int indice = hash(clave);     // Calcula el índice en la tabla usando la función hash
        Nodo *actual = tabla[indice]; // Obtiene el primer nodo en la lista del índice calculado

        // Recorre la lista enlazada en busca de la clave (para actualizarla si ya existe)
        while (actual != nullptr)
        {
            if (actual->clave == clave)
            {
                actual->valor = valor; // Si la clave ya existe, actualiza el valor
                cout << "Clave " << clave << " actualizada con valor: " << valor << endl;
                return; // Termina la ejecución de la función porque ya se ha actualizado
            }
            actual = actual->siguiente; // Avanza al siguiente nodo en la lista
        }

        // Si la clave no existe, se crea un nuevo nodo con la clave y el valor
        Nodo *nuevo = new Nodo(clave, valor);
        nuevo->siguiente = tabla[indice]; // El nuevo nodo apunta al primer nodo actual (encabezado de la lista enlazada)
        tabla[indice] = nuevo;            // El nuevo nodo se convierte en el primer nodo de la lista enlazada en ese índice
        cout << "Clave " << clave << " insertada con valor: " << valor << endl;
    }

    // Método para obtener el valor asociado a una clave, y mostrar el valor si se encuentra
    void obtener(K clave) const {
        int indice = hash(clave);     // Calcula el índice en la tabla usando la función hash
        Nodo* actual = tabla[indice]; // Obtiene el primer nodo en la lista enlazada correspondiente al índice

        // Recorre la lista enlazada buscando la clave
        while (actual != nullptr) {
            if (actual->clave == clave) {
                // Si encuentra la clave, muestra el valor asociado
                cout << "Valor asociado a la clave " << clave << " es: " << actual->valor << endl;
                return; // Sale del método, ya que la clave fue encontrada
            }
            actual = actual->siguiente; // Avanza al siguiente nodo en la lista enlazada
        }
        // Si no encuentra la clave, muestra un mensaje
        cout << "Clave " << clave << " no encontrada." << endl;
    }

    // Método para eliminar una clave de la tabla hash
    void eliminar(K clave)
    {
        int indice = hash(clave);     // Calcula el índice en la tabla usando la función hash
        Nodo *actual = tabla[indice]; // Obtiene el primer nodo en la lista enlazada correspondiente al índice
        Nodo *anterior = nullptr;     // Puntero al nodo anterior, se usa para ajustar los punteros cuando se elimine

        // Recorre la lista enlazada buscando la clave
        while (actual != nullptr)
        {
            if (actual->clave == clave)
            {
                // Si la clave es encontrada, la elimina ajustando los punteros
                if (anterior == nullptr)
                {
                    // Si es el primer nodo en la lista, se ajusta la cabeza de la lista al siguiente nodo
                    tabla[indice] = actual->siguiente;
                }
                else
                {
                    // Si es un nodo en medio o al final, el nodo anterior apunta al siguiente nodo
                    anterior->siguiente = actual->siguiente;
                }
                delete actual; // Libera la memoria del nodo eliminado
                cout << "Clave " << clave << " eliminada correctamente." << endl;
                return; // Termina la ejecución del método porque la clave ha sido eliminada
            }
            anterior = actual;          // Actualiza el puntero anterior al nodo actual
            actual = actual->siguiente; // Avanza al siguiente nodo en la lista enlazada
        }
        // Si la clave no se encuentra, muestra un mensaje
        cout << "Clave " << clave << " no encontrada para eliminar." << endl;
    }

    // Destructor de la tabla hash para liberar la memoria de todos los nodos
    ~TablaHash()
    {
        // Recorre cada índice en la tabla
        for (Nodo *actual : tabla)
        {
            // Recorre la lista enlazada en cada índice y libera la memoria de cada nodo
            while (actual != nullptr)
            {
                Nodo *temp = actual;      // Almacena el nodo actual en una variable temporal
                actual = actual->siguiente; // Avanza al siguiente nodo en la lista
                delete temp;              // Libera la memoria del nodo
            }
        }
    }
};

// Función principal para probar la clase TablaHash
int main()
{
    TablaHash<int, string> tabla(10);

    tabla.insertar(1, "Hola");
    tabla.insertar(2, "Mundo");
    tabla.insertar(3, "C++");

    tabla.obtener(1);
    tabla.obtener(2);
    tabla.obtener(3);

    tabla.eliminar(2);

    tabla.obtener(2);

    return 0;
}
