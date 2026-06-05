#include "Consulta.h"

Consulta::Consulta() : idConsulta(0), tipoServicio(""), costo(0.0), diagnostico("") {
    fechaConsulta.dia = 1; fechaConsulta.mes = 1; fechaConsulta.año = 2026;
}

void Consulta::establecerDatos(int id, string tipo, double cost, Fecha f, string diag) {
    idConsulta = id;
    tipoServicio = tipo;
    costo = cost;
    fechaConsulta = f;
    diagnostico = diag;
}

double Consulta::obtenerCosto() const { return costo; }
string Consulta::obtenerTipoServicio() const { return tipoServicio; }
int Consulta::obtenerId() const { return idConsulta; }
Fecha Consulta::obtenerFecha() const { return fechaConsulta; }
string Consulta::obtenerDiagnostico() const { return diagnostico; }