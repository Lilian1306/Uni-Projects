#include<iostream>
#include<string>

using namespace std; 

int main() {
    float primerNumeroDecimal, segundoNumeroDecimal, promedio;

    cout << " -- Promedio de numeros decimales -- " << endl; 

    cout << "Ingrese el primer numero decimal: ";
    cin >> primerNumeroDecimal;
    cout << "Ingrese el segundo numero decimal: ";
    cin >> segundoNumeroDecimal; 

    promedio = (primerNumeroDecimal + segundoNumeroDecimal ) / 2;

    cout << "El promedio de los numeros decimales es: " << promedio << endl;

    return 0;
}