/*
1. archivos
2. txt
3. guardar
4. actualizar
5. eliminar
6. visualizar
*/

#include <iostream>
#include <fstream>

using namespace std; 

int main() 
{

    ofstream archivo;
    string nombre; 
    int edad; 
    int salario; 

    archivo.open("estudiante.txt", ios::app);

    cout << "Ingrese el nombre: " ;
    cin >> nombre;

    cout << "ingrese la edad: " ;
    cin >> edad; 

    cout << "Ingrese el salario: " ;
    cin >> salario; 

    archivo << nombre << " "  << edad << " " << salario <<  endl;

    archivo.close();

    cout << "Datos guardados de forma correcta" << endl;

    return 0;
}