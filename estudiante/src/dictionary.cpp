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
    //Tomamos las palabras de igual longitud que val
    vector<string> v = wordsOfLength(val.length());
    vector<string>::iterator it = v.begin();
    bool existe = false;

    if(!empty() && !v.empty()) { //Condiciones para empezar a buscar
        bool sigue = true;
        for (int i = 0; i < val.length() && (sigue); i++){

            //Buscamos primera ocurrencia de los caracteres de val en el vector
            while( (it!=v.end()) && (it->at(i) != val.at(i)) )
                it++;

            //Condiciones para detener la búsqueda antes de tiempo:
            if((it == v.end()) || (it->at(i) > val.at(i)) )
                sigue=false;
        }

        //Si no hemos detenido la búsqueda entonces val existe
        if (sigue && *it==val) existe = true;
    }

    return existe;
}

//Añade un nuevo elemento al contenedor de forma ordenada
bool Dictionary::insert(const string &val) {
   pair<iterator, bool> correcto = words.insert(val);
    return correcto.second;
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
    string word;
    for (Dictionary::iterator it = begin(); it != end(); it++){
        word = *it;
        if(word.find(tolower(c)) != string::npos)//Comprobamos si la palabra tiene el carácter c
            for(int i = 0; i < word.length(); i++) //Recorremos la palabra
                if(word.at(i) == tolower(c)) //Contamos cuantas veces tiene la palabra el carácter c
                    total++;
    }


    return total;
}

//Calcula el total de letras que hay en el diccionario
int Dictionary::getTotalLetters(){
    int total = 0;
    string word;
    for (Dictionary::iterator it = begin(); it != end(); it++){
        word = *it;
        total += word.length();
    }

    return total;
}

//Crea un vector con todas las palabras con la longitud dada
vector<string> Dictionary::wordsOfLength (int length) const {
    vector<string> v;
    Dictionary::iterator it = begin();
    string word;

    while(it!=end()){
        word = *it;
        if(word.length() == length) v.push_back(*it);
        it++;
    }

    return v;
}

//Operador de salida
ostream & operator<<(ostream &os, const Dictionary &cl){
    Dictionary::iterator it = cl.begin();
    string word;

    while(it!=cl.end()){
        os << *it << endl;
        it++;
    }

    return os;
}

//Operador de entrada
istream & operator>>(istream &is, Dictionary &cl){
    string word;
    int i=0;

    while(is.peek() != EOF){
        is >> word;
        cl.insert(word);
        i++;
    }

    return is;
}



