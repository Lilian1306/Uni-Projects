#include <iostream>
#include "SistemaVeterinario.h"

using namespace std;

int main() {
    SistemaVeterinaria clinica;

    int opcion = 0;

    while (opcion != 6) {
        cout << "\n============================================\n";
        cout << "       SISTEMA DE CLINICA VETERINARIA       \n";
        cout << "============================================\n";
        cout << "1. Registrar Nuevo Cliente y Mascota\n";
        cout << "2. Registrar Consulta Medica\n";
        cout << "3. Consultar Historial Medico\n";
        cout << "4. Reporte General de Ingresos\n";
        cout << "5. Listar Mascotas (Orden Alfabetico)\n";
        cout << "6. Salir y Guardar Cambios\n";
        cout << "============================================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Entrada invalida. Por favor, ingrese un numero.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                int /*idC,*/ idM, edadM;
                string nomC, telC, nomM, espM;
                //cout << "\nID Cliente: "; cin >> idC;
                cin.ignore();
                cout << "Nombre del Dueno de la Mascota: "; getline(cin, nomC);
                cout << "Telefono: "; getline(cin, telC);
                cout << "ID Mascota: "; 
                while (!(cin >> idM)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Entrada invalida. Ingrese un ID numerico para la mascota: ";
                }
                cin.ignore(10000, '\n'); // Limpia el buffer para que el siguiente getline funcione bien
                cout << "Nombre Mascota: "; getline(cin, nomM);
                cout << "Raza: "; getline(cin, espM);
                cout << "Edad: "; 
                while (!(cin >> edadM)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Entrada invalida. Ingrese una edad numerica: ";
                }

                Mascota nuevaMascota;
                nuevaMascota.inicializar(idM, nomM, espM, edadM);
                clinica.registrarCliente(/*idC,*/ nomC, telC, nuevaMascota);
                break;
            }
            case 2: clinica.registrarConsultaMedica(); break;
            case 3: clinica.mostrarHistorialMascota(); break;
            case 4: clinica.generarReporteIngresos(); break;
            case 5: clinica.listadoMascotasOrdenado(); break;
            default: cout << "Opcion invalida.\n"; break;
        }
    }
    return 0;
}