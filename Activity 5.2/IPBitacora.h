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
#ifndef __IPBITACORA_H__
#define __IPBITACORA_H__
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class IPBitacora
{
private:
    std::string ip;
    int accesos;
    std::vector<int> separatedIP;

public:
    IPBitacora(std::string);
    IPBitacora();
    int getAccesos();
    friend bool operator<(IPBitacora &, IPBitacora &);
    friend bool operator<=(IPBitacora &, IPBitacora &);
    friend bool operator==(const IPBitacora &, const IPBitacora &);
    IPBitacora &operator++(int);
    friend std::ostream &operator<<(std::ostream &, const IPBitacora &);
    int &operator[](int);
};

#endif // __IPBITACORA_H__