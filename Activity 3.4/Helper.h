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
#ifndef __HELPER_H__
#define __HELPER_H__
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <chrono>
#include <iostream>
#include "IPBitacora.h"

class Helper
{
private:
    static void merge(std::vector<IPBitacora> &, std::vector<IPBitacora> &, std::vector<IPBitacora> &);

public:
    static void ordenaMerge(std::vector<IPBitacora> &);
    static void removeDuplicates(std::vector<IPBitacora> &);
    static void swap(IPBitacora *, IPBitacora *);
    static std::vector<IPBitacora> leeBitacora(std::string);
};

#endif // __HELPER_H__