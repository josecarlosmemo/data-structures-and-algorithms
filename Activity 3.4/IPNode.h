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
#ifndef __IPNODE_H__
#define __IPNODE_H__
#include "IPBitacora.h"
#include <algorithm>

class IPNode
{
private:
    static int calculateHeight(IPNode *);
    static IPNode *rightRotate(IPNode *);
    static IPNode *leftRotate(IPNode *);
    static int getBalanceFactor(IPNode *);
    static int max(int, int);

public:
    IPBitacora ip;
    IPNode *left;
    IPNode *right;
    int height;

    IPNode(IPBitacora);
    static IPNode *insert(IPNode *, IPBitacora);
};

#endif // __IPNODE_H__