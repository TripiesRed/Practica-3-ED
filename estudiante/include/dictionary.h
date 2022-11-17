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

     vector<string> wordsOfLength (int length);

     friend ostream & operator<<(ostream &os, const Dictionary &dic);

     friend istream & operator>>(istream &is, Dictionary &dic);

     class iterator {

     private:
         set<string>::const_iterator it; //Iterador constante

     public:

     };

 };

#endif
