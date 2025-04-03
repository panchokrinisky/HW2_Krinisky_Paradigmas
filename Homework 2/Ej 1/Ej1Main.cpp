#include "Time.h"
#include "Ej1Funcs.h"


int main(void) {
    Time tiempo = create_time();
    cout << "Muchas gracias el tiempo ha sido configurado exitosamente" << endl;
    tiempo.get_time();
    //Hasta aca crea el tiempo y lo muestra para ver que se haya configurado bien.

    int opcion = 0;
    while (opcion != 11) {
        //Se abre un menu en terminal para ofrecer todas las opciones que tiene el usuario
        cout << "Ingrese la opcion que solicite hacer:" << endl;
        cout << "1.  Ver las horas actuales" << endl;
        cout << "2.  Ver los minutos actuales" << endl;
        cout << "3.  Ver los segundos actuales" << endl;
        cout << "4.  Mostrar etapa del dia" << endl;
        cout << "5.  Ver el tiempo actual" << endl;
        cout << "6.  Ver el tiempo actual en formato 24 hs" << endl;
        cout << "7.  Cambiar la hora actual" << endl;
        cout << "8.  Cambiar los minutos actuales" << endl;
        cout << "9.  Cambiar los segundos actuales" << endl;
        cout << "10. Cambiar la etapa del dia actual" << endl;
        cout << "11. Salir del programa" << endl;

        cin >> opcion;

        if (cin.fail()){ //Se vuelve a intentar si el usuario no ingresa un tipo int por terminal.
            cin.clear();
            cin.ignore();
            cout << "Opcion no valida, intente de nuevo." << endl;
            continue;
        }

        //En el resto de inputs del usuario asumo que va a ingresar el tipo de dato pedido. Por ejemplo, cuando pide una hora el ususario no va a ingresar un char o un string.

        switch (opcion) { //Dependiendo que haya elegido el usuario con este switch se elije la opcion.
            case 1:
                tiempo.get_hour();
                break;
            case 2:
                tiempo.get_min();
                break;
            case 3:
                tiempo.get_sec();
                break;
            case 4:
                tiempo.get_stage();
                break;
            case 5:
                tiempo.get_time();
                break;
            case 6:
                tiempo.get_full_time();
                break;
            case 7: {
                int hora = 100;
                while (hora > 12 || hora < -1) {
                    cout << "Ingrese unicamente la hora actual (del 0 al 12): (Si quiere salir introduzca -1)" << endl;
                    cin >> hora;
                    if (hora == -1) {
                        break;
                    }
                    if (hora > 12 || hora < 0) {
                        cout << "La hora que se ha ingresado no es valida intente de nuevo. " << endl;
                    } else {
                        tiempo.set_hour(hora);
                        break;
                    }
                }
                break;
            }
            case 8: {
                int minuto = 100;
                while (minuto > 59 || minuto < -1) {
                    cout << "Ingrese unicamente los minutos actuales (del 0 al 59): (Si quiere salir introduzca -1)" << endl;
                    cin >> minuto;
                    if (minuto == -1) {
                        break;
                    }
                    if (minuto > 59 || minuto < 0) {
                        cout << "Los minutos que se han ingresado no son validos intente de nuevo. " << endl;
                    } else {
                        tiempo.set_min(minuto);
                        break;
                    }
                }
                break;
            }
            case 9: {
                int segundo = 100;
                while (segundo > 59 || segundo < -1) {
                    cout << "Ingrese unicamente los segundos actuales (del 0 al 59): (Si quiere salir introduzca -1)" << endl;
                    cin >> segundo;
                    if (segundo == -1) {
                        break;
                    }
                    if (segundo > 59 || segundo < 0) {
                        cout << "Los segundos que se han ingresado no son validos intente de nuevo. " << endl;
                    } else {
                        tiempo.set_sec(segundo);
                        break;
                    }
                }
                break;}

            case 10: {
                string etapa = "etapa";
                while (etapa != "a.m." && etapa != "p.m." && etapa != "NO") {
                    cout << "Ingrese la etapa del dia actual (a.m / p.m.): (Si quiere obviar esto introduzca 'NO')" << endl;
                    cin >> etapa;
                    if (etapa == "NO") {
                        break;
                    }
                    if (etapa != "a.m." && etapa != "p.m." && etapa != "NO") {
                        cout << "La etapa que se ha ingresado no es valida, intente de nuevo. " << endl;
                    } else {
                        tiempo.set_stage(etapa);
                        break;
                    }
                }
                break;}

            case 11:
                cout << "Saliendo del programa..." << endl;
                break;
            default: //Si el usuario pone un tipo int invalido le pide que vuelve a intentar
                cout << "Opcion no valida, intente de nuevo." << endl;
                break;
        }
    }
    return 0;
}

