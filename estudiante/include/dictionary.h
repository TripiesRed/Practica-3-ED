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

     /**
      * @brief Constructor por defecto
      * @post Crea un objeto Dictionary vacío
      */
     Dictionary()=default;

     /**
      * @brief Constructor de copia
      * @param other Objeto Dictionary que se copia
      */
     Dictionary(const Dictionary & other);

     /**
      * @brief Indica si una palabra está en el diccionario.
      * @param val Palabra a buscar
      * @return true si la palabra está, false en caso contario
      */
     bool existe (const string & val) const;

     /**
      * @brief Añade una palabra al diccionario
      * @param val Palabra que se añade al diccionario
      * @return Booleano que indica si la inserción ha tenido éxito, es decir, si la palabra no existía en el diccionario.
      */
     bool insert (const string & val);

     /**
      * @brief Elimina una palabra del diccionario.
      * @param val Palabra a eliminar.
      * @return Booleano que indica si la eliminación ha sido exitosa.
      */
     bool erase (const string & val);

     /**
      * @brief Elimina todas las palabras del diccionario.
      * @post EL diccionario se queda con ningún elemento.
      */
     void clear();

     /**
      * @brief Comprueba si el diccionario está vacío.
      * @return true si el diccionario está vacío, false en caso contrario.
      */
     bool empty () const;

     /**
      * @brief Tamaño del diccionario.
      * @return Número de elementos del diccionario.
      */
     unsigned int size () const;

     /**
      * @brief Indica el número de apariciones de una letra.
      * @param c Letra de la que se cuentan sus apariciones.
      * @return Número de apariciones de la letra.
      */
     int getOccurrences (const char c);

     /**
      * @brief Cuenta el total de letras de un objeto diccionario.
      * @return Número total de letras.
      */
     int getTotalLetters ();

     /**
      * @brief Devuelve las palabras con la longitud suministrada como parámetro.
      * @param length Longitud de palabra.
      * @return Vector con las palabras de longitud length.
      */
     vector<string> wordsOfLength (int length) const;

     /**
      * Sobrecarga del operador de salida.
      * @param os Flujo de salida.
      * @param dic Objeto diccionario a imprimir.
      * @return Flujo de salida para poder encadenar el operador.
      */
     friend ostream & operator<<(ostream &os, const Dictionary &dic);

     /**
      * @brief Sobrecarga del operador de entrada.
      * @param is Flujo de entrada.
      * @param dic Diccionario a rellenar.
      * @return Flujo de entrada para poder encadenar el operador.
      */
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
