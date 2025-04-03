#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Estudiante {
private:
    string nombre;    
    int legajo;       
    list<int> notas;    

public:
    // Constructor (La nota la agrego aparte)
    Estudiante(string nombre, int legajo);

    // Getters
    string getNombre() const;
    int getLegajo() const;
    int getPromedio() const;

    // Setter
    void setNota(int nota);

    // Sobrecarga del operador <
    bool operator<(const Estudiante& otro) const;
};
