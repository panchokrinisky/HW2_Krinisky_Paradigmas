#include "Time.h"
#include "Ej1Funcs.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


// Para crear la clase hago una funcion privada start tal que valide todos los elemento y luego los aplique, si no son validos devuelve invalid_argument


void Time::start(int h, int m, int s, std::string etapa){
    if (!validate_hour(h)) throw invalid_argument("La hora ingresada es invalida, intente de nuevo.");
    hr = h;
    if (!validate_min(m)) throw invalid_argument("Los minutos ingresados son invalidos, intente de nuevo.");
    min = m;
    if (!validate_sec(s)) throw invalid_argument("Los segundos ingresados son invalidos, intente de nuevo.");
    sec = s;
    if (!validate_stage(etapa))throw invalid_argument("La etapa del dia es invalida ( a.m. / p.m. ), intente de nuevo.");
    stage = etapa;
}

//Estas son todas las funciones internas para validar el tiempo
bool Time::validate_hour(int h){
    if (h>12 || h<0) return false;
    return true;}

bool Time::validate_min(int m){
    if (m>59 || m<0) return false;
    return true;}


bool Time::validate_sec(int s){
    if (s>59 || s<0) return false;
    return true;}

bool Time::validate_stage(std::string etapa){
    if (etapa != "p.m." && etapa != "a.m.") return false;
    return true;}

//Aca tengo todas las funciones que puede usar el usuario para crear un objeto Time, cambiar su horario y 
//imprimir en la terminar lo  que necesite
Time::Time(int h,int m,int s,string stage){
    start(h,m,s,stage);
}
Time::Time(){
    start(0,0,0,"a.m.");
}
Time::Time(int h){
    start(h,0,0,"a.m.");
}
Time::Time(int h,int m){
    start(h,m,0,"a.m.");
}
Time::Time(int h,int m,int s){
    start(h,m,s,"a.m.");
}

//Todos los setters
void Time::set_hour(int h){
    if (!validate_hour(h)) throw invalid_argument("La hora ingresada es invalida, intente de nuevo.");
    hr = h;
}
void Time::set_min(int m){
    if (!validate_min(m)) throw invalid_argument("Los minutos ingresados son invalidos, intente de nuevo.");
    min = m;

}
void Time::set_sec(int s){
    if (!validate_sec(s)) throw invalid_argument("Los segundos ingresados son invalidos, intente de nuevo.");
    sec = s;
}

void Time::set_stage(string etapa){
    if (!validate_stage(etapa))throw invalid_argument("La etapa del dia es invalida ( a.m. / p.m. ), intente de nuevo.");
    stage = etapa;
}

//Todos los getters
void Time::get_hour(void){
    cout << setfill('0') << setw(2) << hr << "h" << endl;
}
void Time::get_min(void){
    cout << setfill('0') << setw(2) << min << "m" << endl;
}
void Time::get_sec(void){
    cout << setfill('0') << setw(2) << sec << "s" << endl;
}
void Time::get_stage(void){
    cout << stage << endl;
}
void Time::get_time(void){
    cout << setfill('0') << setw(2) << hr << "h, " << setfill('0') << setw(2) << min << "m, " << setfill('0') << setw(2) << sec << "s, "<< stage << endl;
}
void Time::get_full_time(void){
    int full_hr = hr;
    if (stage == "p.m." && hr != 12) full_hr += 12;
    if (stage == "a.m." && hr == 12) full_hr = 0;
    cout << setfill('0') << setw(2) << full_hr << "h, " << setfill('0') << setw(2) << min << "m, " << setfill('0') << setw(2) << sec << "s"<< endl;
};

Time create_time(void){
    /**
     * create_time es una funcion que crea un objeto clase Time con la interaccion por terminal del usuario.
     * Devuelve el objeto con los parametros iniciados y en cualquier caso donde no se inserte nada se pondra 0 
     * En el caso del stage se pondra a.m. si no se pone nada.
     */
    
    int hora = 100;
    int minuto = 100;
    int segundo = 100;
    string etapa = "etapa";
    //Inicio los valores con cosas incorrectas para que se queden en el while y no haya errores al inicializarlos vacios
    
    while (hora > 12 || hora <-1){
        cout << "Ingrese unicamente la hora actual (del 0 al 12): (Si quiere obviar esto introduzca -1)" << endl;
        cin >> hora;
        if (hora == -1){
            Time tiempo = Time();
            return tiempo;
        }
        if (hora > 12 || hora < -1){
                cout << "La hora que se ha ingresado no es valida intente de nuevo. " <<endl;
                continue;}
    }
    
    
    while (minuto > 59 || minuto <-1){
        cout << "Ingrese unicamente los minutos actuales: (Si quiere obviar esto introduzca -1)" << endl;
        cin >> minuto;
        if (minuto == -1){
            Time tiempo = Time(hora);
            return tiempo;
        } if (minuto > 59 || minuto <-1){
            cout << "Los minutos que se han ingresado no son validos intente de nuevo. " <<endl;
            continue;}
    }

    while (segundo > 59 || segundo <-1){
        cout << "Ingrese unicamente los segundos actuales: (Si quiere obviar esto introduzca -1)" << endl;
        cin >> segundo;
        if (segundo == -1){
            Time tiempo = Time(hora,minuto);
            return tiempo;}
        if (segundo > 59 || segundo <-1){
            cout << "Los segundos que se han ingresado no son validos intente de nuevo. " <<endl; 
            continue;}}
    
    while (etapa != "a.m." && etapa != "p.m." && etapa != "NO"){
        cout << "Ingrese la etapa del dia actual (a.m / p.m.): (Si quiere obviar esto introduzca 'NO')" << endl;
        cin >> etapa;
        if (etapa == "NO"){
            Time tiempo = Time(hora,minuto,segundo);
            return tiempo;}
        if (etapa != "a.m." && etapa != "p.m." && etapa != "NO"){
        cout << "La etapa ingresada no es valida intente de nuevo. " <<endl; 
        continue;}
    }
    Time tiempo = Time(hora,minuto,segundo,etapa);
    return tiempo;
}