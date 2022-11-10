#ifndef __BAG_H__
#define __BAG_H__

#include <iostream>
#include <vector>
#include <algorithm>

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

    Bag(const Bag<T> &other);

    void add(const T & element);

    T get();

    void clear();

    unsigned int size() const;

    bool empty();

    const Bag<T>& operator= (const Bag<T> & other);

};

template<class T> Bag<T>::Bag(const Bag<T> &other) {
    v = other.v;
};

template<class T>void Bag<T>::add (const T & element) {
    v.push_back(element);
};

template<class T>T Bag<T>::get(){
    int random = rand() % v.size();
    T element = v[random];
    v.erase(v.begin()+random);
    return element;
};

template<class T>void Bag<T>::clear(){
    v.clear();
};

template<class T>unsigned int Bag<T>::size() const{
    return v.size();
};

template<class T>bool Bag<T>::empty() {
    return v.empty();
};

template<class T>const Bag<T>& Bag<T>::operator= (const Bag<T> & other){
    v = other.v;
};


#endif