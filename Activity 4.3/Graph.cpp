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
Graph::Graph(std::string fileName)
{
    std::vector<IpAddress> bitacora;
    std::vector<int> rep;

    //! Leemos archivo
    std::ifstream lector(fileName);
    std::string line;
    std::smatch match;

    while (lector.good())
    {
        getline(lector, line, '\n');
        std::regex_search(line, match, std::regex("[0-9]+(?:\\.[0-9]+){3}(:[0-9]+)?"));
        bitacora.push_back(IpAddress(match[0]));
    }
    lector.close();

    //! Ordenamos bitacora
    Algoritmos::ordenaMerge(bitacora);

    //! Quitamos duplicados y contamos repeticiones

    for (int i = 0; i < bitacora.size() - 1; i++)
    {

        while (bitacora[i] == bitacora[i + 1])
        {
            if (i != bitacora.size() - 1)
            {
                bitacora[i]++;

                bitacora.erase(bitacora.begin() + (i + 1));
            }
            else
            {
                break;
            }
        }
        rep.push_back(bitacora[i].getN());
    }

    //! Creamos Lista  de adyacencia

    this->listaAdj.resize(bitacora.size() + 1);

    for (int i = 1; i < 99; i++)
    {
        listaAdj[bitacora[0].getIP()].push_back(bitacora[i]);
        listaAdj[bitacora[i].getIP()].push_back(bitacora[0]);
    }

    int srcIndex = 9;
    int destIndex = 100;

    while (srcIndex < 99)
    {
        for (int i = -1; i < 99; i++)
        {
            listaAdj[bitacora[srcIndex].getIP()].push_back(bitacora[i + destIndex]);
            listaAdj[bitacora[i + destIndex].getIP()].push_back(bitacora[srcIndex]);
        }
        srcIndex += 10;
        destIndex += 100;
    }
    //! Imprimir repeticiones de cada nodo

    for (int i = 0; i < bitacora.size() - 1; i++)
    {
        std::cout << bitacora[i];
    }
    std::cout << std::endl
              << "Elemento con más  repeticiones: " << std::endl;
    std::cout << bitacora[std::distance(rep.begin(), std::max_element(rep.begin(), rep.end()))];
}

void Graph::BFS(int i, std::vector<bool> &visited)
{
    std::queue<int> q;

    visited[i] = true;

    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();
        std::cout << i << " ";

        for (auto u : this->listaAdj[i])
            if (!visited[u.getIP()])
            {
                visited[u.getIP()] = true;
                q.push(u.getIP());
            }
    }
}
