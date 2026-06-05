#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include "Mascota.h"

using namespace std;

class Cliente {
private:
    //int idCliente;
    string nombreDueño;
    string telefono;
    Mascota mascotaRegistrada;

public:
    Cliente* siguiente;

    Cliente(/*int id*/ string nom, string tel, Mascota masc);
    //int obtenerId() const;
    string obtenerNombre() const;
    string obtenerTelefono() const;
    Mascota& obtenerMascota();
};

#endif