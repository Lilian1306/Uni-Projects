#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "Fecha.h"

using namespace std;

class Consulta {
private:
    int idConsulta;
    string tipoServicio;
    double costo;
    Fecha fechaConsulta;
    string diagnostico;

public:
    Consulta();
    void establecerDatos(int id, string tipo, double cost, Fecha f, string diag);
    double obtenerCosto() const;
    string obtenerTipoServicio() const;
    int obtenerId() const;
    Fecha obtenerFecha() const;
    string obtenerDiagnostico() const;
};

#endif