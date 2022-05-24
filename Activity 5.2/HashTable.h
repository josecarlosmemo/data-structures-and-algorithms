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
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__
#include "Helper.h"
#include "IPBitacora.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class HashTable
{
private:
    std::vector<IPBitacora> *table;
    int total_elements;
    int conexiones;

public:
    int getKey(int valor);
    HashTable(std::string fileName);
    void insert(IPBitacora ip);
    void imprimir(int dominio);
};

#endif // __HASHTABLE_H__