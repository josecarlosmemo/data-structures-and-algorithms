/*
  ____  _ _    __                      
 | __ )(_) |_ /_/_  ___ ___  _ __ __ _ 
 |  _ \| | __/ _` |/ __/ _ \| '__/ _` |
 | |_) | | || (_| | (_| (_) | | | (_| |
 |____/|_|\__\__,_|\___\___/|_|  \__,_|
                                                                         
Equipo: 
    - José Carlos Martínez Núñez | A01639664
    - Carla Morales Lopez | A01639225
 */
#include "Bitacora.h"
#include "Algoritmos.h"
#include "ItemBitacora.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

Bitacora bit = Bitacora("bitacora.txt");

//* Función que permite limpiar la pantalla del usuario.
void clear()
{
#ifdef WINDOWS
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
    system(CLEAR);
}

//* Función que permite hacer delays
void sleep(int segs)
{
    this_thread::sleep_for(std::chrono::seconds(segs));
}

//* Imprime el banner de Bítacora
void banner()
{
    cout << "  ____  _ _    __                      " << endl;
    cout << " | __ )(_) |_ /_/_  ___ ___  _ __ __ _ " << endl;
    cout << " |  _ \\| | __/ _\\` |/ __/ _ \\| '__/ _\\|" << endl;
    cout << " | |_) | | || (_| | (_| (_) | | | (_| |" << endl;
    cout << " |____/|_|\\__\\__,_|\\___\\___/|_|  \\__,_|" << endl;
    cout << "                                       ";
    cout << "                        Tamaño Total: " << bit.getSize() << endl;
}

//* Comienza el proceso de preguntarle al usuario por una fecha. Toma el valor de 0 como fecha de inicio y 1 como fecha final.
ItemBitacora preguntarFecha(int tipoFecha)
{
    vector<string> titulosFechas = {
        "Ingresa fecha de Inicio: ",

        "Ingresar fecha de Fin: "

    };

    string mes;
    int dia = 0;
    int hora = 0;
    int minuto = 0;
    int segundo = 0;

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosFechas[tipoFecha] << endl;
        cout << "Ingrese el Mes ej. Jan: ";
        cin >> mes;
        if (!cin.good() || !((mes == "Jan") || (mes == "Feb") || (mes == "Mar") || (mes == "Apr") || (mes == "May") || (mes == "Jun") || (mes == "Jul") || (mes == "Aug") || (mes == "Sep") || (mes == "Oct") || (mes == "Nov") || (mes == "Dec")))
        {
            cout << "El mes ingresado no es válido." << endl;
            cin.clear();
            sleep(1);
            continue;
        }
        break;
    }

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosFechas[tipoFecha] << endl;

        cout << "Ingrese el dia ej. 01: ";
        cin >> dia;

        if (!cin.good() || (dia > 31) || (dia < 1))
        {
            cout << "El día ingresado no es válido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep(1);
            continue;
        }
        break;
    }

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosFechas[tipoFecha] << endl;

        cout << "Ingrese la hora ej. 23: ";
        cin >> hora;

        if (!cin.good() || (hora > 23) || (hora < 0))
        {
            cout << "La hora ingresada es inválida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep(1);
            continue;
        }
        break;
    }

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosFechas[tipoFecha] << endl;

        cout << "Ingrese el minuto ej. 59: ";

        cin >> minuto;

        if (!cin.good() || (minuto > 59) || (minuto < 0))
        {
            cout << "El minuto ingresado es inválido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep(1);
            continue;
        }
        break;
    }

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosFechas[tipoFecha] << endl;

        cout << "Ingrese el segundo ej. 59: ";

        cin >> segundo;

        if (!cin.good() || (segundo > 59) || (segundo < 0))
        {
            cout << "El segundo ingresado es inválido." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            sleep(1);
            continue;
        }
        break;
    }

    return ItemBitacora(mes, dia, hora, minuto, segundo, "-", "-");
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        vector<ItemBitacora> results;
        string archivo;

        clear();

        banner();

        ItemBitacora inicial = preguntarFecha(0);

        ItemBitacora final = preguntarFecha(1);

        try
        {

            results = bit.busqueda(inicial, final);
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            sleep(3);
            continue;
        }
        cout << endl
             << "Nombre para generar un archivo de texto con los resultados: ";
        cin >> archivo;

        cout << endl
             << "--- RESULTADOS ---" << endl;
        Bitacora::exportarBitacora(results, archivo);

        cout << endl
             << "Presiona ENTER para continuar..." << flush;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
