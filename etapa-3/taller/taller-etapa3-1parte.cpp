#include <iostream>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

string ruta_archivo = "/usr/share/dict/words";
int numero_bits = 20;                     // Número de bits para el hash
ulong numero_palabras = pow(2, numero_bits); // Tamaño del vector para almacenar las palabras
vector<int> vector_palabras(numero_palabras, 0); // Vector que almacena los hash para detectar colisiones

// Función Hash 1: Suma de Caracteres
ulong suma_caracteres_hash(const string &palabra, int numero_bits)
{
    ulong suma = 0;

    // Sumamos el valor ASCII de cada carácter
    for (char c : palabra)
    {
        suma += static_cast<int>(c);
    }

    // Retornamos el número de bits especificado (usamos el módulo para ajustar los bits)
    return suma % (1 << numero_bits); // 1 << numero_bits es 2 elevado a numero_bits
}

// Función Hash 2: Producto de Caracteres
ulong producto_caracteres_hash(const string &palabra, int numero_bits)
{
    ulong producto = 1;

    // Multiplicamos el valor ASCII de cada carácter
    for (char c : palabra)
    {
        producto *= static_cast<int>(c);
        producto %= (1 << numero_bits); // Aplicamos el módulo dentro del loop para evitar overflow
    }

    // Retornamos el número de bits especificado
    return producto;
}

// Función Hash 3: XOR por Fragmentos
ulong xor_fragmentos_hash(const string &palabra, int numero_bits)
{
    ulong resultado_xor = 0;
    ulong valor_fragmento = 0;

    ulong bits_en_fragmento_actual = 0;

    // Recorremos todos los caracteres de la palabra
    for (int i = 0; i < palabra.size(); ++i)
    {
        valor_fragmento = (valor_fragmento << 8) | static_cast<int>(palabra[i]); // Agregamos el valor del carácter al fragmento
        bits_en_fragmento_actual += 8;                                            // Incrementamos los bits actuales en el fragmento

        // Cuando tenemos al menos numero_bits en el fragmento, aplicamos XOR y ajustamos al tamaño de numero_bits
        while (bits_en_fragmento_actual >= numero_bits)
        {
            // Tomamos los primeros numero_bits bits del fragmento
            ulong fragmento_para_xor = valor_fragmento >> (bits_en_fragmento_actual - numero_bits);
            resultado_xor ^= fragmento_para_xor; // Aplicamos XOR al resultado

            // Eliminamos los bits procesados y ajustamos el número de bits restantes
            valor_fragmento &= (1 << (bits_en_fragmento_actual - numero_bits)) - 1;
            bits_en_fragmento_actual -= numero_bits;
        }
    }
    resultado_xor ^= valor_fragmento; // Aplicamos XOR al último fragmento si es que quedan bits

    // Retornamos el resultado limitado a numero_bits
    return resultado_xor & ((1 << numero_bits) - 1); // Aquí limitamos el hash a los bits requeridos (14 bits, o en general, numero_bits)
}

// Función Hash 4: Hash Aleatorio
ulong hash_aleatorio(const string &palabra, int numero_bits)
{
    static mt19937 generador(random_device{}()); // Generador de números aleatorios
    uniform_int_distribution<ulong> distribucion(0, (1 << numero_bits) - 1); // Distribución uniforme en el rango [0, 2^numero_bits - 1]

    // Retornamos el hash limitado a numero_bits
    return distribucion(generador);
}

// Función para leer el archivo y aplicar la función hash
void leer_archivo_y_aplicar_hash(ulong (*funcion_hash)(const string &, int), int numero_bits)
{
    ifstream archivo(ruta_archivo);

    if (archivo.is_open())
    {
        string palabra;
        int colisiones = 0, contador = 0;
        vector_palabras.assign(numero_palabras, 0); // Reiniciamos el vector de palabras

        // Leer línea por línea cada palabra del archivo
        int i = 0;
        while (getline(archivo, palabra))
        {
            // Calculamos la clave hash usando la función hash pasada como parámetro
            ulong valor_hash = funcion_hash(palabra, numero_bits);
            ulong indice = valor_hash % numero_palabras; // Usamos el valor modificado dentro del límite de palabras
            contador++;
            if (vector_palabras[indice] != 1)
            {
                vector_palabras[indice] = 1;
            }
            else
            {
                colisiones++;
            }
            i++;
        }
        cout << "colisiones: " << colisiones << endl;
        cout << "ratio de colisiones: " << (double)colisiones / contador << endl;

        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

int main()
{

    cout << "Aplicando Suma Hash:" << endl;
    leer_archivo_y_aplicar_hash(suma_caracteres_hash, numero_bits);

    cout << "\nAplicando Producto Hash:" << endl;
    leer_archivo_y_aplicar_hash(producto_caracteres_hash, numero_bits);

    cout << "\nAplicando XOR Hash:" << endl;
    leer_archivo_y_aplicar_hash(xor_fragmentos_hash, numero_bits);

    cout << "\nAplicando Random Hash:" << endl;
    leer_archivo_y_aplicar_hash(hash_aleatorio, numero_bits);

    return 0;
}