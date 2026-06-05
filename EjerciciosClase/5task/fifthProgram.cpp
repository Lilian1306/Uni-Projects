#include<iostream>
#include<string>

using namespace std;

int main() {
    float salarioMensual, salarioAnual;

    cout << " -- Calculando el salario anual -- " << endl;
    
    cout << "Ingrese el salario mensual del empleado: ";
    cin >> salarioMensual;

    salarioAnual = salarioMensual * 12;

    cout << "El salario anual del empleado es de: " << salarioAnual << endl;

    return 0;
}
