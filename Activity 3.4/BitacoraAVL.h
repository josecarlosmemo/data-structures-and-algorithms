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
#ifndef __BSTSTANDARDBITACORA_H__
#define __BITACORAAVL_H__
#include "IPNode.h"
#include "Helper.h"
#include <string>
#include <stack>

class BitacoraAVL
{
private:
    void inorder(IPNode *, int);

public:
    IPNode *root;

    BitacoraAVL(std::string);
    friend std::ostream &operator<<(std::ostream &, const BitacoraAVL &);
    void imprimir();
};

#endif // __BITACORAAVL_H__