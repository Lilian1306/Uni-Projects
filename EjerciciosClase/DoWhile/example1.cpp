/*vemos como es el cliclo do while*/

#include<iostream>

using namespace std;

int main() {
    int numero;
do { // por lo  menos ingrese 1 vez a nustro ciclo
    cout << "Ingrese el numero :";
    cin >> numero; 

} while (numero <=0 ); // verifica la condicion si se esta cumpliendo, se repite de caso contrario finaliza. es mas utilizado para menus, verificar ingreso de sistemas. 

 return 0;
}
