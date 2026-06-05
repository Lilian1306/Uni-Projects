#include<iostream>
#include<string>

using namespace std; 

int main () {
    string nombre; 
    float  nota1, nota2, nota3, promedio; 

    cout << "Ingrese el nombre del estudiante: " ; 
    getline(cin, nombre); 

    cout << "Ingrese la nota 1: ";
    cin >> nota1; 

    cout << "Ingrese la nota 2: ";
    cin >> nota2; 

    cout << "Ingrese la nota 3: ";
    cin >> nota3;

    promedio = (nota1 + nota2 + nota3) / 3;

    cout << "Estudiante: " << nombre << endl; 
    cout << "Promedio final: " << promedio << endl; 

    return 0;
}