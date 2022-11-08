#ifndef __BAG_H__
#define __BAG_H__

#include <iostream>
#include <vector>

using namespace std;

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 *
 */

template <class T>
class Bag {

private:
    vector<T> v;

public:
    Bag() = default;

    Bag(const Bag<T> &other) {};


};

#endif