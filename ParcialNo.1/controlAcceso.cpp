#include <iostream>
using namespace std;

int main() {
    string usuario, pass;
    string correcto = "admin", exacto = "1234";
    int intentos = 0;

    while (intentos < 3) {
        cout << "Usuario: "; cin >> usuario;
        cout << "Contrasena: "; cin >> pass;

        if (usuario == correcto && pass == exacto) {
            cout << "Acceso permitido." << endl;
            return 0;
        } else {
            intentos++;
            cout << "Incorrecto. Intentos restantes: " << 3 - intentos << endl;
        }
    }
    cout << "Acceso bloqueado." << endl;
    return 0;
}