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

void Algoritmos::ordenaMerge(std::vector<IpAddress> &vect) //! O(n log n)
{

	if (vect.size() > 1)
	{

		int mid = vect.size() / 2;

		std::vector<IpAddress> firstHalf(vect.begin(), vect.begin() + mid);
		std::vector<IpAddress> secondHalf(vect.begin() + mid, vect.end());

		ordenaMerge(firstHalf);

		ordenaMerge(secondHalf);

		merge(firstHalf, secondHalf, vect); // O(n)
	}
}

int Algoritmos::busqBinaria(std::vector<IpAddress> vect, IpAddress n) //! O(log n)
{
	int center, low;
	low = 0;
	int alto = (int)vect.size() - 1;
	IpAddress centerValue;
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
void Algoritmos::merge(std::vector<IpAddress> &left, std::vector<IpAddress> &right, std::vector<IpAddress> &vect)
{
	std::vector<IpAddress>::iterator v = vect.begin();
	std::vector<IpAddress>::iterator l = left.begin();
	std::vector<IpAddress>::iterator r = right.begin();

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
