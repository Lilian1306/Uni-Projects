/* Menus en c++*/

#include<iostream>
using namespace std; 

int main() {
    int opcion; 

    do {
        cout << " --- Menu Principal Banrural" << endl; 
        cout << "1. Cuenta monetarioa" << endl; 
        cout << "2. Cuentas ahorro" << endl; 
        cout << "3. Cuentas plazo fijo" << endl;
        cout << "4. salir" << endl;
        cin >> opcion; 

        // Controlar el flujo del menu
        switch (opcion) {
            case 1: 
              cout << "1. Cuenta monetarioa" << endl; 
            case 2: 
               cout << "2. Cuentas ahorro" << endl;     
            case 3: 
                cout << "3. Cuentas plazo fijo" << endl;
        }
    } while (opcion != 4);

    return 0;
}