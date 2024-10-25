#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

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
    ulong tamanio_tabla;                            // tamaño de la tabla
    ulong cantidad_elementos;                       // cantidad de elementos insertados en la tabla
    ulong const num_bits = 14;                      // numero de bits para el hash y el tamaño inicial de la tabla
    ulong const tamanio_inicial = pow(2, num_bits); // tamaño inicial de la tabla
    ulong cantidad_de_tablas_adicionales;           // numero de veces que se hizo el resize del vector
    ulong cantidad_de_colisiones;                   // cantidad de colisiones en la tabla

    const float factor_carga = 0.2;

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

            // Cuando tenemos al menos numero_bits en el fragmento, entramos a operar los primeros numero_bits bits
            while (bits_en_fragmento_actual >= num_bits)
            {
                ulong fragmento_para_xor = valor_fragmento >> (bits_en_fragmento_actual - num_bits); // Tomamos los primeros numero_bits bits del fragmento
                resultado_xor ^= fragmento_para_xor;                                                 // Aplicamos XOR entre el fragmento y el resultado actual

                valor_fragmento &= (1 << (bits_en_fragmento_actual - num_bits)) - 1; // Limpiamos los bits que ya usamos del fragmento
                bits_en_fragmento_actual -= num_bits;                                // Disminuimos la cantidad de bits  que hay en el fragmento actual para seguir operando
            }
        }
        resultado_xor ^= valor_fragmento; // Aplicamos XOR al último fragmento si es que quedan bits en el fragmento

        return resultado_xor & ((1 << num_bits) - 1); // Limitamos el hash a los bits requeridos (14 bits, o en general, numero_bits)
    }

    // inserta un nuevo dato en la tabla y devuelve si hubo colision o no
    bool insertar(Dato *nuevo_dato, ulong hash_valor)
    {
        if (!(*Tabla)[hash_valor + (cantidad_de_tablas_adicionales * tamanio_inicial)]) // si no hay un dato en la posicion del hash
        {
            (*Tabla)[hash_valor + (cantidad_de_tablas_adicionales * tamanio_inicial)] = nuevo_dato; // insertamos el nuevo dato en la posicion del hash
            return false;                                                                           // retornamos que no hubo colision
        }
        else // si hay un dato en la posicion del hash
        {
            Dato *actual = (*Tabla)[hash_valor + (cantidad_de_tablas_adicionales * tamanio_inicial)]; // creamos un puntero al dato que esta en la posicion del hash
            while (actual->siguiente != nullptr)                                                      // recorremos la lista enlazada hasta encontrar el ultimo dato
            {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo_dato; // insertamos el nuevo dato al final de la lista enlazada en la posicion del hash
            return true;                    // retornamos que hubo una colision
        }
    }

    void leer_archivo_y_aplicar_hash(string direccion_archivo)
    {
        ifstream archivo(direccion_archivo);

        if (archivo.is_open()) // si se pudo abrir el archivo
        {
            string palabra;
            int cont_colisiones = 0, cont_palabras_insertadas = 0; // variables para calcular el ratio de colisiones

            while (getline(archivo, palabra)) // mientras hayan palabras en el archivo
            {
                ulong hash_valor = xor_fragmentos_hash(palabra) % tamanio_inicial; // calculamos el hash de la palabra actual y nos aseguramos que cabe en la tabla
                Dato *nuevo_dato = new Dato(palabra);                              // creamos un nuevo dato con la palabra actual
                if (insertar(nuevo_dato, hash_valor))                              // insertamos el nuevo dato en la tabla, en la posicion del hash  y verificamos la colision
                {
                    cont_colisiones++; // agregamos una colision al contador de la tabla actual en caso de que la haya
                }
                cont_palabras_insertadas++; // incrementamos la cantidad de elementos en la tabla actual

                if ((double)cont_colisiones / cont_palabras_insertadas > factor_carga) // si nuestro ratio de colisiones es mayor a el factor de carga (0.75)
                {
                    cantidad_de_tablas_adicionales++;               // incrementamos la cantidad de tablas
                    tamanio_tabla += tamanio_inicial;               // calculamos el nuevo tamaño de la tabla
                    cantidad_elementos += cont_palabras_insertadas; // sumamos la cantidad de palabras insertadas en la tabla actual a la cantidad total de palabras
                    cont_palabras_insertadas = 0;                   // reiniciamos la cantidad de palabras insertadas
                    cantidad_de_colisiones += cont_colisiones;      // sumamos las colisiones de la tabla actual a las colisiones totales
                    cont_colisiones = 0;                            // reiniciamos las colisiones

                    vector<Dato *> *nueva_tabla = new vector<Dato *>(tamanio_tabla, nullptr); // creamos una nueva tabla con el nuevo tamaño actual

                    for (ulong i = 0; i < (tamanio_inicial * cantidad_de_tablas_adicionales) - 1; i++) // recorremos la tabla actual
                    {
                        if ((*Tabla)[i]) // si hay un dato en la posicion i
                        {
                            (*nueva_tabla)[i] = (*Tabla)[i]; // insertamos el dato en la nueva tabla
                        }
                    }
                    delete Tabla;        // liberamos la memoria de la tabla actual
                    Tabla = nueva_tabla; // asignamos la nueva tabla a la tabla actual
                }
            }
            archivo.close();
            cantidad_de_colisiones += cont_colisiones;      // sumamos las colisiones de la ultima tabla a las colisiones totales
            cantidad_elementos += cont_palabras_insertadas; // sumamos las palabras insertadas en la ultima tabla a las palabras totales
        }
        else // si no se pudo abrir el archivo
        {
            cout << "No se pudo abrir el archivo." << endl; // mostramos un mensaje de error
        }
    }

public:
    TablaDeHash()
    {
        tamanio_tabla = pow(2, num_bits);                   // se inicializa el tamaño de la tabla con el tamaño inicial (2^14)
        cantidad_elementos = 0;                             // se inicializa la cantidad de elementos en la tabla en 0
        cantidad_de_tablas_adicionales = 0;                 // se inicializa la cantidad de tablas en 0
        cantidad_de_colisiones = 0;                         // se inicializa la cantidad de colisiones en 0
        Tabla = new vector<Dato *>(tamanio_tabla, nullptr); // se inicializa la tabla con el tamaño inicial y todos los elementos en nullptr
    }

    ~TablaDeHash()
    {
        clear();
        delete Tabla;
    }

    void mostrar_colisiones()
    {
        cout << "---------------------------------------------------" << endl;
        cout << "\t\tcolisiones: " << cantidad_de_colisiones << endl;
        cout << "\tratio de colisiones: " << (double)cantidad_de_colisiones / cantidad_elementos << endl;
        cout << "---------------------------------------------------" << endl;
    }

    // lee el archivo y aplica la funcion hash a cada palabra del archivo
    void leer_archivo(string direccion_archivo)
    {
        leer_archivo_y_aplicar_hash(direccion_archivo);
    }

    // elimina todos los datos de la tabla
    void clear()
    {
        for (ulong i = 0; i < tamanio_tabla; i++) // recorre la tabla
        {
            if ((*Tabla)[i]) // si hay un dato
            {
                Dato *actual = (*Tabla)[i]; // creamos un puntero a la primera posicion de la lista enlazada de la posicion i
                Dato *temp;
                while (actual != nullptr) // borramos uno a uno, los datos que tengamos en la lista enlazada
                {
                    temp = actual;
                    actual = actual->siguiente;
                    delete temp;
                }
            }
        }
    }

    bool buscar(string palabra)
    {
        cout << "---------------------------------------------------" << endl;
        ulong hash_valor = xor_fragmentos_hash(palabra) % tamanio_tabla; // calculamos el hash de la palabra
        for (int i = 0; i <= cantidad_de_tablas_adicionales; i++)         // recorremos todas las tablas
        {
            if ((*Tabla)[hash_valor + (i *  tamanio_inicial)]) // si hay un dato en la posicion del hash
            {
                Dato *actual = (*Tabla)[hash_valor + (i * tamanio_inicial)]; // creamos un puntero al dato que esta en la posicion del hash
                while (actual != nullptr) // recorremos la lista enlazada
                {
                    if (actual->valor == palabra) // si encontramos la palabra
                    {
                        cout << "Palabra " << palabra << " encontrada en la posicion " << hash_valor << endl; // mostramos un mensaje
        cout << "---------------------------------------------------" << endl;

                        return true;
                    }
                    actual = actual->siguiente; // avanzamos al siguiente dato
                }
            }
        }
        cout << "Palabra " << palabra << " no encontrada." << endl; // si no encontramos la palabra, mostramos un mensaje
        cout << "---------------------------------------------------" << endl;

        return false;
    }

    //imoprime todos los datos que tienen ese mismo hash
    void imprimir_indice(ulong indice){
        cout << "---------------------------------------------------" << endl;
        cout << "\tPalabras encontradas con indice: " << indice << endl;
        for (int i = 0; i <= cantidad_de_tablas_adicionales; i++) // recorremos todas las tablas
        {
            if ((*Tabla)[indice + (i *  tamanio_inicial)]) // si hay un dato en la posicion del hash
            {
                Dato *actual = (*Tabla)[indice + (i * tamanio_inicial)]; // creamos un puntero al dato que esta en la posicion del hash
                while (actual != nullptr) // recorremos la lista enlazada
                {
                    cout << "\t\t" << actual->valor << endl; // mostramos el valor del dato
                    actual = actual->siguiente; // avanzamos al siguiente dato
                }
            }
        }
        cout << "---------------------------------------------------" << endl;
    }

    void imprimir_tabla(){
        cout << "\t\tTabla de Hash" << endl;
        for (ulong i = 0; i <= tamanio_inicial; i++) // recorremos todas las posiciones de la tabla
        {
            imprimir_indice(i);
        }
    }

};

int main()
{
    TablaDeHash *tabla = new TablaDeHash();
    tabla->leer_archivo("/usr/share/dict/words");
    tabla->imprimir_tabla();
    tabla->mostrar_colisiones();
    delete tabla;
    return 0;
}