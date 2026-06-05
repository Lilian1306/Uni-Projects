#include <iostream>
#include <string>

using namespace std;


struct NodoCliente {
    string nombreCliente;
    NodoCliente* siguiente;
};

void enqueueCola(NodoCliente*& frente, NodoCliente*& fin, string valor) {
    NodoCliente* nuevoNodo = new NodoCliente();
    nuevoNodo->nombreCliente = valor;
    nuevoNodo->siguiente = nullptr;

    if (fin == nullptr) {
        frente = fin = nuevoNodo; 
    } else {
        fin->siguiente = nuevoNodo; 
        fin = nuevoNodo;           
    }
    cout << "Cliente \"" << valor << "\" se ha formado en la fila.\n";
}


void mostrarCola(NodoCliente* frente) {
    if (frente == nullptr) {
        cout << "\nLa cola esta vacia. No hay clientes esperando.\n";
        return;
    }
    cout << "\n--- Clientes en la Cola  ---\n";
    NodoCliente* actual = frente;
    while (actual != nullptr) {
        cout << "- " << actual->nombreCliente << "\n";
        actual = actual->siguiente;
    }
    cout << "---------------------------------------------\n";
}

void dequeueCola(NodoCliente*& frente, NodoCliente*& fin) {
    if (frente == nullptr) {
        cout << "No hay clientes por atender.\n";
        return;
    }
    NodoCliente* temp = frente;
    cout << "Atendiendo al cliente: \"" << temp->nombreCliente << "\"\n";
    
    frente = frente->siguiente;
    if (frente == nullptr) {
        fin = nullptr; 
    }
    delete temp; 
}

void verPrimerCliente(NodoCliente* frente) {
    if (frente == nullptr) {
        cout << "La cola esta vacia.\n";
    } else {
        cout << "El primer cliente en la fila es: \"" << frente->nombreCliente << "\"\n";
    }
}


void mostrarCantidad(NodoCliente* frente) {
    int contador = 0;
    NodoCliente* actual = frente;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    cout << "Cantidad de clientes en espera: " << contador << "\n";
}

int main() {
    NodoCliente* frente = nullptr;
    NodoCliente* fin = nullptr;
    int opcion;
    string cliente;

    do {
        cout << "\n=== MENU ATENCION DE CLIENTES ===\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Mostrar cola\n";
        cout << "3. Atender cliente\n";
        cout << "4. Ver primer cliente\n";
        cout << "5. Mostrar cantidad de clientes\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, cliente);
                enqueueCola(frente, fin, cliente);
                break;
            case 2:
                mostrarCola(frente);
                break;
            case 3:
                dequeueCola(frente, fin);
                break;
            case 4:
                verPrimerCliente(frente);
                break;
            case 5:
                mostrarCantidad(frente);
                break;
            case 6:
                cout << "Saliendo del sistema bancario...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);


    while (frente != nullptr) {
        dequeueCola(frente, fin);
    }

    return 0;
}