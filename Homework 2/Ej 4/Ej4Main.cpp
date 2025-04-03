#include "Cuenta.h"
#include "Ej4Funcs.h"
#include <iostream>
#include <memory>
using namespace std;

//Asumo que todos los inputs seran del tipo que se especifica.



int main() {
    // Crear una cuenta corriente y una caja de ahorro
    string nombreTitular;
    cout << "Ingrese el nombre del titular de la cuenta: " << endl;
    getline(cin,nombreTitular);
    shared_ptr<CajaDeAhorro> cajaDeAhorro = make_shared<CajaDeAhorro>(200, nombreTitular);
    shared_ptr<CuentaCorriente> cuentaCorriente = make_shared<CuentaCorriente>(100, nombreTitular);

    int opcion = 0;

    while (opcion != 8) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int deposito;
                cout << "Ingrese la cantidad a depositar en la Caja de Ahorro: ";
                cin >> deposito;
                cajaDeAhorro->depositar(deposito);
                break;
            }
            case 2: {
                int deposito;
                cout << "Ingrese la cantidad a depositar en la Cuenta Corriente: ";
                cin >> deposito;
                cuentaCorriente->depositar(deposito);
                break;
            }
            case 3: {
                int retiro;
                cout << "Ingrese la cantidad a retirar de la Caja de Ahorro: ";
                cin >> retiro;
                cajaDeAhorro->retirar(retiro);
                break;
            }
            case 4: {
                int retiro;
                cout << "Ingrese la cantidad a retirar de la Cuenta Corriente (usando Caja de Ahorro si es necesario): ";
                cin >> retiro;
                cuentaCorriente->retirarConCaja(retiro, cajaDeAhorro);
                break;
            }
            case 5: { 
                int retiro;
                cout << "Ingrese la cantidad a retirar de la Cuenta Corriente (sin usar Caja de Ahorro): ";
                cin >> retiro;
                cuentaCorriente->retirar(retiro);
                break;
            }
            case 6: {
                cajaDeAhorro->mostrarInfo();
                break;
            }
            case 7: {
                cuentaCorriente->mostrarInfo();
                break;
            }
            case 8: {
                cout << "Saliendo del programa. ¡Gracias por usar el sistema!" << endl;
                break;
            }
            default: {
                cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}