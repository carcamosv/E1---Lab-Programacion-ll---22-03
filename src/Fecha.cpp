#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha() {
    this->dia = 0;
    this->mes = 0;
    this->anio = 0;
}

Fecha::Fecha(int d, int m, int a) {
    this->dia = d;
    this->mes = m;
    this->anio = a;
}

void Fecha::mostrarFecha() {
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}
