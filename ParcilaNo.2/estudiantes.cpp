#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Estudiante {
    string codigo;
    string nombre;
    float nota1, nota2, nota3;
    float promedio;
    string estado;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    vector<Estudiante> listaEstudiantes(n);
    float sumaPromediosClase = 0;
    int aprobados = 0, reprobados = 0;


    for (int i = 0; i < n; i++) {
        cout << "\n--- Estudiante " << i + 1 << " ---\n";
        cout << "Codigo: ";
        cin >> listaEstudiantes[i].codigo;
        cin.ignore(); 
        cout << "Nombre: ";
        getline(cin, listaEstudiantes[i].nombre);
        cout << "Nota 1: "; cin >> listaEstudiantes[i].nota1;
        cout << "Nota 2: "; cin >> listaEstudiantes[i].nota2;
        cout << "Nota 3: "; cin >> listaEstudiantes[i].nota3;


        listaEstudiantes[i].promedio = (listaEstudiantes[i].nota1 + listaEstudiantes[i].nota2 + listaEstudiantes[i].nota3) / 3;
        
        if (listaEstudiantes[i].promedio >= 61) {
            listaEstudiantes[i].estado = "Aprobado";
            aprobados++;
        } else {
            listaEstudiantes[i].estado = "Reprobado";
            reprobados++;
        }

        sumaPromediosClase += listaEstudiantes[i].promedio;
    }


    Estudiante mayor = listaEstudiantes[0];
    Estudiante menor = listaEstudiantes[0];

    for (int i = 1; i < n; i++) {
        if (listaEstudiantes[i].promedio > mayor.promedio) mayor = listaEstudiantes[i];
        if (listaEstudiantes[i].promedio < menor.promedio) menor = listaEstudiantes[i];
    }

   
    cout << "\n================ REPORTES ================" << endl;
    cout << "Promedio general de la clase: " << (sumaPromediosClase / n) << endl;
    cout << "Cantidad de aprobados: " << aprobados << endl;
    cout << "Cantidad de reprobados: " << reprobados << endl;
    cout << "Estudiante con mayor promedio: " << mayor.nombre << " (" << mayor.promedio << ")" << endl;
    cout << "Estudiante con menor promedio: " << menor.nombre << " (" << menor.promedio << ")" << endl;

    cout << "\nLISTADO COMPLETO:" << endl;
    cout << "Cod\tNombre\t\tProm\tEstado" << endl;
    for (const auto& est : listaEstudiantes) {
        cout << est.codigo << "\t" << est.nombre << "\t" << est.promedio << "\t" << est.estado << endl;
    }

    return 0;
}