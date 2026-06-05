#include <iostream>

using namespace std;

// Denficiion de estructura NODO
struct Nodo {
    int dato; 
    Nodo* siguiente;
};

//  Funcion para insertar un elemento en la cola (enqueque)
void enqueque(Nodo*& frente, Nodo*& fin, int valor) {
    Nodo* nuevo = new Nodo();
    
    nuevo->dato=valor; 
    nuevo -> siguiente = nullptr;
    
    if(fin == nullptr){
        frente = fin = nuevo;
    }else {
        fin->siguiente= nuevo; 
        fin = nuevo;
    }
    cout  <<"Elemento " << valor<<"agregado a  la cola. ";
}

// Funcion para eleminar un elemento de la cola (deque)
void deque(Nodo*& frente, Nodo*& fin) {
    if(frente == nullptr){
        cout << "La cola esta vacia.";
        return; 
    }
    Nodo* temp = frente;
    cout << "Elemento eliminado:" << temp->dato<< endl;
    
    frente  = frente-> siguiente; 
    
    if(frente == nullptr) {
        fin = nullptr;
    }
    
    delete temp;
    
}

// Funcion para mostrar la cola
void mostrar(Nodo* frente) {
    if(frente == nullptr) {
        cout << "La cola esta vacia.";
        return; 
    }
    
    cout << "Elementos de la cola ";
    
    while (frente != nullptr){
        cout << frente-> dato << "->"; 
        frente = frente->siguiente;
    }
    cout <<"NULL";
}

