#include <iostream>
#include <fstream> 
#include <string>

using namespace std; 

const int MAX_EMPLEADOS = 100;

class Empleado {
private:
    string nombre;
    string puesto;
    double salario;

public:
    Empleado() {
        nombre = "";
        puesto = "";
        salario = 0.0;
    }

    Empleado(string _nombre, string _puesto, double _salario) {
        nombre = _nombre;
        puesto = _puesto;
        salario = _salario;
    }

    string getNombre() { return nombre; }
    string getPuesto() { return puesto; }
    double getSalario() { return salario; }

    void mostrarEmpleado() {
        cout << "Nombre: " << nombre 
             << " | Puesto: " << puesto 
             << " | Salario: Q" << salario << endl;
    }
};


void guardarEnArchivo(Empleado emp) {
    ofstream archivo;
    archivo.open("empleados.txt", ios::app); 
    
    if (archivo.is_open()) {
        // Se guarda sin el campo ID
        archivo << emp.getNombre() << "," 
                << emp.getPuesto() << "," 
                << emp.getSalario() << "\n";
        archivo.close(); 
    } else {
        cout << "[Error] No se pudo abrir el archivo para guardar.\n";
    }
}

int cargarDesdeArchivo(Empleado lista[]) {
    ifstream archivo;
    archivo.open("empleados.txt");
    
    if (!archivo.is_open()) {
        return 0;
    }

    string nombre, puesto, salStr;
    int contador = 0;

    while (contador < MAX_EMPLEADOS && 
           getline(archivo, nombre, ',') &&
           getline(archivo, puesto, ',') &&
           getline(archivo, salStr)) {
   
        double salario = stod(salStr);
        
        lista[contador] = Empleado(nombre, puesto, salario);
        contador++;
    }

    archivo.close();
    return contador; 
}

void ordenarPorSalario(Empleado lista[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (lista[j].getSalario() < lista[j + 1].getSalario()) {
                Empleado temporal = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temporal;
            }
        }
    }
}


int main() {
    Empleado listaEmpleados[MAX_EMPLEADOS];
    int opcion;

    do {
        cout << "\n=========================================" << endl;
        cout << "     SISTEMA DE EMPLEADOS " << endl;
        cout << "=========================================" << endl;
        cout << "1. Registrar Empleado\n";
        cout << "2. Mostrar Todos los Empleados\n";
        cout << "3. Buscar Empleado por Nombre\n";
        cout << "4. Ordenar por Salario (Mayor a Menor)\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1: { 
                string nombre, puesto;
                double salario;

                cout << "\n--- Registrar Empleado ---\n";
                cout << "Ingrese Nombre: "; getline(cin, nombre);
                cout << "Ingrese Puesto: "; getline(cin, puesto);
                cout << "Ingrese Salario: "; cin >> salario;

                Empleado nuevo(nombre, puesto, salario);
                guardarEnArchivo(nuevo); 
                cout << "\n[!] Empleado guardado exitosamente.\n";
                break;
            }
            case 2: { 
                cout << "\n--- Lista de Empleados Registrados ---\n";
                int total = cargarDesdeArchivo(listaEmpleados);

                if (total == 0) {
                    cout << "No hay registros disponibles.\n";
                } else {
                    for (int i = 0; i < total; i++) {
                        listaEmpleados[i].mostrarEmpleado();
                    }
                }
                break;
            }
            case 3: {
                cout << "\n--- Buscar Empleado ---\n";
                string criterio;
                cout << "Ingrese Nombre a buscar: ";
                getline(cin, criterio);

                int total = cargarDesdeArchivo(listaEmpleados);
                bool encontrado = false;

                for (int i = 0; i < total; i++) {
                    if (listaEmpleados[i].getNombre() == criterio) {
                        cout << "\n[Registro Encontrado]:\n";
                        listaEmpleados[i].mostrarEmpleado();
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "\n[x] No se encontraron coincidencias para: " << criterio << "\n";
                }
                break;
            }
            case 4: {
                cout << "\n--- Empleados Ordenados por Salario ---\n";
                int total = cargarDesdeArchivo(listaEmpleados);

                if (total == 0) {
                    cout << "No hay datos para ordenar.\n";
                } else {
                    ordenarPorSalario(listaEmpleados, total); 
                    
                    for (int i = 0; i < total; i++) {
                        listaEmpleados[i].mostrarEmpleado(); 
                    }
                }
                break;
            }
            case 5:
                cout << "\nSaliendo del sistema... \n";
                break;
            default:
                cout << "\n[Error] Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 5);

    return 0;
}