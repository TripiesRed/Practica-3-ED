/**
 * @file dictionary.h
 * @brief  Archivo de especificación del TDA LettersSet
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */
 class Dictionary {

 private:
     set <string> words; //Conjunto de palabras del juego

 public:

     Dictionary()=default;

     Dictionary(const Dictionary & other);

     bool existe (const string & val) const;

     bool insert (const string & val);

     bool erase (const string & val);

     void clear();

     bool empty () const;

     unsigned int size () const;

     int getOccurrences (const char c);

     int getTotalLetters ();

     vector<string> wordsOfLength (int length) const;

     friend ostream & operator<<(ostream &os, const Dictionary &dic);

     friend istream & operator>>(istream &is, Dictionary &dic);

     /**
     * @brief TDA Dictionary::const_iterator
     *
     * Este TDA representa un 'iterador' sobre la clase LettersSet con las operaciones básicas
     * que cabría esperar del 'iterador' si se tratase de un contenedor tipo set.
     */
     class iterator {

     private:
         set<string>::const_iterator it; //Iterador constante

     public:

         /**
         * @brief Constructor por defecto.
         * @return iterator, el objeto creado.
         * @post Genera un iterator vacío.
         */
         iterator() = default;

         /**
         * @brief Constructor de copia.
         * @param other iterator a copiar.
         * @return iterator, el objeto creado.
         * @post other no se modifica.
         */
         iterator (const iterator &other){
             it = other.it;
         }

         /**
         * @brief Constructor de copia (versión 2).
         * @param other iterator a copiar.
         * @return iterator, el objeto creado.
         * @post other no se modifica.
         */
         iterator (const set<string>::const_iterator &other){
             it = other;
         }

         /**
         * @brief Sobrecarga del operador de asignación.
         * @param other iterator que se va a copiar.
         * @return Referencia al objeto this que permita encadenar el operador.
         */
         iterator & operator=(const iterator &other){
             it = other.it;
             return *this;
         }

         /**
         * @brief Sobrecarga del operador de relacional 'distinto de'.
         * @param other iterator que se va a comparar.
         * @return Booleano que marca true en caso de ser iteradores distintos,
         *  false en caso contrario.
         */
         bool operator!=(const iterator &other){
             bool distintos = this->it!=other.it ? true : false;
             return distintos;
         }

         /**
         * @brief Sobrecarga del operador de relacional de igualdad.
         * @param other iterator que se va a comparar.
         * @return Booleano que marca true en caso de ser iteradores iguales,
         *  false en caso contrario.
         */
         bool operator==(const iterator &other){
             bool iguales = this->it==other.it ? true : false;
             return iguales;
         }

         /**
         * @brief Sobrecarga del operador (pre) incremento.
         * @return Referencia al objeto this.
         */
         iterator &operator++(){
             ++it;
             return *this;
         }

         /**
         * @brief Sobrecarga del operador (pre) decremento.
         * @return Referencia al objeto this.
         */
         iterator &operator--(){
             --it;
             return *this;
         }

         /**
         * @brief Sobrecarga del operador (pos) incremento.
         * @return Referencia al objeto this.
         */
         iterator &operator++(int n){
             it++;
             return *this;
         }

         /**
         * @brief Sobrecarga del operador (pos) decremento.
         * @return Referencia al objeto this.
         */
         iterator &operator--(int n){
             it--;
             return *this;
         }

         /**
         * @brief Sobrecarga del operador de indirección.
         * @return Referencia al objeto apuntado por el dato privado it.
         */
        const string &operator*() const{
             return *it;
         }

     };

     /**
     * @brief Devuelve un iterador que apunta a la primera posición de la estructura.
     * @return Objeto del tipo iterator de la clase Dictionary.
     */
     iterator begin() const{
         iterator it = words.begin();
         return it;
     }

     /**
     * @brief Devuelve un iterador que apunta a la primera posición de la estructura.
     * @return Objeto del tipo iterator de la clase Dictionary.
     */
     iterator end() const{
         iterator it = words.end();
         return it;
     }
 };

#endif
