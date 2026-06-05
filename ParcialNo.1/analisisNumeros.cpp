#include <iostream>
using namespace std;

int main() {
    int num, pos = 0, neg = 0, cero = 0;

    for (int i = 0; i < 10; i++) {
        cout << "Ingrese numero " << i + 1 << ": ";
        cin >> num;
        if (num > 0) pos++;
        else if (num < 0) neg++;
        else cero++;
    }
    cout << "Positivos: " << pos << "\nNegativos: " << neg << "\nCeros: " << cero << endl;
    return 0;
}