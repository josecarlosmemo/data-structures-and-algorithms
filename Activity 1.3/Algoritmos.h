#pragma once
#include <vector>
#include "ItemBitacora.h"

class Algoritmos
{
public:
	static void ordenaMerge(std::vector<ItemBitacora> &);
	static int busqBinaria(std::vector<ItemBitacora>, ItemBitacora);

private:
	static void merge(std::vector<ItemBitacora> &, std::vector<ItemBitacora> &, std::vector<ItemBitacora> &);
};
