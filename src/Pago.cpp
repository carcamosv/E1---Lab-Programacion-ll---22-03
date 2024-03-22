#include "Pago.h"
#include "Pago.h"

Pago::Pago(Fecha* fp, float mp) {
    this->fechaPago = fp;
    this->montoPago = mp;
}

Fecha* Pago::getFechaPago() {
    return this->fechaPago;
}

float Pago::getMontoPago() {
    return this->montoPago;
}
