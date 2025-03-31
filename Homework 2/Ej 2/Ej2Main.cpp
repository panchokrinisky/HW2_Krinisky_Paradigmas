#include <iostream>
#include <vector>
#include <string>
#include "Ej2Funcs.h"
#include "Estudiante.h"
#include "Curso.h"

//El inciso v del punto b se encuentra sobre la implementacion del constuctor copia de Curso 

// c. ¿Qué tipo de relación existe entre los objetos curso y estudiante? 

/*
Los objetos curso y estudiante tienen una relacion de asociacion ya que ambos estan
vinculados pero ninguno tiene ownership sobre el otro, por ejemplo, si se elimina un 
curso y hay un alumno dentro de este pero tambien forma parte de otro mas no hara que 
el alumno deje de existir, solo dejara de estar en el curso que fue eliminado.
No hay una relacion de dependencia sino que cada uno tiene un lifetime propio 
pero esta asociado al otro.

*/

int main(void) {
    vector<Curso> cursos; // Vector para guardar multiples cursos
    int opcion = 0;

    cout << "Bienvenido al sistema de gestion de cursos." << endl;
    cout << "Primero, cree un curso para comenzar." << endl;

    // Crear el primer curso
    cursos.push_back(crearCurso());

    while (true) {
        cout << "\n--- Menu Principal ---" << endl;
        cout << "1. Imprimir cursos" << endl;
        cout << "2. Gestionar un curso" << endl;
        cout << "3. Crear curso nuevo" << endl;
        cout << "4. Copiar curso" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Imprimir todos los cursos
                cout << "\n--- Lista de Cursos ---" << endl;
                for (size_t i = 0; i < cursos.size(); ++i) { 
                    cout << i + 1 << ". " << cursos[i].getNombre() << endl; //Uso el i + 1 para que los indices arranquen desde 1 para que sea mas estetico que arrancar de 0
                }
                break;
            }
            case 2: {
                int cursoIndex = 0;
                cout << "Elija el numero de indice del curso que desea gestionar (1 a " << cursos.size() << "): ";
                cin >> cursoIndex;

                // Validacion de indice
                if (cursoIndex < 1 || cursoIndex > cursos.size()) {
                    cout << "Indice invalido. Intente nuevamente." << endl;
                } else {
                    menuCurso(cursos[cursoIndex - 1]); // Llama al menu del curso seleccionado
                }
                break;
            }
            case 3: {
                cursos.push_back(crearCurso());
                break;
            }
            case 4: {
                int cursoIndex = 0;
                cout << "Elija el numero de indice del curso que desea copiar (1 a " << cursos.size() << "): ";
                cin >> cursoIndex;

                // Validacion del indice 
                if (cursoIndex < 1 || cursoIndex > cursos.size()) {
                    cout << "Indice invalido. Intente nuevamente." << endl;
                } else {
                    string nuevoNombre;
                    cout << "Ingrese el nombre del nuevo curso: ";
                    cin.ignore(); 
                    getline(cin, nuevoNombre); //Para que el curso pueda tener espacios en el nombre

                    // Crear el nuevo curso copiando los estudiantes del curso seleccionado
                    Curso nuevoCurso(nuevoNombre, cursos[cursoIndex - 1]);
                    cursos.push_back(nuevoCurso);

                    cout << "El curso: "<< nuevoNombre << " ha sido creado exitosamente con los mismos estudiantes que el curso: "  << cursos[cursoIndex - 1].getNombre() << "." << endl;
                }
                break;
            }
            case 5: {
                // Salir del programa
                cout << "Saliendo del programa..." << endl;
                return 0;
            }
            default: {
                cout << "Opcion no valida. Intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}



