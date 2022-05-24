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
#include "Bitacora.h"
#include "Algoritmos.h"
#include <fstream>
#include <iostream>
#include <vector>

Bitacora::Bitacora(std::string fileName)
{
    std::ifstream lector(fileName);
    std::string mes, dia, hora, minuto, segundo, ip, razon;

    while (lector.good())
    {
        getline(lector, mes, ' ');
        getline(lector, dia, ' ');
        getline(lector, hora, ':');
        getline(lector, minuto, ':');
        getline(lector, segundo, ' ');
        getline(lector, ip, ' ');

        getline(lector, razon, '\n');

        this->bitacora.push_back(ItemBitacora(
            mes,
            stoi(dia),
            stoi(hora),
            stoi(minuto),
            stoi(segundo),
            ip,
            razon));
    }
    lector.close();
    ordenaBitacora();
}

std::vector<ItemBitacora> Bitacora::busqueda(ItemBitacora inicio, ItemBitacora final)
{
    std::vector<ItemBitacora> resultadosBusqueda;

    // Agregamos elementos a la bítacora
    this->bitacora.push_back(inicio);
    this->bitacora.push_back(final);
    // Ordenamos la bítacora
    ordenaBitacora();
    // Buscamos por el inicio y el final
    int posInicio = Algoritmos::busqBinaria(this->bitacora, inicio);
    int posFinal = Algoritmos::busqBinaria(this->bitacora, final);

    // Validamos los rangos
    if (posInicio > posFinal)
    {
        throw "Rango de IP's inválido.";
    }

    resultadosBusqueda = std::vector<ItemBitacora>(this->bitacora.begin() + posInicio + 1, this->bitacora.begin() + posFinal);

    // Borramos los elementos temporales de la bítacora
    this->bitacora.erase(this->bitacora.begin() + posInicio);
    this->bitacora.erase(this->bitacora.begin() + posFinal - 1);

    return resultadosBusqueda;
}

void Bitacora::exportar(std::vector<ItemBitacora> x, std::string filename)
{
    std::ofstream escribe;

    escribe.open(filename);

    for (int i = (int)x.size() - 1; i >= 0; i--)
    {
        std::cout << x[i] << std::endl;
        escribe << x[i] << std::endl;
    }

    escribe.close();
}

int Bitacora::getSize()
{
    return (int)this->bitacora.size();
}

void Bitacora::ordenaBitacora()
{
    Algoritmos::ordenaMerge(this->bitacora);
}
