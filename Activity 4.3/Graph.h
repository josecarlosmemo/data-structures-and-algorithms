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
#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <vector>
#include <fstream>
#include <regex>
#include <queue>

#include "IpAddress.h"
#include "Algoritmos.h"

class Graph
{
private:
    std::vector<std::vector<IpAddress>> listaAdj;

public:
    Graph(std::string);
    void BFS(int, std::vector<bool> &);
};

#endif // __GRAPH_H__