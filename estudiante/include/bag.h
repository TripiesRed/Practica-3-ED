#ifndef __BAG_H__
#define __BAG_H__

/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

#endif

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Bag {

private:
    vector<T> v;

public:
    Bag()=default;

    Bag(const Bag<T>& other){};

    

};