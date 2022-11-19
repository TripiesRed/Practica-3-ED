/**
 * @file letters_set.cpp
 * @brief  Archivo de implementación del TDA LettersSet
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#include <letters_set.h>
#include <iostream>

using namespace std;

/****************************************
        FUNCIONES PÚBLICAS
*****************************************/

//Constructor de copia
LettersSet::LettersSet(const LettersSet &other) {
    letras = other.letras;
}

//Añade un nuevo elemento al contenedor
bool LettersSet::insert(const pair<char, LetterInfo> &val) {
    bool correcto = true;

    if (empty() || !find(val.first))
        letras.insert(val);

    else correcto = false;

    return correcto;
}

//Elimina el elemento del contenedor
bool LettersSet::erase(const char &key) {
    return letras.erase(key);
}

//Borra todos los elementos del contenedor
void LettersSet::clear() {
    letras.clear();
}

//Indica si el contenedor está vacío
bool LettersSet::empty() const {
    return letras.empty();
}

//Devuelve el tamaño del contenedor
unsigned int LettersSet::size() const {
    return letras.size();
}

//Calcula el valor total de una palabra
int LettersSet::getScore (string word){
    int tam = word.size(), total=0;
    for(int i=0; i<tam; i++)
        total += letras[_toupper(word.at(i))].score;

    return total;
}

//Busca un elemento en el contenedor
bool LettersSet::find(const char &key) {
    bool found = false;
    LettersSet::iterator it;

    it = letras.find(toupper(key));
    if(it != end()) found = true;

    return found;
}

//Operador de copia
LettersSet & LettersSet::operator=(const LettersSet &cl) {
    letras = cl.letras;
    return *this;
}

//Operador de consulta
LetterInfo & LettersSet::operator[](const char &val){
    return letras[val];
}

//Operador de salida
ostream & operator<<(ostream &os, const LettersSet &cl){
    string header = "Letra Cantidad Puntos";
    os << header << endl;

    int i=0;
    LettersSet copy = cl;
    char key= 'A';
    while(i<cl.size()){
        const LetterInfo letra = copy[key];
        os << key << "\t" << letra.repeticiones << "\t" << letra.score << endl;
        i++;
        key++;
        while(!copy.find(key))key++;

    }

    return os;
}

//Operador de entrada
istream & operator>>(istream &is, LettersSet &cl){
    string header;
    is >> header >> header >> header;

    int i=0;
    char key;
    while(is.peek() != EOF){
        is >> key;
        is >> cl[key].repeticiones >> cl[key].score;
        i++;
    }

    return is;
}




