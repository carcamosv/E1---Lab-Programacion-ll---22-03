#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;
class Cliente {
private:
    int idCliente;
    string nombre;
    string apellido;

public:
    Cliente(int id, string n, string a);
    int getIdCliente();
    string getNombre();
    string getApellido();
};

#endif // CLIENTE_H
