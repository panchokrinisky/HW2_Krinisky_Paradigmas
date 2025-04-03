
#include<string>
using namespace std;

#pragma once

class Numero{
    public:
        virtual shared_ptr<Numero> operator+(const Numero& otro) = 0;
        virtual shared_ptr<Numero> operator-(const Numero& otro) = 0;
        virtual shared_ptr<Numero> operator*(const Numero& otro) = 0;
        virtual void toString() const = 0;
};

class Entero: public Numero{
    private:
    const int entero;

    public:
        Entero(int ent) : entero (ent) {}

        int getEntero() const {return entero;}
        shared_ptr<Numero> operator+(const Numero& otro) override;
        shared_ptr<Numero> operator-(const Numero& otro) override;
        shared_ptr<Numero> operator*(const Numero& otro) override;
        void toString() const override;
};

class Real: public Numero{
    protected:
    const double real;

    public:
        
        Real(double re) : real (re) {}

        double getReal() const { return real;}

        shared_ptr<Numero> operator+(const Numero& otro) override;
        shared_ptr<Numero> operator-(const Numero& otro) override;
        shared_ptr<Numero> operator*(const Numero& otro) override;
        void toString() const override;
};

class Complejo: public Numero{
    private:
    const double real;
    const double imaginario;

    public:
        Complejo(double re, double im) : real (re), imaginario(im) {}

        double getReal() const { return real;}
        double getImaginario() const { return imaginario;}
        shared_ptr<Numero> operator+(const Numero& otro) override;
        shared_ptr<Numero> operator-(const Numero& otro) override;
        shared_ptr<Numero> operator*(const Numero& otro) override;
        void toString() const override;
};