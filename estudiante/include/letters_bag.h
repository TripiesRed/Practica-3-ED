/**
 * @file letters_bag.h
 * @brief  Archivo de especificación del TDA LettersBag
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */

#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__

#include "bag.h"
#include "letters_set.h"


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

    /**
     * @brief Constructor por defecto.
     * @posr Crea una bolsa vacía.
     */
    LettersBag() = default;

    /**
     * @brief Constructor de copia.
     * @param letterSet Objeto LettersBag que se va a copiar.
     */
    LettersBag( LettersSet & letterSet);

    /**
     * @brief Inserta una letra en la bolsa.
     * @param l Letra que se inserta.
     * @post El tamaño de la bolsa aumenta.
     */
    void insertLetter(const char & l);

    /**
     * @brief Extrae y elimina una letra de la bolsa.
     * @return Letra extraída.
     * @post La letra extraída se elimina de la bolsa.
     */
    char extractLetter();

    /**
     * @brief Extrae y elimina un cierto número de letras.
     * @param num Número de letras que se extraen.
     * @return Vector de letras extraídas.
     * @post Las letras extraídas se eliminan de la bolsa.
     */
    vector<char> extractLetters(int num);

    /**
     * @brief Elimina todas las letras de la bolsa.
     * @post La bolsa queda vacía.
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa.
     * @return Devuleve el número de letras de la bolsa.
     */
    unsigned int size() const;

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param other Objeto LettersBag que se copia.
     * @return Referencia a this, de manera que el operador se puede encadenar.
     */
    LettersBag & operator= (const LettersBag & other);

};

#endif
