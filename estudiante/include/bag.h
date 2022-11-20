/**
 * @file bag.h
 * @brief  Archivo de especificación del TDA Bag
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#ifndef __BAG_H__
#define __BAG_H__

#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>


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
    /**
     * @brief Constructor por defecto.
     * @post Genera un vector de 0 elementos.
     */
    Bag() = default;

    /**
     * @brief Constructor de copia. Crea una copia exacta de otro objeto Bag.
     * @param other Objeto que se copia.
     */
    Bag(const Bag<T> &other);

    /**
     * @brief Añade un elemento a la bolsa
     * @param element Elemento que se añade.
     * @post El tamaño del vector aumenta.
     */
    void add(const T & element);

    /**
     * @brief Extrae un elemento de forma aleatoria
     * @return Un elemento al azar.
     * @pre Bag no puede estar vacío
     * @post El elemento extraído se elimina de la bolsa
     */
    T get();

    /**
     * @brief Elimina todos los elementos de la bolsa.
     * @post La bolsda se queda vacía.
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return El número de elementos de la bolsa.
     */
    unsigned int size() const;

    /**
     * @brief Comprueba si la bolsa está vacía.
     * @return Devuelve true si la bolsa está vacía, false en caso contrario.
     */
    bool empty();

    /**
     * Sobrecarga del operador de asignación.
     * @param other Objeto Bag que se copia
     * @return Referencia a this.
     */
    const Bag<T>& operator= (const Bag<T> & other);

    void show() const;

};

template<class T> Bag<T>::Bag(const Bag<T> &other) {
    v = other.v;
};

template<class T>void Bag<T>::add (const T & element) {
    v.push_back(element);
};

template<class T>T Bag<T>::get(){
    srand(time(NULL));
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
    return *this;
};

template<class T>void Bag<T>::show () const{
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    cout << "fin" << endl;
}

#endif