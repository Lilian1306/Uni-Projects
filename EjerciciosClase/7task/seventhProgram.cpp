#include<iostream>
#include<string>

using namespace std; 

int main() {
    float horasTrabajadas, pagoPorHora, salarioTotal;

    cout << " -- Salario Total Por Horas Trabajadas --  " << endl;

    cout << "Ingrese las horas trabajadas: ";
    cin >> horasTrabajadas;

    cout << "Ingrese el pago por hora: " ;
    cin >> pagoPorHora; 

    salarioTotal = horasTrabajadas * pagoPorHora; 

    cout << "El salario total a pagar es: " << salarioTotal << endl;

    return 0;
}