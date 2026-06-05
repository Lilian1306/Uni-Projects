#include <iostream>
using namespace std;

int main() {
    float horas, pago, total;
    cout << "Horas trabajadas: "; cin >> horas;
    cout << "Pago por hora: "; cin >> pago;

    if (horas > 40) {
        total = (40 * pago) + ((horas - 40) * (pago * 2));
    } else {
        total = horas * pago;
    }
    cout << "Salario semanal: Q" << total << endl;
    return 0;
}