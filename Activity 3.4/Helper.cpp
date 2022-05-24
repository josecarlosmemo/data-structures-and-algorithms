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
#include "Helper.h"

//* Remueve duplicados de un vector<IPBitacora> combiando los duplicados en solo un elemento.

void Helper::removeDuplicates(std::vector<IPBitacora> &x)
{
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < x.size() - 1; i++)
    {

        while (x[i] == x[i + 1])
        {
            x[i]++;
            x.erase(x.begin() + (i + 1));
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Removemos duplicados... Completado en " << duration.count() << " microsegundos." << std::endl;
}
//* Cambia dos valores de cualquier tipo de lugar.

void Helper::swap(IPBitacora *x, IPBitacora *y)
{
    IPBitacora temp = *y;
    *y = *x;
    *x = temp;
}

//* Recibe el nombre del archivo a leer y regresa un vector con solamente las IP's en forma de IPBitacora

std::vector<IPBitacora> Helper::leeBitacora(std::string fileName)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<IPBitacora> vect;
    std::ifstream lector(fileName);
    std::string line;
    std::smatch match;

    while (lector.good())
    {
        getline(lector, line, '\n');

        std::regex_search(line, match, std::regex("[0-9]+(?:\\.[0-9]+){3}(:[0-9]+)?"));

        vect.push_back(IPBitacora(match[0]));
    }
    lector.close();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Leemos bitácora... Completado en " << duration.count() << " microsegundos." << std::endl;

    return vect;
}

//* Función Auxiliar para el método de ordenaMerge

void Helper::merge(std::vector<IPBitacora> &left, std::vector<IPBitacora> &right, std::vector<IPBitacora> &vect)
{
    std::vector<IPBitacora>::iterator v = vect.begin();
    std::vector<IPBitacora>::iterator l = left.begin();
    std::vector<IPBitacora>::iterator r = right.begin();

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

//* Ordena vector de cualquier tipo de dato utilizando el método mergeSort

void Helper ::ordenaMerge(std::vector<IPBitacora> &vect) //! Complpejidad: O(n log n)
{
    if (vect.size() > 1)
    {

        int mid = vect.size() / 2;

        std::vector<IPBitacora> firstHalf(vect.begin(), vect.begin() + mid);
        std::vector<IPBitacora> secondHalf(vect.begin() + mid, vect.end());

        ordenaMerge(firstHalf);

        ordenaMerge(secondHalf);

        merge(firstHalf, secondHalf, vect); // O(n)
    }
}
