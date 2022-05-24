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
#include "Algoritmos.h"
#include <vector>
#include <iostream>

void Algoritmos::ordenaMerge(std::vector<ItemBitacora> &vect) //! O(n log n)
{

	if (vect.size() > 1)
	{

		int mid = vect.size() / 2;

		std::vector<ItemBitacora> firstHalf(vect.begin(), vect.begin() + mid);
		std::vector<ItemBitacora> secondHalf(vect.begin() + mid, vect.end());

		ordenaMerge(firstHalf);

		ordenaMerge(secondHalf);

		merge(firstHalf, secondHalf, vect); // O(n)
	}
}

int Algoritmos::busqBinaria(std::vector<ItemBitacora> vect, ItemBitacora n) //! O(log n)
{
	int center, low;
	low = 0;
	int alto = (int)vect.size() - 1;
	ItemBitacora centerValue;
	while (low <= alto)
	{
		center = (low + alto) / 2;
		centerValue = vect[center];
		if (n == centerValue)
			return center;
		else if (n < centerValue)
			alto = center - 1;
		else
			low = center + 1;
	}
	return -1;
}

//* Función Auxiliar para el método de ordenaMerge
void Algoritmos::merge(std::vector<ItemBitacora> &left, std::vector<ItemBitacora> &right, std::vector<ItemBitacora> &vect)
{
	std::vector<ItemBitacora>::iterator v = vect.begin();
	std::vector<ItemBitacora>::iterator l = left.begin();
	std::vector<ItemBitacora>::iterator r = right.begin();

	while (v != vect.end()) // O(n)
	{
		while (l != left.end() && (r == right.end() || *l <= *r))
		{
			*v = *l;
			++l;
			++v;
		}
		while (r != right.end() && (l == left.end() || *r < *l))
		{
			*v = *r;
			++r;
			++v;
		}
	}
}
