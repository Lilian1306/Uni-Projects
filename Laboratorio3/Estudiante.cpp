#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    vector<string> nombres(n);
    vector<double> notas(n);

  
    for (int i = 0; i < n; i++) {
        cout << "Nombre del estudiante " << i + 1 << ": ";
        cin.ignore(); 
        getline(cin, nombres[i]);
        cout << "Nota: ";
        cin >> notas[i];
    }

    int opcion;
    do {
        cout << "\n--- MENU REGISTRO DE ESTUDIANTES ---\n";
        cout << "1. Mostrar todos los estudiantes\n";
        cout << "2. Mostrar estudiantes aprobados (>= 60)\n";
        cout << "3. Buscar estudiante por nombre e indicar posicion\n";
        cout << "4. Ordenar notas (Menor a Mayor)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n--- LISTA COMPLETA ---\n";
            for (int i = 0; i < n; i++) {
                cout << "Nombre: " << nombres[i] << " | Nota: " << notas[i] << endl;
            }
        } 
        else if (opcion == 2) {
            cout << "\n--- ESTUDIANTES APROBADOS ---\n";
            bool huboAprobados = false;
            for (int i = 0; i < n; i++) {
                if (notas[i] >= 60) {
                    cout << "- " << nombres[i] << " (" << notas[i] << ")" << endl;
                    huboAprobados = true;
                }
            }
            if (!huboAprobados) cout << "Nadie aprobo.\n";
        } 
        else if (opcion == 3) {
        
            string nombreBusca;
            cout << "Nombre del estudiante a buscar: ";
            cin.ignore();
            getline(cin, nombreBusca);
            bool encontrado = false;

            for (int i = 0; i < n; i++) {
                if (nombres[i] == nombreBusca) {
                    cout << "Estudiante: " << nombres[i] << endl;
                    cout << "Nota: " << notas[i] << endl;
                    cout << "Posicion en el arreglo: " << i << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "El estudiante no existe en el registro.\n";
        } 
        else if (opcion == 4) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (notas[j] > notas[j + 1]) { 
           
                        double tempNota = notas[j];
                        notas[j] = notas[j + 1];
                        notas[j + 1] = tempNota;

                        string tempNom = nombres[j];
                        nombres[j] = nombres[j + 1];
                        nombres[j + 1] = tempNom;
                    }
                }
            }
            cout << "Notas ordenadas de menor a mayor.\n";
        }

    } while (opcion != 5);

    return 0;
}