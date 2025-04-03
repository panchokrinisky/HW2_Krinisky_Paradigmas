
#include "Cuenta.h"
#include "Ej4Funcs.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;

void CajaDeAhorro::depositar(int deposito) {
    if (deposito<=0){
        cout << "Por que depositarias plata en negativo...?" << endl;
        return;
    } else {
        cout << "Depositando $" << deposito << " A la cuenta..." << endl;
        this->balance+= deposito;
        cout << "Nuevo balance: $" << this->balance << endl;
        return;
    }

}

void CajaDeAhorro::mostrarInfo() {
    cout << "Titular: " << this->titularCuenta << endl;
    cout << "Cuenta actual: Caja de Ahorro" << endl;
    if (contadorMostrarInfo == 3){
        contadorMostrarInfo = 0;
        cout << "Se han descontado $20 por mostrar informacion 3 veces." << endl;
        if (this->balance < 20){
            cout << "Saldo insuficiente, te perdonaremos los $20" << endl;
        } else {
            this->balance -= 20;
        }
        cout << "Balance actual: $" << this->balance << endl;
    } else {
        cout << "Balance actual: $" << this->balance << endl;
    }
    contadorMostrarInfo++;
    cout << "Proximo descuento de $20 en " << 3-(this->contadorMostrarInfo) << " Intento(s)" << endl;
    return;
} 

void CajaDeAhorro::retirar(int salida) {
    if (salida <= 0) {
        cout << "El monto a retirar debe ser mayor a 0. Intente nuevamente." << endl;
        return;
    }
    if (salida > this->balance) {
        cout << "No puedes retirar más dinero del que tienes en tu cuenta." << endl;
        cout << "Por favor, revisa tu saldo antes de intentar nuevamente." << endl;
        return;
    } else {
        this->balance -= salida;
        cout << "$" << salida << " retirados exitosamente." << endl;
        cout << "Nuevo balance: $" << this->balance << endl;
        return;
    }
}

void CuentaCorriente::depositar(int deposito) {
    if (deposito<=0){
        cout << "Por que depositarias plata en negativo...?" << endl;
        return;
    } else {
        cout << "Depositando $" << deposito << " A la cuenta..." << endl;
        this->balance+= deposito;
        cout << "Nuevo balance: $" << this->balance << endl;
        return;
    }

}

void CuentaCorriente::mostrarInfo() {
    cout << "Titular: " << this->titularCuenta << endl;
    cout << "Cuenta actual: Cuenta Corriente" << endl;
    cout << "Balance actual: $" << this->balance << endl;
    return;
}

void CuentaCorriente::retirar(int salida) {
    if (salida<=0){
        cout << "Por que retirarias plata en negativo...?" << endl;
        return;}
    if (salida > this->balance){
        cout << "No puedes retirar más dinero del que tienes en tu cuenta corriente." << endl;
        cout << "Por favor, revisa tu saldo antes de intentar nuevamente." << endl;
        return;
    } else {
        this->balance  -= salida;
        cout << "$" << salida << " Retirados exitosamente." << endl;
        cout << "Nuevo balance: $" << this->balance << endl;
        return;
    }
}

void CuentaCorriente::retirarConCaja(int salida, shared_ptr<CajaDeAhorro> caja) {
    if (salida<=0){
        cout << "Por que retirarias plata en negativo...?" << endl;
        return;}
    int total = this->balance + caja->balance;
    if (salida > total) {
        cout << "El dinero en ambas cuentas no es suficiente para retirar." << endl;
        return;
    }

    int parteCaja = 0;
    int parteCuenta = 0;

    if (salida <= this->balance) {
        parteCuenta = salida;
        this->balance -= parteCuenta;
    } else {
        parteCuenta = this->balance;
        parteCaja = salida - parteCuenta;
        this->balance = 0;
        caja->balance -= parteCaja;
    }

    if (parteCaja > 0) {
        cout << "Se han retirado $" << parteCaja << " de tu caja de ahorros." << endl;
        cout << "Nuevo balance de la caja de ahorro: $" << caja->balance << endl;
    }
    cout << "Se han retirado $" << parteCuenta << " de tu cuenta corriente." << endl;
    cout << "Nuevo balance de la cuenta corriente: $" << this->balance << endl;
}


void mostrarMenu() {
    cout << "\n=== Menu de Opciones ===" << endl;
    cout << "1. Depositar en Caja de Ahorro" << endl;
    cout << "2. Depositar en Cuenta Corriente" << endl;
    cout << "3. Retirar de Caja de Ahorro" << endl;
    cout << "4. Retirar de Cuenta Corriente (usando Caja de Ahorro si es necesario)" << endl;
    cout << "5. Retirar de Cuenta Corriente (sin usar Caja de Ahorro)" << endl; 
    cout << "6. Mostrar informacion de Caja de Ahorro" << endl;
    cout << "7. Mostrar informacion de Cuenta Corriente" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opción: ";
}