#include <iostream>
using namespace std;

int main() {
    int opcion;
    float n1, n2;

    do {
        cout << "\n--- MENU DE CALCULADORA ---" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 3) {
            cout << "Ingrese el primer numero: ";
            cin >> n1;
            cout << "Ingrese el segundo numero: ";
            cin >> n2;

            switch (opcion) {
                case 1: 
                    cout << ">>> Resultado de la suma: " << n1 + n2 << endl; 
                    break;
                case 2: 
                    cout << ">>> Resultado de la resta: " << n1 - n2 << endl; 
                    break;
                case 3: 
                    cout << ">>> Resultado de la multiplicacion: " << n1 * n2 << endl; 
                    break;
            }
        } else if (opcion != 4) {
            cout << "opcion no valida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);

    cout << "Saliendo del programa..." << endl;
    return 0;
}