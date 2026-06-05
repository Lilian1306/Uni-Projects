#include <iostream>
#include <string>

using namespace std; 

int main() {

    float numero1, numero2; 

    cout << "  -- suma de dos numeros --  " << endl;
    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

    float suma = numero1 + numero2;
    float resta = numero1 - numero2;
    float multiplicacion = numero1 * numero2; 

    cout << "Suma: " << suma << endl;
    cout << "Resta: " << resta << endl;
    cout << "Multipplicacion: " << multiplicacion << endl;

    if(numero2 != 0) {
        float division = numero1 / numero2; 
        cout << "Division: " << division << endl;
    } else {
        cout << "Division: Error (no se puede divir entre 0) " << endl; 
    }

    return 0;
}