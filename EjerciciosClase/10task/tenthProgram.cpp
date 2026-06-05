#include<iostream>
#include<string>

using namespace std; 

int main() {
    float base, altura, area; 

    cout << "Ingrese la base del reactangulo: "; 
    cin >> base; 

    cout << "Ingrese la altura del rectangulo: "; 
    cin >> altura;

    area = base * altura; 

    cout << "El area del rectangulo es: " << area << endl;  
}