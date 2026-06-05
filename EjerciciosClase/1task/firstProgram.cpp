#include <iostream>
#include <string>

using namespace std;

int main() {
    float nota1, nota2, nota3, nota4, promedio;

    cout << "Ingrese la nota numero 1: " ;
    cin >> nota1;
    cout << "Ingrese la nota numero 2: " ;
    cin >> nota2;
    cout << "Ingrese la nota numero 3: " ;
    cin >> nota3;
    cout << "Ingrese la nota numero 4: " ;
    cin >> nota4;

    promedio = (nota1 + nota2 + nota3 + nota4) / 4;

    cout << "El promedio final del alumno es: " << promedio << endl;

    return 0;
}