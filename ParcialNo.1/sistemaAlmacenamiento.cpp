#include <iostream>
using namespace std;

int main() {
    int tipo, GB;
    cout << "Tipo (1. HDD, 2. SSD, 3. USB): "; cin >> tipo;
    cout << "Capacidad en GB: "; cin >> GB;

    switch (tipo) {
        case 1: cout << "Tipo: HDD" << endl; break;
        case 2: cout << "Tipo: SSD" << endl; break;
        case 3: cout << "Tipo: USB" << endl; break;
    }

    if (GB < 256) cout << "Capacidad: Baja" << endl;
    else if (GB <= 1000) cout << "Capacidad: Media" << endl;
    else cout << "Capacidad: Alta" << endl;

    return 0;
}