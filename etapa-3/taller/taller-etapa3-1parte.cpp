#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

string direccion_archivo = "/usr/share/dict/words";
int num_palabras = pow(2,14) ; // Tamaño del vector para almacenar las palabras
vector<int> palabras(num_palabras, 0); // Vector que almacena los hash para detectar colisiones

// Hash Function 1: Character Summation
int character_summation_hash(const string &palabra, int num_bits) {
    int suma = 0;

    // Sumamos el valor ASCII de cada carácter
    for (char c : palabra) {
        suma += static_cast<int>(c);
    }

    // Retornamos el número de bits especificado (usamos el módulo para ajustar los bits)
    return suma % (1 << num_bits); // 1 << num_bits es 2 elevado a num_bits
}

// Hash Function 2: Character Products
int character_products_hash(const string &palabra, int num_bits) {
    int producto = 1;

    // Multiplicamos el valor ASCII de cada carácter
    for (char c : palabra) {
        producto *= static_cast<int>(c);
        producto %= (1 << num_bits); // Aplicamos el módulo dentro del loop para evitar overflow
    }

    // Retornamos el número de bits especificado
    return producto;
}

// Hash Function 3: Chunked XORs
int chunked_xor_hash(const string &palabra, int num_bits) {
    int xor_result = 0;
    int fragment_value = 0;
    
    int bits_in_current_chunk = 0;
    
    // Recorremos todos los caracteres de la palabra
    for (int i = 0; i < palabra.size(); ++i) {
        fragment_value = (fragment_value << 8) | static_cast<int>(palabra[i]); // Agregamos el valor del carácter al fragmento
        bits_in_current_chunk += 8;  // Incrementamos los bits actuales en el fragmento

        // Cuando tenemos al menos num_bits en el fragmento, aplicamos XOR y ajustamos
        while (bits_in_current_chunk >= num_bits) {
            // Tomamos los primeros num_bits bits del fragmento
            int fragment_to_xor = fragment_value >> (bits_in_current_chunk - num_bits);
            xor_result ^= fragment_to_xor; // Aplicamos XOR al resultado

            // Eliminamos los bits procesados y ajustamos el número de bits restantes
            fragment_value &= (1 << (bits_in_current_chunk - num_bits)) - 1;
            bits_in_current_chunk -= num_bits;
        }
    }
    xor_result ^= fragment_value; // Aplicamos XOR al último fragmento si es que quedan bits

    // Retornamos el resultado limitado a num_bits
    return xor_result & ((1 << num_bits) - 1);  // Aquí limitamos el hash a los bits requeridos (14 bits)
}

// Función para leer el archivo y aplicar la función hash
void leer_archivo_y_aplicar_hash(int (*funcion_hash)(const string&, int), int num_bits) {
    ifstream archivo(direccion_archivo);
    
    if (archivo.is_open()) {
        string palabra;
        int colisiones = 0;
        
        // Leer línea por línea cada palabra del archivo
        while(getline(archivo, palabra)){
            // Calculamos la clave hash usando la función hash pasada como parámetro
            int hash_valor = funcion_hash(palabra, num_bits);
            int index = abs(hash_valor) % num_palabras; // Usamos el valor modificado dentro del límite de palabras

            if (palabras[index] == 0) {
                palabras[index] = 1;
            } else {
                colisiones++;
            }
        }
        cout << "Colisiones: " << colisiones << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main(){
    int num_bits = 14;

    cout << "Aplicando Character Summation Hash:" << endl;
    leer_archivo_y_aplicar_hash(character_summation_hash, num_bits);

    cout << "\nAplicando Character Products Hash:" << endl;
    leer_archivo_y_aplicar_hash(character_products_hash, num_bits);

    cout << "\nAplicando Chunked XOR Hash:" << endl;
    leer_archivo_y_aplicar_hash(chunked_xor_hash, num_bits);

    return 0;
}