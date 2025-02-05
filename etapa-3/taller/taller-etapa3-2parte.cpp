#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

using ulong = unsigned long;

class TablaDeHash
{
private:
    struct Dato
    {
        string valor;
        Dato *siguiente;

        Dato(string valor)
        {
            this->valor = valor;
            this->siguiente = nullptr;
        }
    };

    vector<Dato *> *Tabla;
    ulong tamanio_tabla;                   // tamaño de la tabla
    ulong cantidad_elementos;              // cantidad de elementos insertados en la tabla
    ulong num_bits;                        // número de bits para el hash y el tamaño inicial de la tabla
    ulong cantidad_de_colisiones;          // cantidad de colisiones en la tabla

    const float factor_carga = 0.7;       // factor de carga para la tabla

    ulong xor_fragmentos_hash(const string &palabra)
    {
        ulong resultado_xor = 0;
        ulong valor_fragmento = 0;
        ulong bits_en_fragmento_actual = 0;

        // Recorremos todos los caracteres de la palabra
        for (ulong i = 0; i < palabra.size(); ++i)
        {
            valor_fragmento = (valor_fragmento << 8) | static_cast<int>(palabra[i]); // Agregamos el valor del carácter en binario al fragmento
            bits_en_fragmento_actual += 8;                                           // agregamos los 8 bits del caracter al fragmento

            // Cuando tenemos al menos num_bits en el fragmento, operamos los primeros num_bits bits
            while (bits_en_fragmento_actual >= num_bits)
            {
                ulong fragmento_para_xor = valor_fragmento >> (bits_en_fragmento_actual - num_bits); // Tomamos los primeros num_bits bits del fragmento
                resultado_xor ^= fragmento_para_xor;                                                // Aplicamos XOR entre el fragmento y el resultado actual

                valor_fragmento &= (1 << (bits_en_fragmento_actual - num_bits)) - 1; // Limpiamos los bits que ya usamos del fragmento
                bits_en_fragmento_actual -= num_bits;                                // Disminuimos la cantidad de bits en el fragmento actual
            }
        }
        resultado_xor ^= valor_fragmento; // Aplicamos XOR al último fragmento si es que quedan bits en el fragmento

        return resultado_xor & ((1 << num_bits) - 1); // Limitamos el hash a los bits requeridos (14 bits, o en general, num_bits)
    }

    // Inserta un nuevo dato en la tabla y devuelve si hubo colisión o no
    bool insertar(Dato *nuevo_dato, ulong hash_valor)
    {
        cout << "Insertando: " << nuevo_dato->valor << " en índice: " << hash_valor << endl;
        Dato *&actual = (*Tabla)[hash_valor];
        if (actual) // Si hay un dato en la posición del hash
        {
            Dato *temp = actual;
            while (temp->siguiente != nullptr) // Recorremos la lista enlazada
            {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo_dato; // Insertamos el nuevo dato al final de la lista enlazada
            return true;                  // Retornamos que hubo una colisión
        }
        else // Si no hay un dato en la posición del hash
        {
            actual = nuevo_dato; // Insertamos el nuevo dato en la posición del hash
            return false;        // Retornamos que no hubo una colisión
        }
    }

    void leer_archivo_y_aplicar_hash(string direccion_archivo)
    {
        ifstream archivo(direccion_archivo);

        if (archivo.is_open()) // Si se pudo abrir el archivo
        {
            string palabra;

            while (getline(archivo, palabra)) // Mientras hayan palabras en el archivo
            {
                leer_palabra(palabra);
                // Verificamos si es necesario redimensionar la tabla
                if ((double)cantidad_elementos / tamanio_tabla > factor_carga) resize();
            }
            archivo.close();
        }
        else // Si no se pudo abrir el archivo
        {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }

    void leer_palabra(string palabra){
        cout << "Procesando palabra: " << palabra << endl;
                ulong hash_valor = xor_fragmentos_hash(palabra); // Calculamos el hash de la palabra actual
                cout << "Hash calculado: " << hash_valor << endl;
                Dato *nuevo_dato = new Dato(palabra);           // Creamos un nuevo dato con la palabra actual
                if (insertar(nuevo_dato, hash_valor))           // Insertamos el nuevo dato en la tabla y verificamos la colisión
                {
                    cantidad_de_colisiones++; // Incrementamos el contador de colisiones
                }
                cantidad_elementos++; // Incrementamos la cantidad de elementos en la tabla
    }

    void resize(){
        cout << "Redimensionando la tabla..." << endl;
                    tamanio_tabla *= 2; // Duplicamos el tamaño de la tabla
                    num_bits++;         // Incrementamos el número de bits para el hash

                    vector<Dato *> *nueva_tabla = Tabla; // Creamos una nueva tabla con el nuevo tamaño
                    Tabla = new vector<Dato *>(tamanio_tabla, nullptr);

                    // Reinsertamos todos los elementos en la nueva tabla
                    for (ulong i = 0; i < tamanio_tabla / 2; i++)
                    {
                        if ((*Tabla)[i])
                        {
                            Dato *actual = (*Tabla)[i];
                            while (actual != nullptr)
                            {
                                ulong nuevo_indice = xor_fragmentos_hash(actual->valor); // Calculamos el nuevo índice
                                cout << "Reinsertando: " << actual->valor << " en nuevo índice: " << nuevo_indice << endl;
                                if (nuevo_indice >= tamanio_tabla) // Verificamos que el índice esté dentro de los límites
                                {
                                    cerr << "Error: Índice fuera de límites (" << nuevo_indice << " >= " << tamanio_tabla << ")" << endl;
                                    actual = actual->siguiente;
                                    continue;
                                }
                                Dato *temp = actual;
                                actual = actual->siguiente;
                                if (insertar(temp, nuevo_indice)) // Insertamos en la nueva tabla
                                {
                                    cantidad_de_colisiones++;
                                }
                            }
                        }
                    }

                    delete nueva_tabla;        // Liberamos la memoria de la tabla anterior
                    cout << "Tabla redimensionada a tamaño: " << tamanio_tabla << endl;
    }

public:
    TablaDeHash()
    {
        num_bits = 8;                                      // Número inicial de bits para el hash
        tamanio_tabla = pow(2, num_bits);                   // Tamaño inicial de la tabla (2^14)
        cantidad_elementos = 0;                             // Cantidad de elementos en la tabla
        cantidad_de_colisiones = 0;                         // Cantidad de colisiones
        Tabla = new vector<Dato *>(tamanio_tabla, nullptr); // Inicializamos la tabla
        cout << "Tabla creada con tamaño inicial: " << tamanio_tabla << endl;
    }

    ~TablaDeHash()
    {
        clear();
        delete Tabla;
    }

    void mostrar_colisiones()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "\t\tTamaño de la tabla: " << tamanio_tabla << endl;
        cout << "\t\tColisiones: " << cantidad_de_colisiones << endl;
        cout << "\tRatio de colisiones: " << (double)cantidad_de_colisiones / cantidad_elementos << endl;
        cout << "---------------------------------------------------" << endl;
    }

    // Lee el archivo y aplica la función hash a cada palabra del archivo
    void leer_archivo(string direccion_archivo)
    {
        leer_archivo_y_aplicar_hash(direccion_archivo);
    }

    // Elimina todos los datos de la tabla
    void clear()
    {
        for (ulong i = 0; i < tamanio_tabla; i++) // Recorre la tabla
        {
            if ((*Tabla)[i]) // Si hay un dato
            {
                Dato *actual = (*Tabla)[i];
                Dato *temp;
                while (actual != nullptr) // Borramos uno a uno los datos en la lista enlazada
                {
                    temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                }
                (*Tabla)[i] = nullptr; // Ponemos el puntero a nullptr
            }
        }
    }

    // Busca una palabra en la tabla
    bool buscar(string palabra)
    {
        ulong hash_valor = xor_fragmentos_hash(palabra); // Calculamos el hash de la palabra
        if ((*Tabla)[hash_valor])                        // Si hay un dato en la posición del hash
        {
            Dato *actual = (*Tabla)[hash_valor];
            while (actual != nullptr) // Recorremos la lista enlazada
            {
                if (actual->valor == palabra) // Si encontramos la palabra
                {
                    return true;
                }
                actual = actual->siguiente;
            }
        }
        return false; // Si no encontramos la palabra
    }

    // Imprime todos los datos que tienen el mismo hash
    void imprimir_indice(ulong indice)
    {
        if ((*Tabla)[indice]) // Si hay un dato en la posición del hash
        {
            Dato *actual = (*Tabla)[indice];
            cout << "Índice: " << indice << endl;
            while (actual != nullptr) // Recorremos la lista enlazada
            {
                cout << "\t" << actual->valor << endl; // Imprimimos el valor del dato
                actual = actual->siguiente;
            }
        }
    }

    // Imprime toda la tabla
    void imprimir_tabla()
    {
        cout << "\t\tTabla de Hash" << endl;
        for (ulong i = 0; i < tamanio_tabla; i++) // Recorremos todas las posiciones de la tabla
        {
            imprimir_indice(i);
        }
    }
};

int main()
{
    TablaDeHash tabla;
    tabla.leer_archivo("/usr/share/dict/words"); // Cambia la ruta si es necesario
    tabla.imprimir_tabla();
    tabla.mostrar_colisiones();
    return 0;
}
