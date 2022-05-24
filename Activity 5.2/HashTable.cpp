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
#include "HashTable.h"

HashTable::HashTable(std::string fileName)
{
    std::vector<IPBitacora> vect = Helper::leeBitacora(fileName);

    this->table = new std::vector<IPBitacora>[999];

    for (int i = 0; i < vect.size() - 1; i++)
    {
        this->insert(vect[i]);
    }
}

int HashTable::getKey(int valor)
{
    return valor % total_elements;
}

void HashTable::insert(IPBitacora ip)
{
    table[getKey(ip[0])].push_back(ip);
}

void HashTable::imprimir(int dominio)
{

    conexiones = 0;
    std::cout << "Dominio " << dominio << ": " << std::endl;
    for (auto j : table[dominio])
    {
        std::cout << j << " => ";
        conexiones++;
    }

    std::cout << std::endl;
    std::cout << "Numero de Conexiones: " << conexiones << std::endl;
}