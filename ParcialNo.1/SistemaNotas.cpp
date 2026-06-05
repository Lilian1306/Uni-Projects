#include<iostream>
using namespace std;

int main() {
    float nota, suma = 0;
    int contador = 0;

    while (true) {
        cout << "Ingrese nota: ";
        cin >> nota;

        if(nota == -1) break;

        if(nota >= 0 && nota <= 100) {
            suma += nota; 
            contador++;
            if(nota >= 60) cout << "Aprobrado" << endl; 
            else cout << "Reprobado" << endl;
        } else {
            cout << "Nota invalida." << endl;
        }
    }

    if (contador > 0) cout << "Promedio final: " << suma / contador << endl;
    return 0;
    
}