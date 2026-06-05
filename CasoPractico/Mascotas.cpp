#include <iostream>
#include <string>

using namespace std;

class Mascota {
private:
    string nombre;
    string tipoAnimal;
    int edad;
    string nombreDueno;

public:
   
    Mascota(string _nombre, string _tipoAnimal, int _edad, string _nombreDueno) {
        nombre = _nombre;
        tipoAnimal = _tipoAnimal;
        edad = _edad;
        nombreDueno = _nombreDueno;
    }

    string getNombre() { return nombre; }
    string getTipoAnimal() { return tipoAnimal; }
    int getEdad() { return edad; }
    string getNombreDueno() { return nombreDueno; }

    string clasificarEdad() {
        if (edad <= 2) {
            return "Joven";
        } else {
            return "Adulta";
        }
    }

   
    void mostrarInformacion() {
        cout << "\n===================================" << endl;
        cout << "     INFORMACION DE LA MASCOTA     " << endl;
        cout << "===================================" << endl;
        cout << "Nombre de la Mascota: " << nombre << endl;
        cout << "Tipo de Animal:       " << tipoAnimal << endl;
        cout << "Edad:                 " << edad << " anos" << endl;
        cout << "Clasificacion:        " << clasificarEdad() << endl;
        cout << "Nombre del Dueno:     " << nombreDueno << endl;
        cout << "===================================" << endl;
    }
};

int main() {
    string nom, tipo, dueno;
    int ed;

    cout << "--- Registro de Mascotas (Veterinaria) ---\n" << endl;
    
    cout << "Ingrese el nombre de la mascota: ";
    getline(cin, nom);
    
    cout << "Ingrese el tipo de animal (ej. Perro, Gato): ";
    getline(cin, tipo);
    
    cout << "Ingrese la edad de la mascota: ";
    cin >> ed;
    cin.ignore(); 
    
    cout << "Ingrese el nombre del dueno: ";
    getline(cin, dueno);

    Mascota mascota1(nom, tipo, ed, dueno);


    mascota1.mostrarInformacion();

    return 0;
}