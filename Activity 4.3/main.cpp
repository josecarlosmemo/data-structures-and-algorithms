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
#include "Graph.h"

int main(int argc, char const *argv[])
{
    Graph bit = Graph("bitacora.txt");

    std::vector<bool> discoveredB(999, false);

    std::cout << std::endl
              << "---   BFS   ---" << std::endl;

    for (int i = 0; i < 99; i++)
    {
        if (discoveredB[i] == false)
        {
            bit.BFS(i, discoveredB);
        }
    }
    std::cout << std::endl;

    return 0;
}