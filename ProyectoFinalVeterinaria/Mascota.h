#ifndef MASCOTA_H
#define MASCOTA_H

#include <string>
#include "Consulta.h"

using namespace std;

class Mascota {
private:
    int idMascota;
    string nombre;
    string especie;
    int edad;
    Consulta historial[50];
    int cantidadConsultas;

public:
    Mascota();
    void inicializar(int id, string nom, string esp, int ed);
    int obtenerId() const;
    string obtenerNombre() const;
    string obtenerEspecie() const;
    int obtenerEdad() const;
    int obtenerCantidadConsultas() const;
    Consulta obtenerConsulta(int index) const;
    void agregarConsulta(Consulta nuevaConsulta);
};

#endif