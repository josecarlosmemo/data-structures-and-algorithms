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
#include "Helper.h"
//* Recibe el nombre del archivo a leer y regresa un vector con solamente las IP's en forma de IPBitacora

std::vector<IPBitacora> Helper::leeBitacora(std::string fileName)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<IPBitacora> vect;
    std::ifstream lector(fileName);
    std::string line;
    std::smatch match;

    while (lector.good())
    {
        getline(lector, line, '\n');

        std::regex_search(line, match, std::regex("[0-9]+(?:\\.[0-9]+){3}(:[0-9]+)?"));

        vect.push_back(IPBitacora(match[0]));
    }
    lector.close();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Leemos bitácora... Completado en " << duration.count() << " microsegundos." << std::endl;

    return vect;
}