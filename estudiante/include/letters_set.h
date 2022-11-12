#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__

#include <iostream>
#include <map>

using namespace std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */
struct LetterInfo {
    int repeticiones;
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
class LettersSet{

private:
    map <char, LetterInfo> letras;

public:

    LettersSet()=default;

    LettersSet(const LettersSet &other);

    bool insert (const pair<char, LetterInfo> &val);

    bool erase (const char &key);

    void clear();

    bool empty() const;

    unsigned int size () const;

    int getScore (string word);

    bool find (const char &key);

    LettersSet & operator=(const LettersSet &cl);

    LetterInfo & operator[](const char &val);

    friend ostream & operator<<(ostream &os, const LettersSet &cl);

    friend istream & operator>>(istream &is, LettersSet &cl);


    class iterator{

    private:
        map<char, LetterInfo>::const_iterator it;

    public:
        iterator() = default;

        iterator (const iterator &other){
            it = other.it;
        }

        iterator & operator=(const map<char, LetterInfo>::const_iterator &other){
            it = other;
            return *this;
        }

        bool operator!=(const map<char, LetterInfo>::const_iterator &other){
            bool iguales = this->it!=other ? true : false;
            return iguales;
        }

        bool operator==(const map<char, LetterInfo>::const_iterator &other){
            bool iguales = this->it!=other ? true : false;
            return iguales;
        }

    };

};


#endif

