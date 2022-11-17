/**
 * @file dictionary.cpp
 * @brief  Archivo de especificación del TDA LettersSet
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#include "dictionary.h"
#include <iostream>

using namespace std;

/****************************************
        FUNCIONES PÚBLICAS
*****************************************/

//Constructor de copia
Dictionary::Dictionary(const Dictionary &other) {
    words = other.words;
}

//Comprueba si el elemento ya está en el conjunto
bool Dictionary::existe (const string & val) const{
    set<string>::iterator it = words.begin();
    bool encontrada = false;

    for (int i = 0; i < val.length(); ++i)
        while( (it->at(i) != val.at(i)) && (it->at(i) <= val.at(i)) ) it++;

    if (*it == val) encontrada = true;

    return encontrada;
}

//Añade un nuevo elemento al contenedor
bool Dictionary::insert(const string &val) {
    bool correcto = true;

    if (empty() || !existe(val))
        words.insert(val);

    else correcto = false;

    return correcto;
}

//Elimina el elemento del contenedor
bool Dictionary::erase(const string &val) {
    return words.erase(val);
}

//Borra todos los elementos del contenedor
void Dictionary::clear() {
    words.clear();
}

//Indica si el contenedor está vacío
bool Dictionary::empty() const {
    return words.empty();
}

//Devuelve el tamaño del contenedor
unsigned int Dictionary::size() const {
    return words.size();
}

//Calcula el número total de apariciones de un carácter en el diccionario
int Dictionary::getOccurrences(const char c){
    int total=0;

    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
        if(it->find(c) != string::npos)//Comprobamos si la palabra tiene el carácter c
            for(int i = 0; i < it->length(); i++) //Recorremos la palabra
                if(it->at(i) == c) //Contamos cuantas veces tiene la palabra el carácter c
                    total++;


    return total;
}

//Calcula el total de letras que hay en el diccionario
int Dictionary::getTotalLetters(){
    int total = 0;
    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
        total += it->length();

    return total;
}

//Crea un vector con todas las palabras con la longitud dada
vector<string> Dictionary::wordsOfLength (int length){
    vector<string> v;
    set<string>::iterator it = words.begin();

    while(it!=words.end()){
        if(it->length() == length) v.push_back(*it);
        it++;
    }

    return v;
}



