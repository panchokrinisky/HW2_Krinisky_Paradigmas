#include <iostream>
#include "Numero.h"
using namespace std;

int main(void) {
    // Creo dos objetos de cada tipo: Entero, Real y Complejo
    shared_ptr<Numero> entero1 = make_shared<Entero>(5);
    shared_ptr<Numero> entero2 = make_shared<Entero>(10);
    shared_ptr<Numero> real1 = make_shared<Real>(3.5);
    shared_ptr<Numero> real2 = make_shared<Real>(7.2);
    shared_ptr<Numero> complejo1 = make_shared<Complejo>(2.0, 3.0);
    shared_ptr<Numero> complejo2 = make_shared<Complejo>(4.0, -1.0);

    //Pruebas de suma
    //Como toString imprime directamente en la terminal puse algunas cosas de corrido
    //Para que sean mas legibles xq no se podia hacer un solo cout ya que toString no devuelve
    cout << "Pruebas de suma:" << endl;
    entero1->toString(); cout << " + "; entero2->toString(); cout << " = ";
    (*entero1 + *entero2)->toString(); cout << endl;

    entero1->toString(); cout << " + "; real1->toString(); cout << " = ";
    (*entero1 + *real1)->toString(); cout << endl;

    entero1->toString(); cout << " + "; complejo1->toString(); cout << " = ";
    (*entero1 + *complejo1)->toString(); cout << endl;

    real1->toString(); cout << " + "; real2->toString(); cout << " = ";
    (*real1 + *real2)->toString(); cout << endl;

    real1->toString(); cout << " + "; complejo1->toString(); cout << " = ";
    (*real1 + *complejo1)->toString(); cout << endl;

    complejo1->toString(); cout << " + "; complejo2->toString(); cout << " = ";
    (*complejo1 + *complejo2)->toString(); cout << endl;

    // Pruebas de resta
    cout << "\nPruebas de resta:" << endl;
    entero2->toString(); cout << " - "; entero1->toString(); cout << " = ";
    (*entero2 - *entero1)->toString(); cout << endl;

    entero1->toString(); cout << " - "; real1->toString(); cout << " = ";
    (*entero1 - *real1)->toString(); cout << endl;

    entero1->toString(); cout << " - "; complejo1->toString(); cout << " = ";
    (*entero1 - *complejo1)->toString(); cout << endl;

    real2->toString(); cout << " - "; real1->toString(); cout << " = ";
    (*real2 - *real1)->toString(); cout << endl;

    real1->toString(); cout << " - "; complejo1->toString(); cout << " = ";
    (*real1 - *complejo1)->toString(); cout << endl;

    complejo2->toString(); cout << " - "; complejo1->toString(); cout << " = ";
    (*complejo2 - *complejo1)->toString(); cout << endl;

    // Pruebas de multiplicacion
    cout << "\nPruebas de multiplicacion:" << endl;
    entero1->toString(); cout << " * "; entero2->toString(); cout << " = ";
    (*entero1 * *entero2)->toString(); cout << endl;

    entero1->toString(); cout << " * "; real1->toString(); cout << " = ";
    (*entero1 * *real1)->toString(); cout << endl;

    entero1->toString(); cout << " * "; complejo1->toString(); cout << " = ";
    (*entero1 * *complejo1)->toString(); cout << endl;

    real1->toString(); cout << " * "; real2->toString(); cout << " = ";
    (*real1 * *real2)->toString(); cout << endl;

    real1->toString(); cout << " * "; complejo1->toString(); cout << " = ";
    (*real1 * *complejo1)->toString(); cout << endl;

    complejo1->toString(); cout << " * "; complejo2->toString(); cout << " = ";
    (*complejo1 * *complejo2)->toString(); cout << endl;

    // Pruebas de toString
    cout << "\nPruebas de toString:" << endl;
    cout << "Entero: "; entero1->toString(); cout << endl;
    cout << "Real: "; real1->toString(); cout << endl;
    cout << "Complejo: "; complejo1->toString(); cout << endl;

    return 0;
}