#include <iostream>
#include <vector>

using namespace std;

// Plantilla de clase TablaHash que permite almacenar pares clave-valor de tipos genéricos
template <typename K, typename V>
class TablaHash
{
private:
    // Estructura Nodo que representa cada elemento almacenado en la tabla hash
    struct Nodo
    {
        K clave;       // Clave del nodo
        V valor;       // Valor asociado a la clave
        Nodo *siguiente; // Puntero al siguiente nodo, usado para manejar colisiones

        // Constructor del Nodo que inicializa la clave, valor y puntero siguiente
        Nodo(K clave, V valor) : clave(clave), valor(valor), siguiente(nullptr) {}
    };

    vector<Nodo *> tabla;     // Vector que contiene punteros a Nodos; representa la tabla hash
    int tamano;               // Tamaño de la tabla (número de slots o "buckets")
    int cantidadElementos;    // Contador de elementos insertados en la tabla
    const float factorCarga = 0.75; // Factor de carga máximo antes de redimensionar la tabla

    // Función hash que calcula el índice a partir de la clave
    int hash(K clave) const {
        // Devuelve un índice calculado por el cuadrado de la clave módulo el tamaño de la tabla
        return (clave * clave) % tamano;
    }

    // Función para redimensionar la tabla cuando el factor de carga se excede
    void redimensionar() {
        int nuevoTamano = tamano * 2;            // Duplicar el tamaño de la tabla
        vector<Nodo *> nuevaTabla(nuevoTamano, nullptr); // Nueva tabla con el nuevo tamaño

        // Reinsertar todos los elementos en la nueva tabla
        for (auto actual : tabla) {              // Recorre cada índice de la tabla actual
            while (actual != nullptr) {          // Recorre la lista enlazada en cada índice
                int nuevoIndice = (actual->clave * actual->clave) % nuevoTamano; // Calcula el nuevo índice
                Nodo *siguiente = actual->siguiente; // Guarda el siguiente nodo temporalmente
                actual->siguiente = nuevaTabla[nuevoIndice]; // Inserta nodo en el nuevo índice
                nuevaTabla[nuevoIndice] = actual;  // Coloca el nodo en el nuevo índice de la nueva tabla
                actual = siguiente;                // Avanza al siguiente nodo
            }
        }
        tabla = move(nuevaTabla);                 // Reemplaza la tabla antigua con la nueva
        tamano = nuevoTamano;                     // Actualiza el tamaño de la tabla
    }

public:
    // Constructor que inicializa la tabla con el tamaño dado y establece cantidadElementos en 0
    TablaHash(int tamano)
        : tamano(tamano), cantidadElementos(0) {
        tabla.resize(tamano, nullptr);            // Inicializa cada índice con nullptr
    }

    // Método para insertar una clave y valor en la tabla hash
    void insertar(K clave, V valor) {
        int indice = hash(clave);                 // Calcula el índice usando la función hash
        Nodo *actual = tabla[indice];             // Obtiene el primer nodo en ese índice

        // Recorre la lista enlazada en el índice para verificar si la clave ya existe
        while (actual != nullptr) {
            if (actual->clave == clave) {         // Si la clave existe, actualiza el valor
                actual->valor = valor;
                cout << "Clave " << clave << " actualizada con valor: " << valor << endl;
                return;                           // Finaliza la función
            }
            actual = actual->siguiente;           // Avanza al siguiente nodo en la lista
        }

        // Si la clave no existe, crea un nuevo nodo e inserta al inicio de la lista enlazada
        Nodo *nuevo = new Nodo(clave, valor);
        nuevo->siguiente = tabla[indice];         // Enlaza el nuevo nodo al primer nodo actual
        tabla[indice] = nuevo;                    // El nuevo nodo se convierte en el primer nodo
        cantidadElementos++;                      // Incrementa el contador de elementos

        // Verifica si el factor de carga se ha excedido y redimensiona si es necesario
        if (float(cantidadElementos) / tamano > factorCarga) {
            redimensionar();                      // Llama a la función de redimensionamiento
            cout << "Tabla redimensionada a " << tamano << " elementos." << endl;
        }

        cout << "Clave " << clave << " insertada con valor: " << valor << endl;
    }

    // Método para obtener el valor asociado a una clave
    void obtener(K clave) const {
        int indice = hash(clave);                 // Calcula el índice usando la función hash
        Nodo* actual = tabla[indice];             // Obtiene el primer nodo en la lista del índice

        // Recorre la lista enlazada en el índice buscando la clave
        while (actual != nullptr) {
            if (actual->clave == clave) {         // Si encuentra la clave, imprime el valor
                cout << "Valor asociado a la clave " << clave << " es: " << actual->valor << endl;
                return;                           // Termina la función
            }
            actual = actual->siguiente;           // Avanza al siguiente nodo en la lista
        }

        // Si no encuentra la clave, muestra un mensaje
        cout << "Clave " << clave << " no encontrada." << endl;
    }

    // Método para eliminar un par clave-valor de la tabla hash
    void eliminar(K clave) {
        int indice = hash(clave);                 // Calcula el índice usando la función hash
        Nodo *actual = tabla[indice];             // Obtiene el primer nodo en la lista del índice
        Nodo *anterior = nullptr;                 // Puntero al nodo anterior para ajustes

        // Recorre la lista enlazada buscando la clave
        while (actual != nullptr) {
            if (actual->clave == clave) {         // Si encuentra la clave
                if (anterior == nullptr) {        // Si es el primer nodo, ajusta la cabeza de la lista
                    tabla[indice] = actual->siguiente;
                } else {                          // Si es un nodo intermedio, ajusta punteros
                    anterior->siguiente = actual->siguiente;
                }
                delete actual;                    // Libera la memoria del nodo eliminado
                cantidadElementos--;              // Disminuye el contador de elementos
                cout << "Clave " << clave << " eliminada correctamente." << endl;
                return;                           // Termina la función
            }
            anterior = actual;                    // Actualiza el nodo anterior
            actual = actual->siguiente;           // Avanza al siguiente nodo en la lista
        }
        // Si no encuentra la clave, muestra un mensaje
        cout << "Clave " << clave << " no encontrada para eliminar." << endl;
    }

    // Destructor que libera toda la memoria de los nodos de la tabla
    ~TablaHash() {
        for (Nodo *actual : tabla) {              // Recorre cada índice de la tabla
            while (actual != nullptr) {           // Libera todos los nodos de la lista en el índice
                Nodo *temp = actual;              // Guarda el nodo actual en una variable temporal
                actual = actual->siguiente;       // Avanza al siguiente nodo
                delete temp;                      // Libera la memoria del nodo
            }
        }
    }
};

// Función principal que crea una tabla hash y realiza algunas operaciones
int main() {
    TablaHash<int, string> tabla(10); // Crea una tabla hash con 10 slots iniciales

    tabla.insertar(1, "Hola");        // Inserta la clave 1 con valor "Hola"
    tabla.insertar(2, "Mundo");       // Inserta la clave 2 con valor "Mundo"
    tabla.insertar(3, "C++");         // Inserta la clave 3 con valor "C++"

    tabla.obtener(1);                 // Obtiene y muestra el valor de la clave 1
    tabla.obtener(2);                 // Obtiene y muestra el valor de la clave 2
    tabla.obtener(3);                 // Obtiene y muestra el valor de la clave 3

    tabla.eliminar(2);                // Elimina la clave 2 de la tabla
    tabla.obtener(2);                 // Intenta obtener el valor de la clave 2 (ya eliminada)

    return 0;
}
