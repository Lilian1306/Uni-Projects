#include <iostream>
#include "Mascota.h"

Mascota::Mascota() : idMascota(0), nombre(""), especie(""), edad(0), cantidadConsultas(0) {}

void Mascota::inicializar(int id, string nom, string esp, int ed) {
    idMascota = id;
    nombre = nom;
    especie = esp;
    edad = ed;
    cantidadConsultas = 0;
}

int Mascota::obtenerId() const { return idMascota; }
string Mascota::obtenerNombre() const { return nombre; }
string Mascota::obtenerEspecie() const { return especie; }
int Mascota::obtenerEdad() const { return edad; }
int Mascota::obtenerCantidadConsultas() const { return cantidadConsultas; }
Consulta Mascota::obtenerConsulta(int index) const { return historial[index]; }

void Mascota::agregarConsulta(Consulta nuevaConsulta) {
    if (cantidadConsultas < 50) {
        historial[cantidadConsultas] = nuevaConsulta;
        cantidadConsultas++;
    } else {
        cout << "Historial medico lleno para esta mascota.\n";
    }
}