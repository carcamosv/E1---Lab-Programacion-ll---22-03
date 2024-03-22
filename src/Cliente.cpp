#include "Cliente.h"

Cliente::Cliente(int id, string n, string a) {
    this->idCliente = id;
    this->nombre = n;
    this->apellido = a;
}

int Cliente::getIdCliente() {
    return this->idCliente;
}

string Cliente::getNombre() {
    return this->nombre;
}

string Cliente::getApellido() {
    return this->apellido;
}


/// EL RESULTADO ES ESTE.... LEES?
