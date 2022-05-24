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
#include "IPBitacora.h"

int &IPBitacora::operator[](int index)
{
    return this->separatedIP[index];
}

bool operator<(IPBitacora &x, IPBitacora &y)
{
    if (x[0] != y[0])
    {

        return (x[0] < y[0]);
    }
    else
    {

        if (x[1] != y[1])
        {
            return (x[1] < y[1]);
        }
        else
        {

            if (x[2] != y[2])
            {
                return (x[2] < y[2]);
            }
            else
            {

                if (x[3] != y[3])
                {
                    return (x[3] < y[3]);
                }
                else
                {

                    return (x[4] < y[4]);
                }
            }
        }
    }
}

bool operator==(const IPBitacora &x, const IPBitacora &y)
{
    return (x.ip == y.ip);
}

IPBitacora &IPBitacora::operator++(int)
{
    this->accesos++;
    return *this;
}

IPBitacora::IPBitacora(std::string ip)
{
    this->ip = ip;
    this->accesos = 1;

    // Separamos la IP por elemento
    std::stringstream lectorIP(this->ip);
    std::vector<int> separatedIP;

    while (lectorIP.good())
    {
        std::string item;

        getline(lectorIP, item, (separatedIP.size() != 3) ? '.' : ':');

        separatedIP.push_back(stoi(item));
    }
    this->separatedIP = separatedIP;
}

IPBitacora::IPBitacora()
{
    this->accesos = 0;
    this->ip = "";
}

int IPBitacora::getAccesos()
{
    return this->accesos;
}

bool operator<=(IPBitacora &x, IPBitacora &y)
{
    if (x[0] != y[0])
    {

        return (x[0] < y[0]);
    }
    else
    {

        if (x[1] != y[1])
        {
            return (x[1] < y[1]);
        }
        else
        {

            if (x[2] != y[2])
            {
                return (x[2] < y[2]);
            }
            else
            {

                if (x[3] != y[3])
                {
                    return (x[3] < y[3]);
                }
                else
                {
                    if (x[4] != y[4])
                    {
                        return (x[4] < y[4]);
                    }
                    return true;
                }
            }
        }
    }
}

std::ostream &operator<<(std::ostream &os, const IPBitacora &x)
{
    os << x.ip << std::endl;
    return os;
}