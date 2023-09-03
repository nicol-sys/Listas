#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente; //puntero siguiente 
    Nodo* anterior;//puntero anterior 
};

void insertarAlPrincipio(Nodo*&, int);
void insertarAlFinal(Nodo*&, int);
void insertarEnPosicion(Nodo*&, int, int);
void buscarLista(Nodo*, int);
void borrarLista(Nodo*&, int);
void actualizarLista(Nodo*&, int, int);
void mostrarLista(Nodo*);

int main() {
    Nodo* lista = NULL;
    Nodo* copiaLista = NULL;
    int opcion, dato, posicion;

    do {
        cout << "MENU DE OPCIONES" << endl;
        cout << "1. Insertar al principio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en una posicion" << endl;
        cout << "4. Buscar valor" << endl;
        cout << "5. Borrar valor" << endl;
        cout << "6. Actualizar valor" << endl;
        cout << "7. Mostrar lista" << endl;
        cout << "8. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Digite un numero: ";
                cin >> dato;
                insertarAlPrincipio(copiaLista, dato);
                break;

            case 2:
                cout << "Digite un numero: ";
                cin >> dato;
                insertarAlFinal(copiaLista, dato);
                break;

            case 3:
                cout << "Digite un numero: ";
                cin >> dato;
                cout << "Digite la posicion: ";
                cin >> posicion;
                insertarEnPosicion(copiaLista, dato, posicion);
                break;

            case 4:
                cout << "Digite el valor a buscar: ";
                cin >> dato;
                buscarLista(copiaLista, dato);
                break;

            case 5:
                cout << "Digite el valor a borrar: ";
                cin >> dato;
                borrarLista(copiaLista, dato);
                break;

            case 6:
                int nuevoDato;
                cout << "Digite el valor a actualizar: ";
                cin >> dato;
                cout << "Digite el nuevo valor: ";
                cin >> nuevoDato;
                actualizarLista(copiaLista, dato, nuevoDato);
                break;

            case 7:
                mostrarLista(copiaLista);
                break;

            case 8:
                break;

            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}

void insertarAlPrincipio(Nodo*& lista, int x) {
    Nodo* nodoNuevo = new Nodo(); 
    nodoNuevo->dato = x;

    if (lista == NULL) { //si la lista está vacía.
        nodoNuevo->siguiente = NULL; //no hay ningún nodo siguiente en una lista vacía
        nodoNuevo->anterior = NULL;
        lista = nodoNuevo;
    } else {
        nodoNuevo->siguiente = lista;
        nodoNuevo->anterior = NULL;
        lista->anterior = nodoNuevo;
        lista = nodoNuevo;
    }

    cout << "El elemento " << x << " ha sido insertado al principio de la lista doblemente enlazada" << endl;
}

void insertarAlFinal(Nodo*& lista, int x) {
    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->dato = x;

    if (lista == NULL) {
        nodoNuevo->siguiente = NULL;
        nodoNuevo->anterior = NULL;
        lista = nodoNuevo;
    } else {
        Nodo* ultimo = lista; //puntero llamado ultimo,se inicializa con la dirección del primer nodo de la lista 
        while (ultimo->siguiente != NULL) { //recorre la lista hasta encontrar el último nodo
            ultimo = ultimo->siguiente;
        }
        nodoNuevo->siguiente = NULL;
        nodoNuevo->anterior = ultimo; //el puntero `anteriordel nuevo nodo para que puntear al último nodo de la lista
        ultimo->siguiente = nodoNuevo;
    }

    cout << "El elemento " << x << " ha sido insertado al final de la lista doblemente enlazada" << endl;
}

void insertarEnPosicion(Nodo*& lista, int x, int posicion) {
    if (posicion <= 0) {
        cout << "Posicion no valida" << endl;
        return;
    }

    if (posicion == 1) {
        insertarAlPrincipio(lista, x);
        return;
    }

    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->dato = x;

    Nodo* actual = lista;
    int contador = 1;

    while (contador < posicion - 1) {
        if (actual == NULL) {
            cout << "Posicion no valida" << endl;
            delete nodoNuevo;
            return;
        }
        actual = actual->siguiente;
        contador++;
    }

    if (actual == NULL) {
        cout << "Posicion no valida" << endl;
        delete nodoNuevo;
        return;
    }

    nodoNuevo->siguiente = actual->siguiente;
    nodoNuevo->anterior = actual;
    if (actual->siguiente != NULL) { //Si actual no es NULL, avanzamos al siguiente nodo de la lista
        actual->siguiente->anterior = nodoNuevo;
    }
    actual->siguiente = nodoNuevo;

    cout << "El elemento " << x << " ha sido insertado en la posicion " << posicion << " de la lista doblemente enlazada" << endl;
}

void buscarLista(Nodo* lista, int x) {
    Nodo* actual = lista;
    int contador = 1;
    bool encontrado = false;

    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    while (actual != NULL) {
        if (actual->dato == x) {
            cout << "El elemento " << x << " fue encontrado en la posicion " << contador << " de la lista doblemente enlazada" << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
        contador++;
    }

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista doblemente enlazada" << endl;
    }
}

void borrarLista(Nodo*& lista, int x) {
    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* actual = lista;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == x) { //se verifica si el valor almacenado en el nodo actual es igual a x.
            if (actual->anterior == NULL) { //Si el nodo a eliminar es el primer nodo de la lista se actualiza el puntero lista
                lista = actual->siguiente; 
                if (actual->siguiente != NULL) { //Si el nodo siguiente (actual->siguiente) no es NULL, se actualiza el puntero anterior del nodo siguiente para que apunte a NULL.
                    actual->siguiente->anterior = NULL;
                }
            } else { //Si el nodo a eliminar no es el primero de la lista, se actualizan los punteros siguiente y anterior de los nodos adyacentes para "saltar" el nodo actual. Esto se hace para eliminar el nodo actual sin romper la continuidad de la lista doblemente enlazada.
                actual->anterior->siguiente = actual->siguiente;
                if (actual->siguiente != NULL) {
                    actual->siguiente->anterior = actual->anterior;
                }
            }
            delete actual;
            cout << "El elemento " << x << " ha sido eliminado de la lista doblemente enlazada" << endl;
            encontrado = true;
            return;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista doblemente enlazada" << endl;
    }
}

void actualizarLista(Nodo*& lista, int x, int nuevoDato) {
    Nodo* actual = lista;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == x) {
            actual->dato = nuevoDato;
            cout << "El elemento " << x << " ha sido actualizado a " << nuevoDato << endl;
            encontrado = true;
            return;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista doblemente enlazada" << endl;
    }
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = lista;

    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    cout << "Lista: ";
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }

    cout << endl;
}
