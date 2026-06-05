#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Empleado {
    string codigo;
    string nombre;
    string departamento;
    double salarioBase;
    int horasExtra;
    double pagoHorasExtra;
    double salarioTotal;
};

int main() {
    int n;
    const double PRECIO_HORA_EXTRA = 50.0;
    
    cout << "Ingrese la cantidad de empleados: ";
    cin >> n;

    vector<Empleado> planilla(n);
    double sumaSalariosTotales = 0;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Datos del empleado " << i + 1 << " ---" << endl;
        cout << "Codigo: "; cin >> planilla[i].codigo;
        cin.ignore(); 
        cout << "Nombre: "; getline(cin, planilla[i].nombre);
        cout << "Departamento: "; getline(cin, planilla[i].departamento);
        cout << "Salario Base: "; cin >> planilla[i].salarioBase;
        cout << "Horas extra trabajadas: "; cin >> planilla[i].horasExtra;

        planilla[i].pagoHorasExtra = planilla[i].horasExtra * PRECIO_HORA_EXTRA;
        planilla[i].salarioTotal = planilla[i].salarioBase + planilla[i].pagoHorasExtra;
        
        sumaSalariosTotales += planilla[i].salarioTotal;
    }


    double promedio = sumaSalariosTotales / n;
    Empleado *mayor = &planilla[0];
    Empleado *menor = &planilla[0];
    int arribaPromedio = 0;

    for (int i = 0; i < n; i++) {
        if (planilla[i].salarioTotal > mayor->salarioTotal) mayor = &planilla[i];
        if (planilla[i].salarioTotal < menor->salarioTotal) menor = &planilla[i];
        if (planilla[i].salarioTotal > promedio) arribaPromedio++;
    }

    cout << fixed << setprecision(2);
    cout << "\n==========================================" << endl;
    cout << "          REPORTE DE NOMINA" << endl;
    cout << "==========================================" << endl;
    
    for (const auto& e : planilla) {
        cout << "ID: " << e.codigo << " | Nombre: " << e.nombre 
             << " | Salario Total: Q" << e.salarioTotal << endl;
    }

    cout << "\n--- Resumen General ---" << endl;
    cout << "Total de la nomina: Q" << sumaSalariosTotales << endl;
    cout << "Promedio general: Q" << promedio << endl;
    cout << "Mayor salario: " << mayor->nombre << " (Q" << mayor->salarioTotal << ")" << endl;
    cout << "Menor salario: " << menor->nombre << " (Q" << menor->salarioTotal << ")" << endl;
    cout << "Empleados arriba del promedio: " << arribaPromedio << endl;

    return 0;
}