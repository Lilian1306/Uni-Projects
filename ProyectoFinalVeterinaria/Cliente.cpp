#include "Cliente.h"

Cliente::Cliente(/*int id*/ string nom, string tel, Mascota masc) {
    //idCliente = id;
    nombreDueño = nom;
    telefono = tel;
    mascotaRegistrada = masc;
    siguiente = nullptr;
}

//int Cliente::obtenerId() const { return idCliente; }
string Cliente::obtenerNombre() const { return nombreDueño; }
string Cliente::obtenerTelefono() const { return telefono; }
Mascota& Cliente::obtenerMascota() { return mascotaRegistrada; }