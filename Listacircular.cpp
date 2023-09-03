#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
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

    if (lista == NULL) {
        nodoNuevo->siguiente = nodoNuevo; // Si la lista está vacía, el siguiente apunta al mismo nodo.
        lista = nodoNuevo; // Ahora la lista apunta al nuevo nodo.
    } else {
        Nodo* ultimo = lista;
        while (ultimo->siguiente != lista) {
            ultimo = ultimo->siguiente; // Encontramos el último nodo.
        }
        nodoNuevo->siguiente = lista; // El nuevo nodo apunta al primero.
        lista = nodoNuevo; // Ahora la lista apunta al nuevo nodo.
        ultimo->siguiente = lista; // El antiguo último nodo apunta al nuevo primero.
    }

    cout << "El elemento " << x << " ha sido insertado al principio de la lista circular" << endl;
}

void insertarAlFinal(Nodo*& lista, int x) {
    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->dato = x;

    if (lista == NULL) {
        nodoNuevo->siguiente = nodoNuevo; // Si la lista está vacía, el siguiente apunta al mismo nodo.
        lista = nodoNuevo; // Ahora la lista apunta al nuevo nodo.
    } else {
        Nodo* ultimo = lista;
        while (ultimo->siguiente != lista) {
            ultimo = ultimo->siguiente; // Encontramos el último nodo.
        }
        nodoNuevo->siguiente = lista; // El nuevo nodo apunta al primero.
        ultimo->siguiente = nodoNuevo; // El antiguo último nodo apunta al nuevo último nodo.
    }

    cout << "El elemento " << x << " ha sido insertado al final de la lista circular" << endl;
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
        if (actual->siguiente == lista) {
            cout << "Posicion no valida" << endl;
            delete nodoNuevo;
            return;
        }
        actual = actual->siguiente;
        contador++;
    }

    nodoNuevo->siguiente = actual->siguiente;
    actual->siguiente = nodoNuevo;

    cout << "El elemento " << x << " ha sido insertado en la posicion " << posicion << " de la lista circular" << endl;
}

void buscarLista(Nodo* lista, int x) {
    Nodo* actual = lista;
    int contador = 1;
    bool encontrado = false;

    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    do {
        if (actual->dato == x) {
            cout << "El elemento " << x << " fue encontrado en la posicion " << contador << " de la lista circular" << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
        contador++;
    } while (actual != lista);

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista circular" << endl;
    }
}

void borrarLista(Nodo*& lista, int x) {
    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    Nodo* actual = lista;
    Nodo* anterior = NULL;
    bool encontrado = false;

    do {
        if (actual->dato == x) {
            if (anterior == NULL) {
                while (actual->siguiente != lista) {
                    actual = actual->siguiente;
                }
                lista = lista->siguiente;
                actual->siguiente = lista;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            cout << "El elemento " << x << " ha sido eliminado de la lista circular" << endl;
            encontrado = true;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != lista);

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista circular" << endl;
    }
}

void actualizarLista(Nodo*& lista, int x, int nuevoDato) {
    Nodo* actual = lista;
    bool encontrado = false;

    if (lista == NULL) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    do {
        if (actual->dato == x) {
            actual->dato = nuevoDato;
            cout << "El elemento " << x << " ha sido actualizado a " << nuevoDato << endl;
            encontrado = true;
            return;
        }
        actual = actual->siguiente;
    } while (actual != lista);

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista circular" << endl;
    }
}

void mostrarLista(Nodo* lista) {
    if (lista == NULL) {
        cout << "Lista vacia." << endl;
        return;
    }

    Nodo* actual = lista;

    cout << "Lista: ";
    do {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != lista);

    cout << endl;
}
