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
#include "ItemBitacora.h"
#include <vector>
#include <sstream>
#include <iomanip>

ItemBitacora::ItemBitacora(std::string mes, int dia, int hora, int minuto, int segundo, std::string ip, std::string razon)
{
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->razon = razon;

    // Separamos la IP por elemento
    std::stringstream lectorIP(ip);
    std::vector<int> separatedIP;

    while (lectorIP.good())
    {
        std::string item;

        getline(lectorIP, item, (separatedIP.size() != 3) ? '.' : ':');

        separatedIP.push_back(stoi(item));
    }

    this->ip = separatedIP;
}

ItemBitacora::ItemBitacora()
{
    this->mes = "Jan";
    this->dia = 1;
    this->hora = 0;
    this->minuto = 59;
    this->segundo = 59;
    this->ip = {};
    this->razon = "No data";
}

bool operator==(const ItemBitacora &x, const ItemBitacora &y)
{
    return (x.mes == y.mes) && (x.dia == y.dia) && (x.hora == y.hora) && (x.minuto == y.minuto) && (x.segundo == y.segundo) && (x.ip == y.ip) && (x.razon == y.razon);
}

bool operator<=(const ItemBitacora &x, const ItemBitacora &y)
{
    if (x.ip[0] != y.ip[0])
    {

        return (x.ip[0] < y.ip[0]);
    }
    else
    {

        if (x.ip[1] != y.ip[1])
        {
            return (x.ip[1] < y.ip[1]);
        }
        else
        {

            if (x.ip[2] != y.ip[2])
            {
                return (x.ip[2] < y.ip[2]);
            }
            else
            {

                if (x.ip[3] != y.ip[3])
                {
                    return (x.ip[3] < y.ip[3]);
                }
                else
                {
                    if (x.ip[4] != y.ip[4])
                    {
                        return (x.ip[4] < y.ip[4]);
                    }
                    return true;
                }
            }
        }
    }
}

bool operator<(const ItemBitacora &x, const ItemBitacora &y)
{

    if (x.ip[0] != y.ip[0])
    {

        return (x.ip[0] < y.ip[0]);
    }
    else
    {

        if (x.ip[1] != y.ip[1])
        {
            return (x.ip[1] < y.ip[1]);
        }
        else
        {

            if (x.ip[2] != y.ip[2])
            {
                return (x.ip[2] < y.ip[2]);
            }
            else
            {

                if (x.ip[3] != y.ip[3])
                {
                    return (x.ip[3] < y.ip[3]);
                }
                else
                {

                    return (x.ip[4] < y.ip[4]);
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const ItemBitacora &item)
{
    os << item.mes
       << " " << item.dia << " " << std::setw(2) << std::setfill('0') << item.hora << ":" << std::setw(2) << std::setfill('0') << item.minuto << ":" << std::setw(2) << std::setfill('0') << item.segundo << " " << item.ip[0] << "." << item.ip[1] << "." << item.ip[2] << "." << item.ip[3] << ":" << item.ip[4] << " " << item.razon;
    return os;
}
