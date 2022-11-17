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

    for (int i = 0; i < val.length(); ++i)
        while(it->at(i) != val.at(i)) it++;
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

//Calcula el valor total de una palabra
int Dictionary::getOccurrences(const char c){
    int total=0;
    return total;
}

int Dictionary::getTotalLetters(){

}

vector<string> Dictionary::wordsOfLength (int length){

}



