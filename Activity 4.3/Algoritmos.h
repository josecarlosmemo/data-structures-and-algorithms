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
#pragma once
#include <vector>
#include <iostream>
#include "IpAddress.h"

class Algoritmos
{
public:
  static void ordenaMerge(std::vector<IpAddress> &);
  static int busqBinaria(std::vector<IpAddress>, IpAddress);

private:
  static void merge(std::vector<IpAddress> &, std::vector<IpAddress> &, std::vector<IpAddress> &);
};
