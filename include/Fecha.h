#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha();
    Fecha(int d, int m, int a);
    void mostrarFecha();
};

#endif // FECHA_H
