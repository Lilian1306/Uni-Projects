#include <iostream>
using namespace std; 

struct Nodo {
    int dato; 
    Nodo* siguiente;
};

// Insertar

void insertar(Nodo*& cabeza, int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (cabeza == nullptr){
        cabeza = nuevo; 
    }else{
        Nodo* actual = cabeza;
        while (actual-> siguiente != nullptr){
            actual = actual -> siguiente;
        }
        actual -> siguiente = nuevo; 
    }
}

// Buscar

bool buscar (Nodo* cabeza, int valor){
    Nodo* actual = cabeza; 
    while (actual != nullptr){
        if(actual->dato == valor)
        return true;
        actual = actual -> siguiente; 
    }
    return false; 
}

// Mostrar
void mostrar(Nodo* cabeza){
    Nodo* actual = cabeza;
    cout << "Lista:";
    while(actual != nullptr){
        cout << actual-> siguiente; 
    }
    cout << "NULL" << endl; 
}

// Eliminar
bool eliminar(Nodo*& cabeza, int valor){
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;
    
    while(actual != nullptr && actual-> dato != valor){
        anterior = actual;
        actual = actual -> siguiente;
    }
    if(actual == nullptr){
        return false; // No encontrado
    }
    if(anterior == nullptr){
        cabeza = actual -> siguiente;
    }else {
        anterior-> siguiente = actual->siguiente;
    }
    delete actual; 
    return true; 

}

int main() {
    Nodo* lista = nullptr;
    int opcion, valor;


    do{
        cout << "MENU";
        cout << "1. Insertar";
        cout << "2. Mostrar";
        cout << "3. Buscar";
        cout << "4. Eliminar";
        cout << "4. Salir";
        cin >> opcion; 
        
        switch (opcion){
            case 1:
                cout << "Ingrese un numero:" ;
                cin >> valor; 
                insertar(lista, valor);
                break; 
            case 2:
                mostrar(lista);
                break; 
            case 3:
            cout << "Ingresar el dato a buscar:";
            cin >> valor; 
            if(buscar(lista, valor))
                cout << "Elemento encontrado."; 
            else 
                cout << "Elemento No encontrado.";
            break;
            
            case 4: 
                cout << "Ingrese el numero a eliminar."; 
                cin >> valor; 
                if(eliminar(lista, valor))
                    cout << "Elemento eliminado";
                else 
                    cout << "Elemento NO encontrado"; 
                break; 
            case 5: 
                cout << "Saliendo...";
                break;
            default: 
                cout << "opcion invalida"; 
        }
    }
        while (opcion!= 5);
        
        return 0;
        
    }
    
