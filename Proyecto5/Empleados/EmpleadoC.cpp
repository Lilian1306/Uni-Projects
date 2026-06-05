#include <iostream>
#include <string>

using namespace std;

struct NodoLibro {
    string nombreLibro;
    NodoLibro* siguiente;
};


void pushPila(NodoLibro*& cima, string valor) {
    NodoLibro* nuevoNodo = new NodoLibro();
    nuevoNodo->nombreLibro = valor;
    nuevoNodo->siguiente = cima; 
    cima = nuevoNodo;           
    cout << "Libro \"" << valor << "\" agregado a la pila.\n";
}


void mostrarPila(NodoLibro* cima) {
    if (cima == nullptr) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }
    cout << "\n--- Libros en la Pila ---\n";
    NodoLibro* actual = cima;
    while (actual != nullptr) {
        cout << "- " << actual->nombreLibro << "\n";
        actual = actual->siguiente;
    }
    cout << "-----------------------------------------\n";
}


void popPila(NodoLibro*& cima) {
    if (cima == nullptr) {
        cout << "Error: La pila esta vacia. No se puede eliminar.\n";
        return;
    }
    NodoLibro* temp = cima;
    cout << "Libro eliminado: \"" << temp->nombreLibro << "\"\n";
    cima = cima->siguiente; 
    delete temp;            
}

// 4. Ver libro en la cima (Top)
void verCima(NodoLibro* cima) {
    if (cima == nullptr) {
        cout << "La pila esta vacia.\n";
    } else {
        cout << "Libro en la cima: \"" << cima->nombreLibro << "\"\n";
    }
}

int main() {
    NodoLibro* cima = nullptr; 
    int opcion;
    string libro;

    do {
        cout << "\n=== MENU PILA DE LIBROS ===\n";
        cout << "1. Agregar libro a la pila\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Eliminar ultimo libro ingresado\n";
        cout << "4. Ver libro en la cima\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del libro: ";
                getline(cin, libro);
                pushPila(cima, libro);
                break;
            case 2:
                mostrarPila(cima);
                break;
            case 3:
                popPila(cima);
                break;
            case 4:
                verCima(cima);
                break;
            case 5:
                cout << "Saliendo del sistema de pilas...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);

    while (cima != nullptr) {
        popPila(cima);
    }

    return 0;
}