#include <iostream>
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#include "Fecha.h"
#include "Pago.h"
#define TML 5

using namespace std;

int menu(){
    int op;
    cout<< "MENU DE OPCIONES"<<endl;
    cout<< "1. AGREGAR CLIENTE A LA LISTA."<<endl;
    cout<< "2. AGREGAR PRESTAMO A LA LISTA."<<endl;
    cout<< "3. HACER PAGOS DE PRESTAMOS."<<endl;
    cout<< "4. MOSTRAR LISTA DE CLIENTES."<<endl;
    cout<< "5. MOSTRAR LISTA DE PRESTAMOS."<<endl;
    cout<< "6. MOSTRAR DETALLES DEL PRESTAMO."<<endl;
    cout<< "7. SALIR"<<endl;
    cout<< "DIGITE UNA OPCION: "<<endl;
    cin>>op;

    return op;
}
Cliente *agregarCliente(){
    int id;
    string n,a;
    Cliente *cli;
    cout<< "INGRESE EL ID DEL CLIENTE: ";
    cin>>id;
    cout<< "INGRESE EL NOMBRE DEL CLIENTE: ";
    cin>>n;
    cout<< "INGRESE EL APELLIDO DEL CLIENTE: ";
    cin>>a;
    cli=new Cliente(id, n, a);
    return cli;
}
Cliente *BuscarCliente(Cliente *lst[],int cont,int db){
    bool Encontrado = false;
    int contador=0;
    Cliente *cli = NULL;
    while(contador < cont && !Encontrado){
        if (lst[contador]->getIdCliente() == db){
            Encontrado = true;
            cli=lst[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli){
    int np;
    int d, m, a;
    Fecha *fa;
    float ma;
    Prestamo *ptmo;
    cout <<  "DIGITE EL NUMERO DEL PRESTAMO : ";
    cin >>np;
    cout <<  "DIGITE LA FECHA DE APROBACION (DD/MM/AA) : \n";
    cin >> d;
    cin >> m;
    cin >> a;
    fa = new Fecha(d,m,a);
    cout <<  "DIGITE EL MONTO DEL CLIENTE : ";
    cin >> ma;
    ptmo = new Prestamo(np, cli, fa, ma);
    return ptmo;
}
void registrarPago(Prestamo *ptmo){
    int d,m,a;
    Fecha *fp;
    float mp;
    Pago *pg;
    cout << "DIGITE LA FECHA DE PAGO (DD/MM/AA) : ";
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "DIGITE EL MONTO DEL PAGO : ";
    cin >> mp;
    fp = new Fecha(d,m,a);
    pg = new Pago(fp, mp);
    ptmo->hacerPago(pg);
}
void verDetalles(Prestamo *ptmo){
    cout << "EL NUMERO : " << ptmo->getNumeroPrestamo()<<endl;
    cout << "CLIENTE : " << ptmo->getCliente()->getNombre()<< "" << ptmo->getCliente()->getApellido()<<endl;
    cout << "FECHA-APROBACION : ";
    ptmo->getFechaAprobacion()->mostrarFecha();
    cout << "\nMONTO APROBADO : " << ptmo->getMontoAprobado() << endl;
    cout << "SALDO PENDIENTE : " << ptmo->getSaldoPendiente() << endl;
    if (ptmo->getContadorPagos() == 0){
        cout << "NO TIENE PAGOS REGISTRADOS\n";
    }
    else{
        Pago **lista = ptmo->getLstPagos();
        cout << "no\tFECHA\tMONTO\n";
        for (int i=0;i<ptmo->getContadorPagos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t" << lista[i]->getMontoPago() << endl;
        }
    }
}
Prestamo *BuscarPrestamo(Prestamo *lst[],int cont,int db){
    bool encontrado = false;
    int contador=0;
    Prestamo *ptmo = NULL;
    while(contador < cont && !encontrado){
        if(lst[contador]->getNumeroPrestamo()==db){
            encontrado = true;
            ptmo=lst[contador];
        }
        else{
            contador++;
        }
    }
    return ptmo;
}
int main() {
    Cliente* lstCliente[TML];
    Prestamo* lstPrestamo[TML];
    Cliente* cli = NULL;
    Prestamo* ptmo = NULL;
    int contCli = 0, contPtmo = 0, idCli, idPtmo;
    int opc;
    do {
        system("cls");
        opc = menu();
        switch (opc) {
            case 1: /// AGREGAR CLIENTES
                if (contCli < TML) {
                    lstCliente[contCli] = agregarCliente();
                    contCli++;
                    cout << "EL CLIENTE SE AGREGO CORRECTAMENTE" << endl;
                } else {
                    cout << "LA LISTA DE CLIENTES ESTA LLENA." << endl;
                }
                break;
            case 2:///AGREGAR PRESTAMOS
                if (contPtmo < TML) {
                    cout << "DIGITE EL ID DEL CLIENTE : ";
                    cin >> idCli;
                    cli = BuscarCliente(lstCliente, contCli, idCli);
                    if (cli) {
                        lstPrestamo[contPtmo] = agregarPrestamo(cli);
                        contPtmo++;
                        cout << "EL PRESTAMO SE REGISTRO CON EXITO" << endl;
                    } else {
                        cout << "EL CLIENTE NO EXISTE, NO SE PUEDE AGREGAR EL PRESTAMO." << endl;
                    }
                }
                break;
            case 3: ///HACER PAGOS
                cout << "DIGITE EL NUMERO DEL PRESTAMO: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if (ptmo) {
                    registrarPago(ptmo);
                    cout << "EL PAGO SE REGISTRO CON EXITO" << endl;
                } else {
                    cout << "EL PRESTAMO NO EXISTE, NO SE PUEDE REGISTRAR EL PAGO" << endl;
                }
                break;
            case 4: /// MOSTRAR LISTA DE CLIENTES
                if (contCli == 0) {
                    cout << "LA LISTA ESTA VACIA" << endl;
                } else {
                    cout << "ID\tNOMBRE\tAPELLIDO" << endl;
                    for (int i = 0; i < contCli; i++) {
                        cout << lstCliente[i]->getIdCliente() << "\t";
                        cout << lstCliente[i]->getNombre() << "\t";
                        cout << lstCliente[i]->getApellido() << endl;
                    }
                }
                break;
            case 5: /// MOSTRAR LISTA DE PRESTAMOS
                if (contPtmo == 0) {
                    cout << "LA LISTA ESTA VACIA" << endl;
                } else {
                    cout << "NO\tCLIENTE\tFECHA\tMONTO\tSALDO" << endl;
                    for (int i = 0; i < contPtmo; i++) {
                        cout << lstPrestamo[i]->getNumeroPrestamo() << "\t";
                        cout << lstPrestamo[i]->getCliente()->getNombre() << " " << lstPrestamo[i]->getCliente()->getApellido() << "\t";
                        lstPrestamo[i]->getFechaAprobacion()->mostrarFecha();
                        cout << "\t" << lstPrestamo[i]->getMontoAprobado() << "\t";
                        cout << lstPrestamo[i]->getSaldoPendiente() << endl;
                    }
                }
                break;
            case 6:  /// MOSTRAR DETALLE DEL PRESTAMO
                cout << "DIGITE EL NUMERO DEL PRESTAMO: ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if (ptmo) {
                    verDetalles(ptmo);
                } else {
                    cout << "EL PRESTAMO NO EXITE, NO SE PUEDEN VER LOS DETALLES" << endl;
                }
                break;
            case 7: ///SALIR
                cout << "SALIENDO DEL PROGRAMA..." << endl;
                break;
            default:
                cout << "OPCION INVALIDA." << endl;
                break;
        }
        system("pause");
    } while (opc != 7);

    return 0;
}
