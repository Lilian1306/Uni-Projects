/* Tabla de multiplicar*/

#include<iostream>

using namespace std;

int main() {
    int numero;
    int limite; 
    int contador = 1;
    
    cout << "Ingrese el numero de la tabla : "; 
    cin >> numero; 
    cout << "Ingrese el numero a multiplicar :";
    cin >> limite;

    while ( contador <= limite) 
    {
        cout << numero << " x " << contador << " = " << numero * contador << endl; 
    }
    return 0;

}