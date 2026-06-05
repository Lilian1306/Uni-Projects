#include <iostream>
#include <string>
using namespace std;

int main() {
    float nota1, nota2, nota3, nota4, nota5, nota6, nota7, nota8, promedio;

    cout << "Ingrese la primera nota: " ;
    cin >> nota1;
    cout << "Ingrese la segunda nota: " ; 
    cin >> nota2;
    cout << "Ingrese la tercera nota: " ;
    cin >> nota3;
    cout << "Ingrese la cuarta nota: " ;
    cin >> nota4;
    cout << "Ingrese la quinta nota: " ;
    cin >> nota5;
    cout << "Ingrese la sexta nota: " ; 
    cin >> nota6;
    cout << "Ingrese la septima nota: " ;
    cin >> nota7;
    cout << "Ingrese la octava nota: " ;
    cin >> nota8; 

    promedio = ( nota1 + nota2 + nota3 + nota4 + nota5 + nota6 + nota7 + nota8 ) / 8;
    if(promedio >= 61) {
        cout << "Resultado: Estudiante Gano el semestre con un promedio: " << promedio << endl;
    } else {
        cout << "Resultado: Estudiante Reprobo el semestre con un promedio: " << promedio  << endl;
    }
    return 0;
}