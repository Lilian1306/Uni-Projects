#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;

    vector<string> nombres(n);
    vector<double> salarios(n);

    for (int i = 0; i < n; i++) {
        cout << "Nombre del empleado " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, nombres[i]);
        cout << "Salario: ";
        cin >> salarios[i];
    }

    int opcion;
    do {
        cout << "\n--- MENU SISTEMA DE EMPLEADOS ---\n";
        cout << "1. Mostrar todos los empleados\n";
        cout << "2. Buscar empleado por nombre\n";
        cout << "3. Ordenar por salario (Mayor a Menor)\n";
        cout << "4. Indicar el salario mas alto\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n--- LISTA DE EMPLEADOS ---\n";
            for (int i = 0; i < n; i++) {
                cout << i + 1 << ". " << nombres[i] << " - Q" << salarios[i] << endl;
            }
        } 
        else if (opcion == 2) {
            string nombreBusca;
            cout << "Ingrese el nombre a buscar: ";
            cin.ignore();
            getline(cin, nombreBusca);
            bool encontrado = false;

            for (int i = 0; i < n; i++) {
                if (nombres[i] == nombreBusca) {
                    cout << "Empleado encontrado: " << nombres[i] << " | Salario: Q" << salarios[i] << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "No se encontro el empleado.\n";
        } 
        else if (opcion == 3) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (salarios[j] < salarios[j + 1]) { 
                   
                        double tempSal = salarios[j];
                        salarios[j] = salarios[j + 1];
                        salarios[j + 1] = tempSal;

                        string tempNom = nombres[j];
                        nombres[j] = nombres[j + 1];
                        nombres[j + 1] = tempNom;
                    }
                }
            }
            cout << "Empleados ordenados por salario (Mayor a Menor).\n";
        } 
        else if (opcion == 4) {
            double mayor = salarios[0];
            string nombreMayor = nombres[0];

            for (int i = 1; i < n; i++) {
                if (salarios[i] > mayor) {
                    mayor = salarios[i];
                    nombreMayor = nombres[i];
                }
            }
            cout << "El salario mas alto es de " << nombreMayor << " con  Q" << mayor << endl;
        }

    } while (opcion != 5);

    return 0;
}