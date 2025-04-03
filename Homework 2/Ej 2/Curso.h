#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include "Estudiante.h"

using namespace std;

class Curso {
private:
    vector<shared_ptr<Estudiante>> estudiantes; 
    string nombre; // Nombre del curso

public:
    // Constructor
    Curso(string name);

    // Constructor de copia shallow
    Curso(string name,  const Curso&  otro);

    string getNombre() const;
    shared_ptr<Estudiante> getEstudiante(int legajo);
    bool estaInscripto(int legajo) const;
    void inscribirEstudiante(shared_ptr<Estudiante> estudiante);
    void desinscribirEstudiante(shared_ptr<Estudiante> estudiante);
    bool estaLleno() const;

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Curso& curso);
};

bool compararEstudiantes(const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b);
