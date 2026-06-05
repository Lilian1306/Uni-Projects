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

const string NOMBRE_ARCHIVO = "datos.txt"
// Visualizar

void visualizar() {
    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    int lineaNum=1;

    // Visualizar el archivo

    while (getline(archivo,linea)) {

        cout << lineaNum++ << " , " << linea << endl;

    }

    archivo.close();
   
};



int main() 
{
    int opcion; 
    
    do {

        cout << " **** GESTION DE ARCHIVOS ****"; 
        cout << "1.visualizar datos: ";
        cout << "2.Agregar datod :";
        cout << "3.eliminar datos:";
        cout << "4.actualizar datos: "; 
        cout << "5.salir: "; 
        cout << "Seleccione una opcion: "; 
        cin >> opcion;

        switch (opcion){
            case 1:
            visualizar();
            break;

            case 2:
            escribirDatos();
            break; 

            case 3:
            eliminarDatos();
            break;

            case 4:
            updateDatos();
            break;

            case 5:
            cout << "Saliendo del programa: ";
            break;
            default:
            cout << "Opcion no es valida: ";
        }

    }while (opcion !=5);


    return 0;
}