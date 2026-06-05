/* Ingreso el paciente y mostrarlo en listado*/

#include<iostream>
using namespace std; 

int  main() {
    string pacientes[5]; /* Almacenar informacion no tocar vairas veces la base de datos, 0 , 1, 2*/


    for (int i = 0; i < 5 ; i++) {
        cout << "Ingrese el nombre del paciente " << i + 1 << " : ";
        cin >> pacientes[1];
    }

    cout << " --- Listado de pacientes --- ";
    for (int i = 0; i < 5; i++){
        cout << "Paciente " << i + 1 << " + " << pacientes[i] << endl;
    }

    return 0;
}