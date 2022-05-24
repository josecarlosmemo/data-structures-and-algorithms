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
#ifndef __ITEMBITACORA_H__
#define __ITEMBITACORA_H__

#include <string>
#include <iostream>
#include <vector>

class ItemBitacora
{
private:
    std::string mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    std::vector<int> ip;
    std::string razon;

public:
    ItemBitacora(std::string, int, int, int, int, std::string, std::string);
    ItemBitacora();
    friend std::ostream &operator<<(std::ostream &, const ItemBitacora &);
    friend bool operator==(const ItemBitacora &, const ItemBitacora &);
    friend bool operator<(const ItemBitacora &, const ItemBitacora &);
    friend bool operator<=(const ItemBitacora &, const ItemBitacora &);
};

#endif // __ITEMBITACORA_H__