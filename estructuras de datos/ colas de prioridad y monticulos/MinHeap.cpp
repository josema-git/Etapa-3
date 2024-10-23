#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class MonticuloMinimo {
private:
    vector<T> heap; // El vector que representa el montículo

    // Función para subir el valor en el índice dado para restaurar la propiedad del montículo
    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            // Intercambiamos el nodo con su padre si es menor que él
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2; // Subimos al padre
        }
    }

    // Función para bajar el valor en el índice dado para restaurar la propiedad del montículo
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int menor = index; // El índice del valor más pequeño
            int izq = 2 * index + 1; // Índice del hijo izquierdo
            int der = 2 * index + 2; // Índice del hijo derecho

            // Comparamos con el hijo izquierdo
            if (izq < size && heap[izq] < heap[menor]) {
                menor = izq;
            }
            // Comparamos con el hijo derecho
            if (der < size && heap[der] < heap[menor]) {
                menor = der;
            }

            // Si el valor más pequeño no es el actual, lo intercambiamos
            if (menor != index) {
                swap(heap[index], heap[menor]);
                index = menor; // Bajamos al siguiente nivel
            } else {
                break; // La propiedad del montículo ya está restaurada
            }
        }
    }

public:
    // Función para insertar un nuevo valor en el montículo
    void insertar_nodo(T valor) {
        heap.push_back(valor); // Insertamos el nuevo valor al final
        heapifyUp(heap.size() - 1); // Restauramos la propiedad del montículo desde el final hacia arriba
    }

    // Función para eliminar el valor mínimo (la raíz del montículo)
    T borrar_nodo() {
        if (heap.empty()) {
            throw runtime_error("El montículo está vacío.");
        }

        T raiz = heap[0]; // Guardamos el valor de la raíz
        heap[0] = heap.back(); // Reemplazamos la raíz con el último elemento
        heap.pop_back(); // Eliminamos el último elemento

        // Restauramos la propiedad del montículo desde la raíz hacia abajo
        heapifyDown(0);

        return raiz; // Devolvemos el valor de la raíz eliminada
    }

    // Función para buscar un valor en el montículo
    bool buscar(T valor) const {
        for (const T& v : heap) {
            if (v == valor) return true;
        }
        return false;
    }

    // Función para imprimir el montículo
    void imprimir_monticulo() const {
        for (const T& v : heap) {
            cout << v << " ";
        }
        cout << endl;
    }

    // Función para obtener el tamaño del montículo
    int tamano() const {
        return heap.size();
    }

    // Función para verificar si el montículo está vacío
    bool esta_vacio() const {
        return heap.empty();
    }
};

int main() {
    MonticuloMinimo<int> monticulo;
    
    // Insertamos varios elementos
    monticulo.insertar_nodo(5);
    monticulo.insertar_nodo(3);
    monticulo.insertar_nodo(7);
    monticulo.insertar_nodo(2);
    monticulo.insertar_nodo(6);
    monticulo.insertar_nodo(4);
    monticulo.insertar_nodo(1);

    // Imprimimos el montículo
    monticulo.imprimir_monticulo(); // Debería mostrar el montículo ordenado como un heap mínimo

    // Eliminamos el valor mínimo (la raíz) varias veces y mostramos el resultado
    cout << "Eliminando el valor mínimo: " << monticulo.borrar_nodo() << endl;
    monticulo.imprimir_monticulo();

    cout << "Eliminando el valor mínimo: " << monticulo.borrar_nodo() << endl;
    monticulo.imprimir_monticulo();

    cout << "Eliminando el valor mínimo: " << monticulo.borrar_nodo() << endl;
    monticulo.imprimir_monticulo();

    return 0;
}
