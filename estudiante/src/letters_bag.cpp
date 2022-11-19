/**
 * @file letters_bag.cpp
 * @brief  Archivo de implementación del TDA LettersBag
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#include "letters_bag.h"

using namespace std;

/****************************************
        FUNCIONES PÚBLICAS
*****************************************/

LettersBag::LettersBag( LettersSet & letterSet) {

    for(char cont = 'A'; cont <= 'Z'; cont++){
        if(letterSet.find(cont)){
            for(int i = 0; i < letterSet[cont].repeticiones; i++){
                letters.add(cont);
            }
        }
    }
}

void LettersBag::insertLetter(const char &l) {

    letters.add(l);

}

char LettersBag::extractLetter() {

    char letra = letters.get();
    return letra;
}

vector<char> LettersBag::extractLetters(int num) {

    vector<char> letras;
    for(int i = 0; i < num; i++){
        letras.push_back(extractLetter());
    }
    return letras;
}

void LettersBag::clear() {

    letters.clear();
}

unsigned int LettersBag::size() const{

    return letters.size();
}

LettersBag& LettersBag::operator=(const LettersBag &other) {
    letters = other.letters;
    return *this;
}