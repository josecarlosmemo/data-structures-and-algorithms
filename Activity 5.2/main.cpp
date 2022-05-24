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
#include <iostream>
#include "HashTable.h"

using namespace std;

int main()

{
    int dominio;

    HashTable test("bitacora.txt");

    cout << "Ingresa Dominio a Mostrar: ";
    cin >> dominio;

    test.imprimir(dominio);
    return 0;
}
