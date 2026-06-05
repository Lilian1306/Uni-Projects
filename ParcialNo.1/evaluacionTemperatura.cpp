#include <iostream>
using namespace std;

int main() {
    float temp, alta = -100, baja = 100;
    bool extremos = false;

    for (int i = 1; i <= 7; i++) {
        cout << "Temp dia " << i << ": "; cin >> temp;
        if (temp > alta) alta = temp;
        if (temp < baja) baja = temp;
        if (temp > 35 || temp < 10) extremos = true;
    }
    cout << "Mas alta: " << alta << "\nMas baja: " << baja << endl;
    if (extremos) cout << "Hubo dias con temperaturas extremas." << endl;
    return 0;
}