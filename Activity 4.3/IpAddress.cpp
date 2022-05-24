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
#include "IpAddress.h"

IpAddress::IpAddress(std::string ip)
{

    std::stringstream lectorIP(ip);
    std::string item;

    getline(lectorIP, item, '.');

    this->ip = stoi(item);
    this->n = 1;
}

IpAddress::IpAddress()
{
    this->ip = 0;
    this->n = 0;
}

bool operator==(const IpAddress &x, const IpAddress &y)
{
    return (x.ip == y.ip);
}

IpAddress &IpAddress::operator++(int)
{
    this->n++;
    return *this;
}

int IpAddress::getIP()
{
    return this->ip;
}

bool operator<=(const IpAddress &x, const IpAddress &y)
{

    return x.ip <= y.ip;
}

bool operator<(const IpAddress &x, const IpAddress &y)
{
    return x.ip < y.ip;
}

int IpAddress::getN()
{
    return this->n;
}

std::ostream &operator<<(std::ostream &os, const IpAddress &item)
{
    os << "Inicio de IP: " << item.ip << " "
       << "Repeticiones: " << item.n << std::endl;
    return os;
}
