#include <iostream>

using namespace std;

template <typename Dato>
class ListaSimple
{
private:
    struct Nodo
    {
        Dato valor;
        Nodo *siguiente;
    } *Cabeza;

public:
    ListaSimple();
    ~ListaSimple();
    Dato insertar_nodo(Dato);
    Dato borrar_nodo(Dato);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename Dato>
class ListaDoble
{
private:
    struct Nodo
    {
        Dato valor;
        Nodo *siguiente;
        Nodo *anterior;
    } *Cabeza;

public:
    ListaDoble();
    ~ListaDoble();
    Dato insertar_nodo(Dato);
    Dato borrar_nodo(Dato);
    int imprimir_lista();
    int organizar_lista();
    int reversar_lista();
};

template <typename Dato>
class ListaCircular
{
    private:
    struct Nodo{
        Dato valor;
        Nodo *siguiente;
    } *Cabeza;

    public:
        ListaCircular();
        ~ListaCircular();
        Dato insertar_nodo(Dato);
        Dato borrar_nodo(Dato);
        int imprimir_lista();
        int organizar_lista();
        int reversar_lista();
};

template <typename Dato>
class Pila
{
    private:
        struct Nodo{
            Dato valor;
            Nodo *siguiente;
        } *Cabeza;

    public:

        Pila();
        ~Pila();
        Dato insertar_nodo(Dato);
        Dato borrar_nodo();
        int imprimir_pila();
};

template <typename Dato>
class Cola
{
    private:
        struct Nodo{
            Dato valor;
            Nodo *siguiente;
        } *Cabeza;

    public:

        Cola();
        ~Cola();
        Dato insertar_nodo(Dato);
        Dato borrar_nodo();
        int imprimir_cola();
};

int main()
{
    // ListaSimple<int> *lista = new ListaSimple<int>;
    // lista->insertar_nodo(1);
    // lista->insertar_nodo(3);
    // lista->insertar_nodo(7);
    // lista->insertar_nodo(5);
    // lista->insertar_nodo(6);
    // lista->insertar_nodo(4);
    // lista->insertar_nodo(2);
    // lista->imprimir_lista();
    // lista->organizar_lista();
    // lista->imprimir_lista();
    // lista->reversar_lista();
    // lista->imprimir_lista();
    // delete lista;

    // ListaDoble<int> *listadoble = new ListaDoble<int>;
    // listadoble->insertar_nodo(1);
    // listadoble->insertar_nodo(3);
    // listadoble->insertar_nodo(7);
    // listadoble->insertar_nodo(5);
    // listadoble->insertar_nodo(6);
    // listadoble->insertar_nodo(4);
    // listadoble->insertar_nodo(2);
    // listadoble->imprimir_lista();
    // listadoble->organizar_lista();
    // listadoble->imprimir_lista();
    // listadoble->reversar_lista();
    // listadoble->imprimir_lista();
    // listadoble->borrar_nodo(4);
    // listadoble->imprimir_lista();
    // delete listadoble;

    // ListaCircular<int> *listacircular = new ListaCircular<int>;
    // listacircular->insertar_nodo(1);
    // listacircular->insertar_nodo(3);
    // listacircular->insertar_nodo(7);
    // listacircular->insertar_nodo(5);
    // listacircular->insertar_nodo(6);
    // listacircular->insertar_nodo(4);
    // listacircular->insertar_nodo(2);
    // listacircular->imprimir_lista();
    // listacircular->organizar_lista();
    // listacircular->imprimir_lista();
    // listacircular->reversar_lista();
    // listacircular->imprimir_lista();
    // delete listacircular;

    // Pila<int> *pila = new Pila<int>;
    // pila->insertar_nodo(1);
    // pila->insertar_nodo(3);
    // pila->insertar_nodo(7);
    // pila->insertar_nodo(5);
    // pila->insertar_nodo(6);
    // pila->insertar_nodo(4);
    // pila->insertar_nodo(2);
    // pila->imprimir_pila();
    // pila->borrar_nodo();
    // pila->imprimir_pila();
    // delete pila;

    // Cola<int> *cola = new Cola<int>;
    // cola->insertar_nodo(1);
    // cola->insertar_nodo(3);
    // cola->insertar_nodo(7);
    // cola->insertar_nodo(5);
    // cola->insertar_nodo(6);
    // cola->insertar_nodo(4);
    // cola->insertar_nodo(2);
    // cola->imprimir_cola();
    // cola->borrar_nodo();
    // cola->imprimir_cola();
    // delete cola;

    return 0;
}


// Lista simple
// template <typename Dato>
// ListaSimple<Dato>::ListaSimple()
// {
//     Cabeza = NULL;
// }
// template <typename Dato>
// ListaSimple<Dato>::~ListaSimple()
// {
//     while (Cabeza != NULL)
//     {
//         Nodo *aux = Cabeza;
//         Cabeza = Cabeza->siguiente;
//         delete aux;
//     }
//     cout << "Se ha destruido una lista simple" << endl;
// }
// template <typename Dato>
// Dato ListaSimple<Dato>::insertar_nodo(Dato x)
// {
//     Nodo *NuevoNodo = new Nodo;
//     NuevoNodo->valor = x;
//     NuevoNodo->siguiente = NULL;
//     if (Cabeza == NULL)
//     {
//         Cabeza = NuevoNodo;
//         return NuevoNodo->valor;
//     }
//     else
//     {
//         Nodo *aux = Cabeza;
//         while (aux->siguiente != NULL)
//         {
//             aux = aux->siguiente;
//         }
//         aux->siguiente = NuevoNodo;
//         return NuevoNodo->valor;
//     }
// }
// template <typename Dato>
// int ListaSimple<Dato>::imprimir_lista()
// {
//     if (Cabeza == NULL)
//     {
//         cout << "No hay elementos en esta lista" << endl;
//         return -1;
//     }
//     else
//     {
//         Nodo *aux = Cabeza;
//         cout << aux->valor;
//         while (aux->siguiente != NULL)
//         {
//             aux = aux->siguiente;
//             cout << " -> " << aux->valor;
//         }
//         cout << endl;
//         return 1;
//     }
// }
// template <typename Dato>
// Dato ListaSimple<Dato>::borrar_nodo(Dato x)
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     if (Cabeza->siguiente == NULL)
//     {
//         if (Cabeza->valor == x)
//         {
//             delete Cabeza;
//             Cabeza = NULL;
//             return x;
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != NULL)
//     {
//         if (aux1->siguiente->valor == x)
//         {
//             aux2 = aux1->siguiente;
//             aux1->siguiente = aux2->siguiente;
//             delete aux2;
//             return x;
//             break;
//         }
//         else
//         {
//             aux1 = aux1->siguiente;
//         }
//     }
//     return 0;
// }
// template <typename Dato>
// int ListaSimple<Dato>::organizar_lista()
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != NULL)
//     {
//         aux2 = aux1->siguiente;
//         while (aux2 != NULL)
//         {
//             if (aux1->valor > aux2->valor)
//             {
//                 Dato temp = aux1->valor;
//                 aux1->valor = aux2->valor;
//                 aux2->valor = temp;
//             }
//             aux2 = aux2->siguiente;
//         }
//         aux1 = aux1->siguiente;
//     }
//     return 1;
// }
// template <typename Dato>
// int ListaSimple<Dato>::reversar_lista()
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2 = Cabeza->siguiente;
//     for (int i = 0; aux1->siguiente; i++)
//     {
//         aux1->siguiente = aux2->siguiente;
//         aux2->siguiente = Cabeza;
//         Cabeza = aux2;
//         aux2 = aux1->siguiente;
//     }
//     return 1;
// }

// Lista doble
// template <typename Dato>
// ListaDoble<Dato>::ListaDoble()
// {
//     Cabeza = NULL;
// }
// template <typename Dato>
// ListaDoble<Dato>::~ListaDoble()
// {
//     while (Cabeza != NULL)
//     {
//         Nodo *aux = Cabeza;
//         Cabeza = Cabeza->siguiente;
//         delete aux;
//     }
//     cout << "Se ha destruido una lista doble" << endl;
// }
// template <typename Dato>
// Dato ListaDoble<Dato>::insertar_nodo(Dato x)
// {
//     Nodo *nuevo_nodo = new Nodo;
//     nuevo_nodo->valor = x;
//     nuevo_nodo->siguiente = NULL, nuevo_nodo->anterior = NULL;
//     if (Cabeza == NULL)
//     {
//         Cabeza = nuevo_nodo;
//         return nuevo_nodo->valor;
//     }
//     Nodo *aux = Cabeza;
//     while (aux->siguiente != NULL)
//     {
//         aux = aux->siguiente;
//     }
//     aux->siguiente = nuevo_nodo;
//     nuevo_nodo->anterior = aux;
//     return nuevo_nodo->valor;
// }
// template <typename Dato>
// Dato ListaDoble<Dato>::borrar_nodo(Dato x)
// {
//     Nodo *aux1 = Cabeza;
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     else if (Cabeza->valor == x)
//     {
//         Cabeza = Cabeza->siguiente;
//         delete aux1;
//         return x;
//     }
//     while (aux1 != NULL)
//     {
//         if (aux1->valor == x)
//         {
//             aux1->anterior->siguiente = aux1->siguiente;
//             aux1->siguiente->anterior = aux1->anterior;
//             delete aux1;
//             return x;
//         }
//         aux1 = aux1->siguiente;
//     }
//     return 0;
// }
// template <typename Dato>
// int ListaDoble<Dato>::imprimir_lista()
// {
//     if (Cabeza == NULL)
//     {
//         cout << "La lista esta vacia" << endl;
//         return -1;
//     }
//     Nodo *aux = Cabeza;
//     cout << aux->valor;
//     while (aux->siguiente != NULL)
//     {
//         aux = aux->siguiente;
//         cout << " <-> " << aux->valor;
//     }
//     cout << endl;
//     return 1;
// }
// template <typename Dato>
// int ListaDoble<Dato>::organizar_lista()
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != NULL)
//     {
//         aux2 = aux1->siguiente;
//         while (aux2 != NULL)
//         {
//             if (aux1->valor > aux2->valor)
//             {
//                 Dato temp = aux1->valor;
//                 aux1->valor = aux2->valor;
//                 aux2->valor = temp;
//             }
//             aux2 = aux2->siguiente;
//         }
//         aux1 = aux1->siguiente;
//     }
//     return 1;
// }
// template <typename Dato>
// int ListaDoble<Dato>::reversar_lista()
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != NULL)
//     {
//         aux2 = aux1->siguiente;
//         aux1->siguiente->anterior = aux1;
//         aux1->siguiente = aux2->siguiente;
//         aux2->siguiente = Cabeza;
//         Cabeza->anterior = aux2;
//         Cabeza = aux2;
//         Cabeza->anterior = NULL;
//     }
//     return 1;
// }

// lista circular
// template<typename Dato>
// ListaCircular<Dato>:: ListaCircular(){
//     Cabeza = NULL;
//     cout << "se ha creado una lista circular" << endl;
// }
// template<typename Dato>
// ListaCircular<Dato>::~ListaCircular(){
//     if (Cabeza != NULL) {
//         Nodo *aux1 = Cabeza;
//         Nodo *aux2;
//         while (aux1->siguiente != Cabeza) {
//             aux2 = aux1;
//             aux1 = aux1->siguiente;
//             delete aux2;
//         }
//         delete aux1;
//     }
//     cout << "Se ha destruido una lista circular" << endl;
// }
// template<typename Dato>
// Dato ListaCircular<Dato>::insertar_nodo(Dato valor){
//     Nodo *nuevo_nodo = new Nodo;
//     nuevo_nodo->valor = valor;
//     if (Cabeza == NULL){
//         Cabeza =nuevo_nodo;
//         Cabeza->siguiente = nuevo_nodo;
//         return valor;
//     }
//     Nodo *aux = Cabeza;
//     while (aux->siguiente != Cabeza){
//         aux = aux->siguiente;
//     }
//     aux->siguiente = nuevo_nodo;
//     nuevo_nodo->siguiente = Cabeza;
//     return valor;
// }
// template<typename Dato>
// Dato ListaCircular<Dato>::borrar_nodo(Dato valor){
//     if (Cabeza == NULL){
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     if (Cabeza->valor == valor){
//         if (Cabeza->siguiente == Cabeza){
//             delete Cabeza;
//             Cabeza = NULL;
//             return valor;
//         }
//         while (aux1->siguiente != Cabeza){
//             aux1 = aux1->siguiente;
//         }
//         aux1->siguiente = Cabeza->siguiente;
//         aux1 = Cabeza;
//         Cabeza = Cabeza->siguiente;
//         delete aux1;
//         return valor;
//     }
//     Nodo *aux2;
//     while (aux1->siguiente != Cabeza){
//         if (aux1->siguiente->valor == valor){
//             aux2 = aux1->siguiente;
//             aux1->siguiente = aux2->siguiente;
//             delete aux2;
//             return valor;
//             break;
//         }else{
//             aux1 = aux1->siguiente;
//         }
//     }
//     return valor;
// }
// template<typename Dato>
// int ListaCircular<Dato>::imprimir_lista(){
//     if (Cabeza == NULL){
//         cout << "No hay elementos en la lista" << endl;
//         return -1;
//     }
//     Nodo *aux = Cabeza->siguiente;
//     cout << Cabeza->valor;
//     while (aux != Cabeza){
//         cout << " -> " << aux->valor;
//         aux = aux->siguiente;
//     }
//     cout << endl;
//     return 1;
// }
// template<typename Dato>
// int ListaCircular<Dato>::organizar_lista(){
//     if (Cabeza == NULL)
//     {
//         return -1;
//     } 
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != Cabeza){
//         aux2= aux1->siguiente;
//         while(aux2 !=Cabeza){
//             if(aux1->valor < aux2->valor){
//                 int temp = aux2->valor;
//                 aux2->valor = aux1->valor;
//                 aux1->valor = temp;
//             }
//             aux2 = aux2->siguiente;
//         }
//         aux1 = aux1->siguiente;
//     }
//     return 1;
// }
// template<typename Dato>
// int ListaCircular<Dato>::reversar_lista(){
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux1 = Cabeza;
//     Nodo *aux2;
//     while (aux1->siguiente != aux1)
//     {
//         aux2 = aux1->siguiente;
//         aux1->siguiente = aux2->siguiente;
//         aux2->siguiente = Cabeza; 
//         Cabeza = aux2;
//     }
//     aux1->siguiente = Cabeza;
//     return 1;
// }

// Pilas
// template <typename Dato>
// Pila<Dato>::Pila() {
//     Cabeza = NULL;
// }
// template <typename Dato>
// Pila<Dato>::~Pila() {
//     while (Cabeza != NULL) {
//         Nodo *aux = Cabeza;
//         Cabeza = Cabeza->siguiente;
//         delete aux;
//     }
//     cout << "Se ha destruido una pila" << endl;
// }
// template <typename Dato>
// Dato Pila<Dato>::insertar_nodo(Dato x) {
//     Nodo *nuevo_nodo = new Nodo;
//     nuevo_nodo->valor = x;
//     nuevo_nodo->siguiente = Cabeza;
//     Cabeza = nuevo_nodo;
//     return x;
// }
// template <typename Dato>
// Dato Pila<Dato>::borrar_nodo() {
//     if (Cabeza == NULL) {
//         return -1;
//     }
//     Nodo *aux = Cabeza;
//     Cabeza = Cabeza->siguiente;
//     Dato valor = aux->valor;
//     delete aux;
//     return valor;
// }
// template <typename Dato>
// int Pila<Dato>::imprimir_pila() {
//     if (Cabeza == NULL) {
//         cout << "La pila esta vacia" << endl;
//         return -1;
//     }
//     Nodo *aux = Cabeza;
//     while (aux != NULL) {
//         cout << aux->valor << " ";
//         aux = aux->siguiente;
//     }
//     cout << endl;
//     return 1;
// }

//colas
// template <typename Dato>
// Cola<Dato>::Cola()
// {
//     Cabeza = NULL;
// }
// template <typename Dato>
// Cola<Dato>::~Cola()
// {
//     while (Cabeza != NULL)
//     {
//         Nodo *aux = Cabeza;
//         Cabeza = Cabeza->siguiente;
//         delete aux;
//     }
//     cout << "Se ha destruido una cola" << endl;
// }
// template <typename Dato>
// Dato Cola<Dato>::insertar_nodo(Dato x)
// {
//     Nodo *nuevo_nodo = new Nodo;
//     nuevo_nodo->valor = x;
//     nuevo_nodo->siguiente = NULL;
//     if (Cabeza == NULL)
//     {
//         Cabeza = nuevo_nodo;
//         return x;
//     }
//     Nodo *aux = Cabeza;
//     while (aux->siguiente != NULL)
//     {
//         aux = aux->siguiente;
//     }
//     aux->siguiente = nuevo_nodo;
//     return x;
// }
// template <typename Dato>
// Dato Cola<Dato>::borrar_nodo()
// {
//     if (Cabeza == NULL)
//     {
//         return -1;
//     }
//     Nodo *aux = Cabeza;
//     Cabeza = Cabeza->siguiente;
//     Dato valor = aux->valor;
//     delete aux;
//     return valor;
// }
// template <typename Dato>
// int Cola<Dato>::imprimir_cola()
// {
//     if (Cabeza == NULL)
//     {
//         cout << "La cola esta vacia" << endl;
//         return -1;
//     }
//     Nodo *aux = Cabeza;
//     while (aux != NULL)
//     {
//         cout << aux->valor << " ";
//         aux = aux->siguiente;
//     }
//     cout << endl;
//     return 1;
// }







