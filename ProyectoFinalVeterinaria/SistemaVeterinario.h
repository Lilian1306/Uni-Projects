#ifndef SISTEMAVETERINARIA_H
#define SISTEMAVETERINARIA_H

#include "Cliente.h"

class SistemaVeterinaria {
private:
    Cliente* cabeza;

public:
    SistemaVeterinaria();
    ~SistemaVeterinaria();

    void registrarCliente(/*int id,*/ string nom, string tel, Mascota masc);
    Cliente* buscarClientePorMascotaId(int idMascota);
    void registrarConsultaMedica();
    void mostrarHistorialMascota();
    void generarReporteIngresos();
    void listadoMascotasOrdenado();
    

};

#endif