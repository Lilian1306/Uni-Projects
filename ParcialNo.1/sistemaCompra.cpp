#include <iostream>
using namespace std;

int main() {
    float precio, total = 0;

    while (true) {
        cout << "Precio del producto (0 para finalizar): "; cin >> precio;
        if (precio == 0) break;
        total += precio;
    }

    if (total > 100) {
        cout << "Descuento aplicado del 10%." << endl;
        total *= 0.90;
    }
    cout << "Total a pagar: Q" << total << endl;
    return 0;
}