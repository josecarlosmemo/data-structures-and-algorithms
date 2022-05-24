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
#include <chrono>
#include "BitacoraAVL.h"

using namespace std;

int main(int argc, char const *argv[])
{
    auto start = std::chrono::high_resolution_clock::now();

    BitacoraAVL test("bitacora.txt");

    test.imprimir();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Tiempo total: " << duration.count() << " microsegundos." << std::endl;

    return 0;
}
