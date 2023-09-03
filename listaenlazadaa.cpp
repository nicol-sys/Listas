#include <iostream>
#include <conio.h>
using namespace std;

struct Nodo { /* representa un nodo en la lista enlazada. Cada nodo contiene un valor (dato) y un puntero al siguiente nodo en la lista (siguiente).*/
    int dato;
    Nodo* siguiente;
};
/*Funciones de operaci�n*/
void insertarAlPrincipio(Nodo*&, int);
void insertarAlFinal(Nodo*&, int);
void insertarEnPosicion(Nodo*&, int, int);
void buscarLista(Nodo*, int);
void borrarLista(Nodo*&, int);
void actualizarLista(Nodo*&, int, int);
void mostrarLista(Nodo*);

int main() {
    Nodo* lista = NULL;
    Nodo* copiaLista = NULL;  /*Nueva lista para copiar la original*/
    int opcion, dato, posicion;

     do {
         //El bucle principal se ejecuta hasta que el usuario selecciona la opci�n "8. Salir".
          
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
//trabajar con la 'copiaLista',las operaciones se realizar�n en esta copia, dejando la lista original'Lista' intacta
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
    Nodo* nodoNuevo = new Nodo(); /*Este nodo  se aloja en la memoria y contendr� el valor x.*/
    nodoNuevo->dato = x; /*se asigna el valor x al miembro dato del nodo*/ 
    nodoNuevo->siguiente = lista; /*apunte al nodo que actualmente est� al principio de la lista*/
    lista = nodoNuevo; /*coloca nodoNuevo al principio de la lista.*/
    cout << "El elemento " << x << " ha sido insertado al principio de la lista original" << endl;
}

void insertarAlFinal(Nodo*& lista, int x) {
    Nodo* nodoNuevo = new Nodo();
    nodoNuevo->dato = x;
    nodoNuevo->siguiente = nullptr; //este nodo ser� el �ltimo nodo de la lista y que su puntero siguiente apuntar� a nullptr.
        //nullptr representa un valor de puntero nulo

    if (lista == nullptr) { //si la lista est� vac�a
        lista = nodoNuevo;
    } else {
        Nodo* actual = lista; //Se crea un puntero 'actual' que se inicializa con la direcci�n del primer nodo de la lista
        while (actual->siguiente != nullptr) { //recorre la lista hasta que se encuentra el �ltimo nodo
            actual = actual->siguiente; //el puntero actual se actualiza para apuntar al siguiente nodo en la lista
        }
        actual->siguiente = nodoNuevo; //enlaza nodoNuevo al final de la lista.
    }

    cout << "El elemento " << x << " ha sido insertado al final de la lista original" << endl;
}

void insertarEnPosicion(Nodo*& lista, int x, int posicion) {
    if (posicion <= 0) {
        cout << "Posicion no valida" << endl;
        return; //la posici�n debe ser un n�mero positivo.
    }

    if (posicion == 1) {
        insertarAlPrincipio(lista, x);
        return;
    } // llama a insertarAlPrincipio para insertar el elemento x al principio de la lista

    Nodo* nodoNuevo = new Nodo(); //Si la posici�n no es 0 ni 1, se crea un nuevo nodo
    nodoNuevo->dato = x;

    Nodo* actual = lista;
    int contador = 1; //Se inicia un contador en 1 para saber la posici�n actual mientras se recorre la lista.

    while (actual != nullptr && contador < posicion - 1) { //recorre la lista hasta que se llega una posicion antes de la desada
        actual = actual->siguiente;//se actualiza para apuntar al siguiente nodo en la lista
        contador++; //el contador se incrementa para llevar un registro de la posici�n actual en la lista.
    }

    if (actual == nullptr) { //la posici�n proporcionada no es v�lida
        cout << "Posicion no valida" << endl;
        delete nodoNuevo;
        return;
    }

    nodoNuevo->siguiente = actual->siguiente; //Si la posici�n es v�lida, se enlaza el nuevo nodo nodoNuevo al nodo que est� en la posici�n deseada
    actual->siguiente = nodoNuevo;

    cout << "El elemento " << x << " ha sido insertado en la posicion " << posicion << " de la lista original" << endl;
}

void buscarLista(Nodo* lista, int x) {
    Nodo* actual = lista;
    int contador = 1;
    bool encontrado = false; //una variable booleana encontrado en false. Esta variable se utiliza para indicar si se ha encontrado el valor x en la lista.

    while (actual != NULL) { //mientras el puntero actual no sea NULL.
        if (actual->dato == x) { //si el valor (dato) del nodo actual (actual->dato) es igual al valor buscado (x).
            cout << "El elemento " << x << " fue encontrado en la posicion " << contador << " de la lista original" << endl;
            encontrado = true; //indicar que se ha encontrado el valor x.
        }
        actual = actual->siguiente; //el puntero actual se actualiza para apuntar al siguiente nodo en la lista
        contador++; //El contador se incrementa en cada iteraci�n para llevar un registro de la posici�n actual en la lista
    }

    if (!encontrado) { //se verifica si la variable encontrado es false
        cout << "El elemento " << x << " no fue encontrado en la lista original" << endl;
    }
}

void borrarLista(Nodo*& lista, int x) {
    Nodo* actual = lista;
    Nodo* anterior = NULL; //puntero anterior y se inicializa en NULL
    bool encontrado = false; //se utilizar� para indicar si se ha encontrado el valor x en la lista.

    while (actual != NULL) { //bucle hasta que llegue al final de la lista 
        if (actual->dato == x) { //si el valor buscado es igual a x
            if (anterior == NULL) { //anterior es NULL se va a eliminar es el primer nodo de la lista.
                lista = actual->siguiente; //e actualiza el puntero lista para que apunte al siguiente nodo
            } else {
                anterior->siguiente = actual->siguiente; //Aqu� se actualiza el puntero siguiente del nodo anterior (anterior) para que apunte al nodo siguiente (actual->siguiente). Esto elimina el nodo actual de la lista.
            }
            delete actual;
            cout << "El elemento " << x << " ha sido eliminado de la lista original" << endl;
            encontrado = true;
            return;
        }
        anterior = actual;
        actual = actual->siguiente; // El puntero actual se actualiza para apuntar al siguiente nodo en la lista
    }

    if (!encontrado) {
        cout << "El elemento " << x << " no fue encontrado en la lista original" << endl;
    }
}

void actualizarLista(Nodo*& lista, int x, int nuevoDato) { 
    /*nuevoDato, que es el nuevo valor con el que se actualizar� x.*/
    Nodo* actual = lista;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->dato == x) { //si el dato del nodo actual es igual a x
            actual->dato = nuevoDato; //se actualiza con el nuevo dato
            cout << "El elemento " << x << " ha sido actualizado a " << nuevoDato << endl;
            encontrado = true;
            return;
        }
        actual = actual->siguiente; //apuntar al siguiente nodo en la lista
    }

    if (!encontrado) { //si el bool es falso
        cout << "El elemento " << x << " no fue encontrado en la lista" << endl;
    }
}

void mostrarLista(Nodo* lista) {
    Nodo* actual = lista;
    cout << "Lista: ";
    while (actual != NULL) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}
