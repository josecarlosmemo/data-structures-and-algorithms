#ifndef __BITACORA_H__
#define __BITACORA_H__

#include <vector>
#include <string>
#include "ItemBitacora.h"

class Bitacora
{
private:
    std::vector<ItemBitacora> bitacora;
    void ordenaBitacora();

public:
    Bitacora(std::string);
    std::vector<ItemBitacora> busqueda(ItemBitacora, ItemBitacora);
    static void exportarBitacora(std::vector<ItemBitacora>, std::string);
    int getSize();
};

#endif // __BITACORA_H__