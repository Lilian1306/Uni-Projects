#include <iostream>
using namespace std;

int main() {
    float nota, suma = 0,  mayor = -1,  menor = 101;

    for (int i = 0; i < 5; i++) {
        cout << "Nota " << i + 1 << ": "; cin >> nota;
        suma += nota;
        if (nota > mayor) mayor = nota;
        if (nota < menor) menor = nota;
    }
    cout << "Promedio: " << suma / 5 << "\nNota Mayor: " << mayor << "\nNota Menor: " << menor << endl;
    return 0;
}