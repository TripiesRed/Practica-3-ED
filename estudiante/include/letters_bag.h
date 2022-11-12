#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"
#include "../src/letters_set.cpp"

using namespace std;

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag{

private:
    Bag <char> letters;

public:

    LettersBag();

    LettersBag(const LettersSet & letterSet);

    void insertLetter(const char & l);

    char extractLetter();

    vector<char> extractLetters(int num);

    void clear();

    void size();

    LettersBag & operator= (const LettersBag & other);

};

#endif
