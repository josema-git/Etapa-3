# Manejo de Memoria y Punteros en C++

## Manejo de Memoria

### Componentes Principales
1. **CPU**: El "cerebro" de la computadora. Realiza actividades lógicas, matemáticas y de control.
2. **RAM**: Almacena datos relacionados con el programa, incluyendo el código a ejecutar y las variables utilizadas.

La CPU y la RAM se comunican constantemente: la RAM almacena la información y la CPU la lee y ejecuta.

### Segmentación de la Memoria
El sistema operativo gestiona los recursos y crea un espacio en la memoria para cada programa en ejecución. Este espacio se divide en secciones:

1. **Código ejecutable**: Almacena las instrucciones del programa.
2. **Literales no ejecutables**: Almacena variables que no cambian durante la ejecución del programa.

   Ejemplo:
   ```cpp
   cout << "Hola mundo";
   char dorime[6] = 'Dorime';
   ```

3. **Variables declaradas**: Contiene datos estáticos. Las variables con tamaño definido reservan espacio aquí.
4. **Memoria Dinámica**: 
   - **Heap**: Almacena memoria dinámica controlada por el programador.
   - **Stack**: Gestionado por el compilador, mantiene información de llamadas a funciones y datos temporales.

## Punteros

Los punteros son variables que almacenan direcciones de memoria de otras variables.

### Detalles Importantes
- El tipo de dato del puntero debe coincidir con el de la variable a la que apunta.
- Se usa el asterisco (*) para acceder al valor al que apunta el puntero.
- Sin el asterisco, se accede a la dirección de memoria.
- Es crucial liberar la memoria usada con `delete` después de usar punteros, especialmente con arreglos.
- Los punteros pueden ser de cualquier tipo de dato, incluso tipos complejos.

### Ejemplos de Uso

1. Manipulación básica de punteros:
   ```cpp
   int main()
   {
       int numero = 5896;
       int *puntero = &numero;
       cout << "Direccion de memoria del numero: " << &numero << endl;
       cout << "Direccion del puntero: " << &puntero << endl;
       cout << "Direccion de memoria a la que apunta el puntero: " << puntero << endl;
       cout << "Valor del puntero: "<< *puntero << endl;

       // Cambiando el valor del numero desde el puntero
       *puntero = 1111;
       cout << numero;
       return 0;
   }
   ```

2. Inicialización y uso de punteros:
   ```cpp
   int main() {
       char *puntero = NULL; // Inicialización recomendada
       char letra;
       puntero = &letra;
       *puntero = 'x';
       cout << letra; // Muestra 'x'
   }
   ```

# Curso de Programación Orientada a Objetos en C++ - Parte 2

## 3. Uso Avanzado de Punteros

### Aritmética de Punteros
- Un arreglo es en realidad un puntero que apunta a la primera dirección de memoria del arreglo.
- La aritmética de punteros permite navegar por los elementos de un arreglo.

Ejemplo:
```cpp
int arreglo[] = { 10, -99, 4 };
cout << "Dir. hexadecimal del arreglo: " << arreglo << endl;
cout << "Dir. hexadecimal del arreglo en index 1: " << arreglo + 1 << endl;
cout << "Contenido de index 0: " << *(arreglo + 0) << endl;
```

### Punteros en Funciones
Los punteros permiten modificar variables del main desde una función sin usar return.

Ejemplo:
```cpp
void cambio(char *c){
    *c = 'q';
}

int main(){
    char caracter = 'a';
    cambio(&caracter);
    cout << "El caracter final es: " << caracter;
    return 0;
}
```

## 4. Estructuras de Datos

### Arreglos y Memoria
- Cada elemento de un arreglo (unidimensional o bidimensional) tiene su propia dirección de memoria.
- En C++, la memoria se maneja de forma manual, a diferencia de lenguajes como JavaScript o Python.

Ejemplo:
```cpp
int Arreglo[4] = {1,2,3,4};
for (int i = 0; i < 4; i++) {
    int *puntero = &Arreglo[i];
    cout << "El valor " << *puntero << " tiene la dirección " << puntero << endl;
}
```

### Arreglos de Caracteres
En C++, los arreglos de caracteres (strings) tienen un carácter de cierre '\0'.

Ejemplo:
```cpp
char array1[] = "Hola"; // Longitud real: 5 (incluye '\0')
char array2[50];
strcpy(array2, "holi");
```

## 5. Creando una Estructura

### Asignación de Memoria
Hay dos formas principales de crear objetos:

1. Asignación estática (stack):
   ```cpp
   Persona p = Persona();
   ```

2. Asignación dinámica (heap):
   ```cpp
   Persona *p = new Persona();
   ```

La asignación dinámica requiere liberar la memoria manualmente:
```cpp
delete p;
```

## 6. Uniones y Enumeraciones

### Uniones
Las uniones permiten almacenar diferentes tipos de datos en la misma ubicación de memoria, ahorrando espacio.

Ejemplo:
```cpp
union number_letter {
    int number;
    char letter;
};
```

### Enumeraciones
Las enumeraciones permiten crear un tipo de dato con un conjunto fijo de constantes.

Ejemplo:
```cpp
enum days_of_week { monday = 'M', tuesday = 'T', friday = 'F' };
```

## 7. Introducción a la Programación Orientada a Objetos

### Conceptos Básicos
- Clases: Plantillas para crear objetos.
- Objetos: Instancias de una clase.
- Atributos: Características de un objeto.
- Métodos: Acciones que puede realizar un objeto.

### Principios de POO
- Abstracción: Modelar objetos del mundo real en código.
- Encapsulamiento: Ocultar los detalles internos de un objeto.

## 8. Creando Nuestro Primer Objeto

Ejemplo de una clase simple:
```cpp
class Persona {
  public:
    string nombre = "Luis";
    int edad = 22;
    void saludar(string persona) {
        cout << "Soy " << nombre << endl << "¡Saludos, " << persona << "!" << endl;
    }
};
```

Uso de la clase:
```cpp
int main() {
    Persona *persona1 = new Persona();
    persona1->saludar("Amigo");
    delete persona1;
    return 0;
}
```

## 9. Ciclo de Vida de un Objeto

El ciclo de vida de un objeto incluye:
1. Creación (constructor)
2. Uso (acceso a atributos y métodos)
3. Destrucción (destructor)

Nota: En C++, es importante manejar adecuadamente la memoria, especialmente cuando se usan punteros y asignación dinámica.

# Curso de Programación Orientada a Objetos en C++ - Parte 3

## 9. Ciclo de Vida de un Objeto

El ciclo de vida de un objeto en C++ consta de las siguientes etapas:

1. Reserva de espacio en memoria
2. Invocación del constructor
3. Período de actividad
4. Invocación del destructor
5. Liberación del espacio en memoria

### Constructores y Destructores

```cpp
class Person {
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    ~Person() {
        cout << "Destruction" << endl;
    }
};
```

## 10. Encapsulamiento

El encapsulamiento es un principio que oculta los detalles internos de una clase y expone solo lo necesario.

```cpp
class Person {
private:
    string name;
    int age;

public:
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};
```

## 11. Puntero 'this'

El puntero 'this' se refiere al objeto actual de la clase.

```cpp
class Person {
public:
    Person& setName(string name) {
        this->name = name;
        return *this;
    }
};
```

## 12. Miembros Estáticos

Los miembros estáticos pertenecen a la clase en lugar de a instancias específicas.

```cpp
class Person {
public:
    static int number_of_persons;
    Person() {
        number_of_persons++;
    }
};

int Person::number_of_persons = 0;
```

## 13. Herencia

La herencia permite que una clase (subclase) herede atributos y métodos de otra clase (superclase).

```cpp
class Animal {
protected:
    string alimento;
public:
    void comer() {
        cout << "Este animal está comiendo " << alimento << endl;
    }
};

class Herviboro : public Animal {
public:
    Herviboro() {
        this->alimento = "plantas";
    }
};
```

### Modificadores de Acceso en la Herencia

- **public**: Los miembros públicos de la clase base son públicos en la clase derivada.
- **protected**: Los miembros públicos y protegidos de la clase base son protegidos en la clase derivada.
- **private**: Los miembros públicos y protegidos de la clase base son privados en la clase derivada.

## 14. Herencia Múltiple

C++ permite que una clase herede de múltiples clases base.

```cpp
class Omnivoro : public Herviboro, public Carnivoro {
public:
    Omnivoro() : Herviboro(), Carnivoro() {}
    void comer() {
        cout << "Este animal come lo que sea" << endl;
    }
};
```

## 15. Polimorfismo

El polimorfismo permite que objetos de diferentes clases sean tratados como objetos de una clase base común.

### Polimorfismo de Sobrecarga (Overloading)

Múltiples funciones con el mismo nombre pero diferentes parámetros.

### Polimorfismo de Sobreescritura (Overriding)

Una subclase proporciona una implementación específica de un método ya definido en su superclase.

```cpp
class Animal {
public:
    virtual void comer() {
        cout << "Animal comiendo" << endl;
    }
};

class Herviboro : public Animal {
public:
    void comer() override {
        cout << "Herbívoro comiendo plantas" << endl;
    }
};
```

### Casting en C++

- **static_cast**: Para conversiones entre tipos relacionados.
- **dynamic_cast**: Para conversiones polimórficas seguras.
- **const_cast**: Para agregar o quitar la cualidad de constante.
- **reinterpret_cast**: Para conversiones de bajo nivel entre punteros.

Ejemplo de `static_cast`:

```cpp
Animal* a = new Herviboro();
Herviboro* h = static_cast<Herviboro*>(a);
```