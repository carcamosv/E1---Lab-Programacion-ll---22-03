#ifndef PAGO_H
#define PAGO_H
#include "Fecha.h"

class Pago {
private:
    Fecha* fechaPago;
    float montoPago;

public:
    Pago(Fecha* fp, float mp);
    Fecha* getFechaPago();
    float getMontoPago();
};

#endif // PAGO_H
