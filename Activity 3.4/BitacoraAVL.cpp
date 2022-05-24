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
#include "BitacoraAVL.h"

BitacoraAVL::BitacoraAVL(std::string fileName)
{
    std::vector<IPBitacora> vect = Helper::leeBitacora(fileName);

    auto start = std::chrono::high_resolution_clock::now();

    Helper::ordenaMerge(vect);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Ordenamos la bitácora... Completado en " << duration.count() << " microsegundos." << std::endl;

    Helper::removeDuplicates(vect);

    start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < vect.size() - 1; i++)
    {
        this->root = IPNode::insert(this->root, IPBitacora(vect[i]));
    }
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Creamos árbol AVL... Completado en " << duration.count() << " microsegundos." << std::endl;
}

void BitacoraAVL::imprimir()
{
    inorder(this->root, 5);
}

void BitacoraAVL::inorder(IPNode *node, int n)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::stack<IPNode *> s;
    IPNode *curr = root;

    while ((curr != NULL || s.empty() == false) && (n > 0))
    {

        while (curr != NULL)
        {

            s.push(curr);
            curr = curr->right;
        }

        curr = s.top();
        s.pop();

        std::cout << curr->ip << std::endl;

        curr = curr->left;
        n--;
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Buscamos las 5 IP's  con más accesos... Completado en " << duration.count() << " microsegundos." << std::endl;
}
