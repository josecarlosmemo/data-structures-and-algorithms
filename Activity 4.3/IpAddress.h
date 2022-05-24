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
#ifndef __IPADDRESS_H__
#define __IPADDRESS_H__

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

class IpAddress
{
private:
    int ip; // Primer sección de la IP
    int n;  // Veces que  se repite

public:
    IpAddress(std::string);
    IpAddress();
    friend std::ostream &operator<<(std::ostream &, const IpAddress &);
    friend bool operator==(const IpAddress &, const IpAddress &);
    friend bool operator<(const IpAddress &, const IpAddress &);
    friend bool operator<=(const IpAddress &, const IpAddress &);
    IpAddress &operator++(int);
    int getIP();
    int getN();
};

#endif // __IPADDRESS_H__