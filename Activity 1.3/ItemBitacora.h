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
#ifndef __ITEMBITACORA_H__
#define __ITEMBITACORA_H__

#include <string>
#include <iostream>

enum Mes
{
    Jan = 1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
};

class ItemBitacora
{
private:
    Mes mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    std::string ip;
    std::string razon;

    static std::string mes2Str(Mes);

public:
    friend std::ostream &operator<<(std::ostream &, const ItemBitacora &);
    friend bool operator==(const ItemBitacora &, const ItemBitacora &);
    friend bool operator<(const ItemBitacora &, const ItemBitacora &);
    friend bool operator<=(const ItemBitacora &, const ItemBitacora &);
    ItemBitacora(std::string, int, int, int, int, std::string, std::string);
    ItemBitacora();
    static Mes str2Mes(std::string);
};

#endif // __ITEMBITACORA_H__