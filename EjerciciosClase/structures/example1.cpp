/*
Estructuras

1. Poner Estudiante 
2. Sus atributos
3. Atritubtos de mi estructura (distintos tipos)

*/

#include <iostream>

using namespace std; 

struct empleado
{
 int codigo; 
 string nombre; 
 float salario;
};

int main() 
{
  
    empleado emp; 
    cout << "Ingrese el codigo:"; 
    cin >> emp.codigo;

    cin.ignore();
    cout << "Ingrese el nombre: " ; 
    getline(cin, emp.nombre);

    cout << "Ingrese el salario: " ; 
    cin >> emp.salario;

    cout << "/n ---- datos del empleado -----" << endl; 
    cout << "Codigo: " << emp.codigo << endl;
    cout << "Nombre: " << emp.nombre << endl;
    cout << "salario:" << emp.salario << endl;

    return 0;
}