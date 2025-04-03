#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>
#include <algorithm>
#include "Curso.h"
#include "Estudiante.h"
#include "Ej2Funcs.h"
using namespace std;



/*
Aclaraciones del diseño:
    -Las notas las pongo en una lista y aunque se borre la materia se va a poder seguir accediendo a la nota ya que el promedio general toma en cuenta los cursos que no son viegentes en la actualidad
    -La nota de un curso no se puede cambiar porque generaria conflictos al no poder usarse map para guardar clave - valor(Cuando pregunte en la tutorial me dijeron que no se podia usarlo). 
    -Una vez creado un curso nuevo sin copiar a otro no se pueden agregar estudiantes de un curso ya existente porque el ejercicio no pide tener una base de datos con todos los Alumnos ya que haria este ejercicio mucho mas extensos.
    -En la mayoria de los inputs se asume que se va a insertar una entrada dentro del rango ofrecido y del tipo que corresponde.
    -Se asume que no se van a repetir los numeros de legajo
    -Estudiante y alumno son lo mismo, no siento que deba aclarar esto pero en algunas variables los uso intercaladamente para no repetir nombre de variable
    -En el main uso funciones para crear curso y el menu para los cursos para que no quede tanto codigo seguido en main.

*/


    //Getters
string Estudiante::getNombre() const {return nombre;}

int Estudiante::getLegajo() const {return legajo;}

int Estudiante::getPromedio() const {
    int promedio = 0;
    if (notas.empty()) return 0;
    for (int nota : notas) {
        promedio += nota;}
    return (promedio / notas.size());}

void Estudiante::setNota(int nota){
    notas.push_back(nota);
    return;
}

bool Estudiante::operator<(const Estudiante& otro) const { return nombre < otro.getNombre();}

// Constructor de Estudiante
Estudiante::Estudiante(string nombre, int legajo)
    : nombre(nombre), legajo(legajo) {}

    /*
    Voy a utilizar una deep copy ya que esta crea una copia de cada alumno en vez de copiar al mismo vector ya que con 
    shallow copy lo que pasaria es que si elimino a un alumno de un curso se eliminaria de todos a los que esta inscripto.
    */
    //Constructor copia
Curso::Curso(string name, const Curso& otro): nombre(name){
    for (const auto& estudiante : otro.estudiantes) {
        // Crear una nueva copia de cada estudiante para evitar que cuando elimine a uno de un curso se elimine de otro
        estudiantes.push_back(make_shared<Estudiante>(*estudiante));
    }
};

// Constructor de Curso
Curso::Curso(string name)
    : nombre(name) {}

    string Curso::getNombre() const {
        return nombre;
    }

    shared_ptr<Estudiante> Curso::getEstudiante(int legajo){
        if (!estaInscripto(legajo)) throw runtime_error("El alumno no esta inscripto en el curso.");
        for (shared_ptr<Estudiante> inscripto : estudiantes){
            if (inscripto->getLegajo() == legajo) return inscripto;
        } return nullptr;
    }

    bool Curso::estaInscripto(int legajo)const{
        for (shared_ptr<Estudiante> estudiante : estudiantes){ 
            // Checkeo que no este ya inscripto
            if (estudiante->getLegajo() == legajo) return true;
        }
    return false;
    }

    void Curso::inscribirEstudiante(shared_ptr<Estudiante> estudiante){
        if (estaInscripto(estudiante->getLegajo())) throw runtime_error("El alumno ya esta inscripto en el curso.");
        if (estaLleno()) throw runtime_error("El curso esta lleno.");
        estudiantes.push_back(estudiante);
        return;
    }
    void Curso::desinscribirEstudiante(shared_ptr<Estudiante> estudiante){
        //Verifica que este inscripto y sino devuelve error
        if (!estaInscripto(estudiante->getLegajo())) throw runtime_error("El alumno no esta inscripto en el curso.");
        // Crea un iterador usando las funciones del vector para encontrar el estudiante y borrarlo del curso
        // Elimina el estudiante del curso pero no lo borra ya que puede estar en otros cursos
        for (auto i = estudiantes.begin(); i != estudiantes.end(); ++i){
            if ((*i)->getLegajo() == estudiante->getLegajo()){
                estudiantes.erase(i);
                return;}
            }
        }
    bool  Curso::estaLleno()const{
        return (estudiantes.size() >= 20);
    }

        

        ostream& operator<<(ostream& os, const Curso& curso); //Hace la sobrecarga friend para que puede acceder a estudiantes


//Esta funcion solo la utiliza para poder comparar nombres de estudiantes para la sobrecarga de <<
bool compararEstudiantes(const shared_ptr<Estudiante>& a,const shared_ptr<Estudiante>& b){
    return *a < *b;
}

// Sobrecarga del operador << para imprimir un curso
ostream& operator<<(ostream& os, const Curso& curso) {
    vector< shared_ptr<Estudiante> > copiaEstudiantes = curso.estudiantes;
    sort(copiaEstudiantes.begin(), copiaEstudiantes.end(), compararEstudiantes);
    for (const shared_ptr<Estudiante> estudiante : copiaEstudiantes) {
        os << estudiante->getNombre() <<". Legajo:" << estudiante->getLegajo() << endl;
    }
    return os;
}


Curso crearCurso(){
    string nombreCurso;
    cout << "Ingrese el nombre del curso: " << endl;
    cin.ignore();
    getline(cin,nombreCurso); //Para que el curso pueda tener espacios en el nombre
    Curso curso = Curso(nombreCurso);
    cout << "El curso: " << nombreCurso << " ha sido creado exitosamente." << endl;
    return curso;
}

void menuCurso(Curso &curso){
    int opcion = 0;
    cout << "El curso ingresado fue: " << curso.getNombre() << endl;
    cout << "Menu de opciones del curso:" << endl;
    cout << "1. Nombre del curso" << endl;
    cout << "2. Inscribir un alumno" << endl;
    cout << "3. Desinscribir un alumno" << endl;
    cout << "4. Imprimir nombres y legajos de los alumnos" << endl;
    cout << "5. Promedio general de un alumno." << endl;
    cout << "6. Volver hacia el menu de cursos" << endl;
    cout << "Elija una opcion: " << endl;
    cin >> opcion;

    switch (opcion){
        case 1: {
            cout << "El nombre del curso es: " << curso.getNombre() << endl;
            break;
        }
        case 2: {
            string nombreAlumno;
            int legajo; // Asumo que se va a ingresar un numero unico
            int nota;
            cout << "Ingrese el nombre completo del alumno: " << endl;
            cin.ignore();
            getline(cin,nombreAlumno); //Asi puede aceptar espacios el nombre
            cout << "Ingrese el legajo del alumno: " << endl;
            cin >> legajo;

            // Verifico si el legajo ya esta inscripto en el curso
            if (curso.estaInscripto(legajo)) {
                cout << "Error: El alumno con legajo " << legajo << " ya está inscrito en el curso." << endl;
                break;
            }
            
            cout << "Ingrese la nota del alumno para esta materia: " << endl;
            cin >> nota;

            // Crear el estudiante y agregarlo al curso
            shared_ptr<Estudiante> alumno = make_shared<Estudiante>(nombreAlumno, legajo);
            alumno->setNota(nota);
            curso.inscribirEstudiante(alumno);
            cout << "El alumno " << nombreAlumno << " con legajo " << legajo << " ha sido inscrito exitosamente." << endl;
            break;
        }
        case 3: {
            int legajo;
            cout << "Ingrese el legajo del alumno que desea desinscribir: " << endl;
            cin >> legajo;
            try {
                shared_ptr<Estudiante> alumno = curso.getEstudiante(legajo);
                curso.desinscribirEstudiante(alumno);
                cout << "El alumno con legajo " << legajo << " ha sido desinscripto exitosamente." << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 4: {
            cout << "Lista de estudiantes en el curso '" << curso.getNombre() << "':" << endl;
            cout << curso; // utilizo la sobrecarga del operador << para imprimir los estudiantes
            break;
        }
        case 5: {
            int legajo;
            cout << "Ingrese el legajo del alumno para calcular su promedio general: " << endl;
            cin >> legajo;
            try {
                shared_ptr<Estudiante> alumno = curso.getEstudiante(legajo);
                cout << "El promedio general del alumno con legajo " << legajo << " es: " << alumno->getPromedio() << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 6: {
            cout << "Volviendo al menú principal..." << endl;
            return; // Sale del menu del curso y vuelve al menu principal
        }
        default: {
            cout << "Opción no válida. Intente nuevamente." << endl;
            break;
        }
    }

    // llama recursivamente al menú del curso para seguir gestionando
    menuCurso(curso);
}