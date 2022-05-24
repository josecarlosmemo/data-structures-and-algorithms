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
#include "IPNode.h"

IPNode::IPNode(IPBitacora ip)
{
    this->ip = ip;
    this->left = NULL;
    this->right = NULL;
    this->height = 1;
}
int IPNode::max(int a, int b)
{
    return (a > b) ? a : b;
}

IPNode *IPNode::insert(IPNode *node, IPBitacora newItem)
{
    if (node == NULL)
        return (new IPNode(newItem));
    if (newItem.getAccesos() < node->ip.getAccesos())
        node->left = insert(node->left, newItem);
    else if (newItem.getAccesos() > node->ip.getAccesos())
        node->right = insert(node->right, newItem);
    else
        return node;

    node->height = 1 + max(calculateHeight(node->left),
                           calculateHeight(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (newItem.getAccesos() < node->left->ip.getAccesos())
        {
            return rightRotate(node);
        }
        else if (newItem.getAccesos() > node->left->ip.getAccesos())
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (newItem.getAccesos() > node->right->ip.getAccesos())
        {
            return leftRotate(node);
        }
        else if (newItem.getAccesos() < node->right->ip.getAccesos())
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

int IPNode::calculateHeight(IPNode *node)
{
    if (!node)
        return 0;
    return node->height;
}

IPNode *IPNode::rightRotate(IPNode *y)
{
    IPNode *x = y->left;
    IPNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(calculateHeight(y->left),
                    calculateHeight(y->right)) +
                1;
    x->height = max(calculateHeight(x->left),
                    calculateHeight(x->right)) +
                1;
    return x;
}

IPNode *IPNode::leftRotate(IPNode *x)
{

    IPNode *y = x->right;
    IPNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(calculateHeight(x->left),
                    calculateHeight(x->right)) +
                1;
    y->height = max(calculateHeight(y->left),
                    calculateHeight(y->right)) +
                1;
    return y;
}

int IPNode::getBalanceFactor(IPNode *node)
{
    if (!node)
        return 0;
    return calculateHeight(node->left) -
           calculateHeight(node->right);
}