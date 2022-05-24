/*
  ____  _ _    __                      
 | __ )(_) |_ /_/_  ___ ___  _ __ __ _ 
 |  _ \| | __/ _` |/ __/ _ \| '__/ _` |
 | |_) | | || (_| | (_| (_) | | | (_| |
 |____/|_|\__\__,_|\___\___/|_|  \__,_|
                                                                         
Equipo: 
    - José Carlos Martínez Núñez | A01639664
    - Carla Morales López | A01639225
 */
#include "Bitacora.h"
#include "Algoritmos.h"
#include "ItemBitacora.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

Bitacora bit = Bitacora("bitacora.txt");

//* Función que permite limpiar la pantalla del usuario.
void clear()
{
#ifndef WINDOWS
#define CLEAR "clear"
#else
#define CLEAR "cls"
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
ItemBitacora preguntarIP(int tipoIP)
{
    vector<string> titulosIP = {
        "Ingresa IP de Inicio: ",

        "Ingresar IP de Fin: "

    };

    string ip;

    while (true)
    {
        clear();
        banner();
        cout << endl
             << titulosIP[tipoIP] << endl;
        cout << "Ingrese la IP: ";
        cin >> ip;

        // Expresión Regular para la validación de IP
        // https://stackoverflow.com/a/23542162
        if (!cin.good() || !(regex_match(ip, regex("[0-9]+(?:\\.[0-9]+){3}(:[0-9]+)?"))))
        {
            cout << "La IP ingresada no es válida." << endl;
            cin.clear();
            sleep(1);
            continue;
        }
        break;
    }

    return ItemBitacora("Jan", 1, 1, 1, 1, ip, "-");
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        vector<ItemBitacora> results;
        string archivo;

        clear();

        banner();

        ItemBitacora inicial = preguntarIP(0);

        ItemBitacora final = preguntarIP(1);

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
        Bitacora::exportar(results, archivo);

        cout << endl
             << "Presiona ENTER para continuar..." << flush;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
