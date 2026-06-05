#include <iostream>
using namespace std;

int main() {
    int edad, n = 0, j = 0, a = 0, m = 0;

    while (true) {
        cout << "Ingrese edad (ingrese 0 para salir del programa): ";
        cin >> edad;
        if (edad <= 0) break;

        if (edad < 13) { cout << "Nino\n"; n++; }
        else if (edad < 18) { cout << "Joven\n"; j++; }
        else if (edad < 60) { cout << "Adulto\n"; a++; }
        else { cout << "Adulto Mayor\n"; m++; }
    }
    cout << "Ninos: " << n << ", Jovenes: " << j << ", Adultos: " << a << ", Mayores: " << m << endl;
    return 0;
}