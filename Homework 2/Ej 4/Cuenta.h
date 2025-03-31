#include <string>
#include <iostream>
using namespace std;

#pragma once

class Cuenta{
    protected:
    // Pongo todos los atributos en protected para que quede privado en las subclases pero puedan acceder a ellos desde dentro ya que la propia clase Cuenta no los necesita.    
        string titularCuenta; 
        double balance; 
        Cuenta(int saldo,string nombre): titularCuenta(nombre),balance(saldo) {}
        void virtual mostrarInfo() = 0;
        virtual void depositar(int deposito) = 0;
        void virtual retirar(int salida) = 0;
};

class CajaDeAhorro: public Cuenta{
    private:
        int contadorMostrarInfo; //Lo dejo en privado ya que solo lo necesita CajaDeAhorro
    public:
        //Todos estos metodos estan en public para que el usuario los pueda utilizar
        CajaDeAhorro(int saldo,string nombre): Cuenta(saldo, nombre) {}
        void retirar(int salida) override;
        void depositar(int deposito) override;
        void  mostrarInfo() override;
    
    friend class CuentaCorriente; //Hago que CuentaCorriente sea friend de CajaDeAhorro para que la Cuenta pueda acceder al balance de la caja y retirar de ella si es necesario.
};

class CuentaCorriente: public Cuenta{
    public:
        //Todos estos metodos estan en public para que el usuario los pueda utilizar
        CuentaCorriente(int saldo,string nombre): Cuenta(saldo, nombre) {}
        void mostrarInfo() override;
        void retirarConCaja(int salida, shared_ptr<CajaDeAhorro> caja);
        void retirar(int salida) override; 
        void depositar(int deposito) override;
        
};