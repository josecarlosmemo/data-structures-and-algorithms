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
#ifndef __BITACORA_H__
#define __BITACORA_H__

#include <vector>
#include <string>
#include "ItemBitacora.h"

class Bitacora
{
private:
    std::vector<ItemBitacora> bitacora;
    void ordenaBitacora();

public:
    Bitacora(std::string);
    std::vector<ItemBitacora> busqueda(ItemBitacora, ItemBitacora);
    static void exportar(std::vector<ItemBitacora>, std::string);
    int getSize();
};

#endif // __BITACORA_H__