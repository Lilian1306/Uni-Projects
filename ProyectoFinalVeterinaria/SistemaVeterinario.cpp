#include <iostream>
#include "SistemaVeterinario.h"

using namespace std;


SistemaVeterinaria::SistemaVeterinaria() {
    cabeza = nullptr;
}

SistemaVeterinaria::~SistemaVeterinaria() {
    Cliente* actual = cabeza;
    while (actual != nullptr) {
        Cliente* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}


void SistemaVeterinaria::registrarCliente(/*int id,*/ string nom, string tel, Mascota masc) {
    Cliente* nuevoCliente = new Cliente(/*id,*/ nom, tel, masc);
    if (cabeza == nullptr) {
        cabeza = nuevoCliente;
    } else {
        Cliente* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoCliente;
    }
}


Cliente* SistemaVeterinaria::buscarClientePorMascotaId(int idMascota) {
    Cliente* actual = cabeza;
    while (actual != nullptr) {
        if (actual->obtenerMascota().obtenerId() == idMascota) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}


void SistemaVeterinaria::registrarConsultaMedica() {
    int idMasc, idCons;
    string tipo;
    double costo = 0.0;
    Fecha f;
    string diag;

    cout << "\n--- REGISTRAR CONSULTA MEDICA ---\n";
    cout << "Ingrese el ID de la Mascota: ";
    while (!(cin >> idMasc)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese un ID numerico: ";
    }

    Cliente* cliente = buscarClientePorMascotaId(idMasc);

    if (cliente == nullptr) {
        cout << "Error: No se encontro ninguna mascota con ese ID.\n";
        return;
    }

    cout << "Mascota localizada: " << cliente->obtenerMascota().obtenerNombre() << " (Dueno: " << cliente->obtenerNombre() << ")\n";
    cout << "Ingrese ID de la Consulta: ";
    while (!(cin >> idCons)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese un ID numerico: ";
    }
    cout << "Seleccione Tipo de Servicio (1: Consulta, 2: Vacunacion, 3: Cirugia): ";
    int opcionServicio;
    while (!(cin >> opcionServicio)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Seleccione una opcion numerica (1, 2 o 3): ";
    }

    switch(opcionServicio) {
        case 1: tipo = "Consulta"; costo = 100.0; break;
        case 2: tipo = "Vacunacion"; costo = 75.0; break;
        case 3: tipo = "Cirugia"; costo = 500.0; break;
        default: tipo = "General"; costo = 100.0; break;
    }

    cout << "Ingrese Dia, Mes y Anio (separados por espacios): ";
    while (!(cin >> f.dia >> f.mes >> f.año)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese Dia, Mes y Anio numericos (separados por espacios): ";
    }
    cin.ignore(10000, '\n');
    cout << "Ingrese el Diagnostico: ";
    getline(cin, diag);

    Consulta nuevaConsulta;
    nuevaConsulta.establecerDatos(idCons, tipo, costo, f, diag);
    cliente->obtenerMascota().agregarConsulta(nuevaConsulta);

    cout << "Consulta registrada exitosamente! Costo aplicado: Q" << costo << "\n";
}


void SistemaVeterinaria::mostrarHistorialMascota() {
    int idMasc;
    cout << "\n--- CONSULTAR HISTORIAL MEDICO ---\n";
    cout << "Ingrese el ID de la Mascota: ";
    while (!(cin >> idMasc)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Entrada invalida. Ingrese un ID numerico: ";
    }

    Cliente* cliente = buscarClientePorMascotaId(idMasc);
    if (cliente == nullptr) {
        cout << "Mascota no encontrada.\n";
        return;
    }

    Mascota masc = cliente->obtenerMascota();
    cout << "\n==================================================\n";
    cout << "HISTORIAL MEDICO DE: " << masc.obtenerNombre() << " (" << masc.obtenerEspecie() << ")\n";
    cout << "==================================================\n";

    if (masc.obtenerCantidadConsultas() == 0) {
        cout << "No hay registros medicos previos.\n";
        return;
    }

    for (int i = 0; i < masc.obtenerCantidadConsultas(); i++) {
        Consulta c = masc.obtenerConsulta(i);
        cout << "Fecha: " << c.obtenerFecha().dia << "/" << c.obtenerFecha().mes << "/" << c.obtenerFecha().año << "\n"
             << "ID Consulta: " << c.obtenerId() << " | Servicio: " << c.obtenerTipoServicio() << "\n"
             << "Diagnostico: " << c.obtenerDiagnostico() << "\n"
             << "Costo: Q" << c.obtenerCosto() << "\n"
             << "--------------------------------------------------\n";
    }
}

void SistemaVeterinaria::generarReporteIngresos() {
    double totalIngresos = 0.0;
    int totalAtenciones = 0;

    Cliente* actual = cabeza;
    while (actual != nullptr) {
        Mascota masc = actual->obtenerMascota();
        for (int i = 0; i < masc.obtenerCantidadConsultas(); i++) {
            totalIngresos += masc.obtenerConsulta(i).obtenerCosto();
            totalAtenciones++;
        }
        actual = actual->siguiente;
    }

    cout << "\n==================================================\n"
         << " Total de consultas atendidas: " << totalAtenciones << "\n"
         << " Total de ingresos economicos: Q" << totalIngresos << "\n"
         << "==================================================\n";
}

void SistemaVeterinaria::listadoMascotasOrdenado() {
    if (cabeza == nullptr) {
        cout << "No hay mascotas registradas.\n";
        return;
    }

    int contador = 0;
    Cliente* temp = cabeza;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }

    Mascota* listaMascotas = new Mascota[contador];
    temp = cabeza;
    for (int i = 0; i < contador; i++) {
        listaMascotas[i] = temp->obtenerMascota();
        temp = temp->siguiente;
    }

    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (listaMascotas[j].obtenerNombre() > listaMascotas[j + 1].obtenerNombre()) {
                Mascota auxiliar = listaMascotas[j];
                listaMascotas[j] = listaMascotas[j + 1];
                listaMascotas[j + 1] = auxiliar;
            }
        }
    }

    cout << "\n--- MASCOTAS REGISTRADAS (ORDEN ALFABETICO) ---\n";
    for (int i = 0; i < contador; i++) {
        cout << "ID: " << listaMascotas[i].obtenerId() << " | Nombre: " << listaMascotas[i].obtenerNombre() << " | Raza: " << listaMascotas[i].obtenerEspecie() << "\n";
    }
    delete[] listaMascotas;
}