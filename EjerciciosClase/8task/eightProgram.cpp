#include <iostream>
#include <string>

using namespace std;

int main() {
    float precio;   
    int cantidad;    
    float total;

    cout << " --- Sistema de Ventas (Total de Compra) --- " << endl;

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    cout << "Ingrese la cantidad de unidades compradas: ";
    cin >> cantidad;

    total = precio * cantidad;

    cout << "------------------------------------------" << endl;
    cout << "El total a pagar por su compra es: " << total << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}