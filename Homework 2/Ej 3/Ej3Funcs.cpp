#include <iostream>
#include <memory>
#include "Numero.h"
using namespace std;

/*
Con todas las operaciones aritmeticas uso dynamic cast para verificar el tipo del
dato que se esta sumando al entero, si cuando trato de castear el puntero se crea
significa que el objeto es de ese tipo, una vez con el tipo sabido se hace la
operacion y se crea un nuevo objeto con el tipo mas 'complejo', es decir, si sume
un entero con un real, el resultado va a ser un real, si sumo un entero con un
complejo el resultado va a ser un complejo, etc.

Todas las operaciones aritmeticas tienen codigo muy similar siguiendo esa metodologia, la
unica con una diferencia mayor es la aritmetica de complejos que tambien debe considerar otro
resultado cuando se suman dos complejos usando su formula.
*/

//Suma con un entero
std::shared_ptr<Numero> Entero::operator+(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        int resultado = (this->entero + ptrAEntero->getEntero());
        return std::make_shared<Entero>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->entero + ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado = (this->entero + ptrAComplejo->getReal());
        return std::make_shared<Complejo>(resultado,ptrAComplejo->getImaginario());
    }
    throw invalid_argument("El tipo de dato utlizado no es valido");
    return;
}
//Resta con un entero
std::shared_ptr<Numero> Entero::operator-(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        int resultado = (this->entero - ptrAEntero->getEntero());
        return std::make_shared<Entero>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->entero - ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado = (this->entero - ptrAComplejo->getReal());
        return std::make_shared<Complejo>(resultado,ptrAComplejo->getImaginario());
    }

}
//Multiplicacion con un entero
std::shared_ptr<Numero> Entero::operator*(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        int resultado = (this->entero * ptrAEntero->getEntero());
        return std::make_shared<Entero>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->entero * ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultadoRe = (this->entero * ptrAComplejo->getReal());
        double resultadoIm = (this->entero * ptrAComplejo->getImaginario());
        return std::make_shared<Complejo>(resultadoRe,resultadoIm);
    }

}

//Mostrar el entero en pantalla
void Entero::toString() const{
    cout << this->getEntero();
    return;
}

//Suma con un Real
std::shared_ptr<Numero> Real::operator+(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultado = (this->getReal() + ptrAEntero->getEntero());
        return std::make_shared<Real>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->getReal() + ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado = (this->getReal() + ptrAComplejo->getReal());
        return std::make_shared<Complejo>(resultado,ptrAComplejo->getImaginario());
    }

}
//Resta con un Real
std::shared_ptr<Numero> Real::operator-(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultado = (this->getReal() - ptrAEntero->getEntero());
        return std::make_shared<Real>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->getReal() - ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado = (this->getReal() - ptrAComplejo->getReal());
        return std::make_shared<Complejo>(resultado,ptrAComplejo->getImaginario());
    }

}
//Multiplicacion con un Real
std::shared_ptr<Numero> Real::operator*(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultado = (this->getReal() * ptrAEntero->getEntero());
        return std::make_shared<Real>(resultado);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->getReal() * ptrAReal->getReal());
        return std::make_shared<Real>(resultado);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultadoRe = (this->getReal() * ptrAComplejo->getReal());
        double resultadoIm = (this->getReal() * ptrAComplejo->getImaginario());
        return std::make_shared<Complejo>(resultadoRe,resultadoIm);
    }

}

//Mostrar el Real en pantalla
void Real::toString() const{
    cout << this->getReal();
    return;
}


//Suma con un complejo
std::shared_ptr<Numero> Complejo::operator+(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultado = (this->getReal() + ptrAEntero->getEntero());
        return std::make_shared<Complejo>(resultado,this->getImaginario());
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->getReal() + ptrAReal->getReal());
        return std::make_shared<Complejo>(resultado,this->getImaginario());
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado1 = (this->getReal() + ptrAComplejo->getReal());
        double resultado2 = (this->getImaginario() + ptrAComplejo->getImaginario());
        return std::make_shared<Complejo>(resultado1,resultado2);
    }

}
//Resta con un complejo
std::shared_ptr<Numero> Complejo::operator-(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultado = (this->getReal() - ptrAEntero->getEntero());
        return std::make_shared<Complejo>(resultado,this->getImaginario());
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultado = (this->getReal() - ptrAReal->getReal());
        return std::make_shared<Complejo>(resultado,this->getImaginario());
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        double resultado1 = (this->getReal() - ptrAComplejo->getReal());
        double resultado2 = (this->getImaginario() - ptrAComplejo->getImaginario());
        return std::make_shared<Complejo>(resultado1,resultado2);
    }

}
//Multiplicacion con un complejo
std::shared_ptr<Numero> Complejo::operator*(const Numero& otro) {

    const Entero* ptrAEntero = dynamic_cast<const Entero*>(&otro); 
    if (ptrAEntero){
        double resultadoRe = (this->getReal() * ptrAEntero->getEntero());
        double resultadoIm = (this->getImaginario() * ptrAEntero->getEntero());
        return std::make_shared<Complejo>(resultadoRe,resultadoIm);
    }
    const Real* ptrAReal = dynamic_cast<const Real*>(&otro); 
    if (ptrAReal){
        double resultadoRe = (this->getReal() * ptrAReal->getReal());
        double resultadoIm = (this->getImaginario() * ptrAReal->getReal());
        return std::make_shared<Complejo>(resultadoRe,resultadoIm);
    }
    const Complejo* ptrAComplejo = dynamic_cast<const Complejo*>(&otro);
    if (ptrAComplejo){
        //Aca hago la multiplicacion de Complejos: ac-bd para la parte real y ad+bc para la parte imaginaria
        double resultado1 = ((this->getReal() * ptrAComplejo->getReal()) - (this->getImaginario() * ptrAComplejo->getImaginario()));
        double resultado2 = ((this->getReal() * ptrAComplejo->getImaginario()) + (this->getImaginario() * ptrAComplejo->getReal()));
        return std::make_shared<Complejo>(resultado1, resultado2);
    }

}

//Mostrar el Complejo en pantalla
void Complejo::toString() const{
    double im =  this->getImaginario();
    if (im>=0){
        cout << this->getReal() << "+" << this->getImaginario() << "i";
        return;    
    } else{
        cout << this->getReal() << this->getImaginario() << "i"; //No pongo el signo de menos porque ya viene con el numero
        return;
    }    
}

