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
#include "ItemBitacora.h"
#include <map>
#include <iomanip>

ItemBitacora::ItemBitacora(std::string mes, int dia, int hora, int minuto, int segundo, std::string ip, std::string razon)
{
    this->mes = str2Mes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->ip = ip;
    this->razon = razon;
}

ItemBitacora::ItemBitacora()
{
    this->mes = Jan;
    this->dia = 1;
    this->hora = 0;
    this->minuto = 59;
    this->segundo = 59;
    this->ip = "localhost";
    this->razon = "No data";
}

Mes ItemBitacora::str2Mes(std::string mes)
{
    std::map<std::string, Mes> map = {
        std::pair<std::string, Mes>("Jan", Jan),
        std::pair<std::string, Mes>("Feb", Feb),
        std::pair<std::string, Mes>("Mar", Mar),
        std::pair<std::string, Mes>("Apr", Apr),
        std::pair<std::string, Mes>("May", May),
        std::pair<std::string, Mes>("Jun", Jun),
        std::pair<std::string, Mes>("Jul", Jul),
        std::pair<std::string, Mes>("Aug", Aug),
        std::pair<std::string, Mes>("Sep", Sep),
        std::pair<std::string, Mes>("Oct", Oct),
        std::pair<std::string, Mes>("Nov", Nov),
        std::pair<std::string, Mes>("Dec", Dec),

    };

    return map[mes];
}

std::string ItemBitacora::mes2Str(Mes mes)
{
    std::map<Mes, std::string> map = {
        std::pair<Mes, std::string>(Jan, "Jan"),
        std::pair<Mes, std::string>(Feb, "Feb"),
        std::pair<Mes, std::string>(Mar, "Mar"),
        std::pair<Mes, std::string>(Apr, "Apr"),
        std::pair<Mes, std::string>(May, "May"),
        std::pair<Mes, std::string>(Jun, "Jun"),
        std::pair<Mes, std::string>(Jul, "Jul"),
        std::pair<Mes, std::string>(Aug, "Aug"),
        std::pair<Mes, std::string>(Sep, "Sep"),
        std::pair<Mes, std::string>(Oct, "Oct"),
        std::pair<Mes, std::string>(Nov, "Nov"),
        std::pair<Mes, std::string>(Dec, "Dec"),

    };
    return map[mes];
}

bool operator==(const ItemBitacora &x, const ItemBitacora &y)
{
    return (x.mes == y.mes) && (x.dia == y.dia) && (x.hora == y.hora) && (x.minuto == y.minuto) && (x.segundo == y.segundo) && (x.ip == y.ip) && (x.razon == y.razon);
}

bool operator<=(const ItemBitacora &x, const ItemBitacora &y)
{
    if (x.mes != y.mes)
    {

        return (x.mes < y.mes);
    }
    else
    {

        if (x.dia != y.dia)
        {
            return (x.dia < y.dia);
        }
        else
        {

            if (x.hora != y.hora)
            {
                return (x.hora < y.hora);
            }
            else
            {

                if (x.minuto != y.minuto)
                {
                    return (x.minuto < y.minuto);
                }
                else
                {
                    if (x.segundo != y.segundo)
                    {
                        return (x.segundo < y.segundo);
                    }
                    return true;
                }
            }
        }
    }
}

bool operator<(const ItemBitacora &x, const ItemBitacora &y)
{

    if (x.mes != y.mes)
    {

        return (x.mes < y.mes);
    }
    else
    {

        if (x.dia != y.dia)
        {
            return (x.dia < y.dia);
        }
        else
        {

            if (x.hora != y.hora)
            {
                return (x.hora < y.hora);
            }
            else
            {

                if (x.minuto != y.minuto)
                {
                    return (x.minuto < y.minuto);
                }
                else
                {

                    return (x.segundo < y.segundo);
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const ItemBitacora &item)
{
    os << ItemBitacora::mes2Str(item.mes)
       << " " << item.dia << " " << std::setw(2) << std::setfill('0') << item.hora << ":" << std::setw(2) << std::setfill('0') << item.minuto << ":" << std::setw(2) << std::setfill('0') << item.segundo << " " << item.ip << " " << item.razon;
    return os;
}
