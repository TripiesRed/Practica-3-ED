/**
 * @file letters_set.h
 * @brief  Archivo de especificación del TDA LettersSet
 * @author Gonzalo Martínez Piédrola & Diego Ortega Sánchez
 */


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
    int repeticiones; //Total de apariciones de una letra
    int score;        //Puntuación de una letra
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra.
 */
class LettersSet{

private:
    map <char, LetterInfo> letras; //Conjunto de letras del juego

public:

    /**
     * @brief Constructor por defecto.
     * @return LettersSet, el objeto creado.
     * @post Genera un map con 0 elementos.
     */
    LettersSet()=default;

    /**
     * @brief Constructor de copia.
     * @param other Objeto que se va a copiar.
     * @return El objeto copiado.
     * @post other no se modifica.
     */
    LettersSet(const LettersSet &other);

    /**
     * @brief Añade un nuevo carácter al LettersSet.
     * @param val Carácter añadido.
     * @return Booleano tal que solo es true si y solo si, se ha podido realizar la inserción y
     *  el nuevo carácter no se encontraba previamente en el LettersSet.
     * @post El tamaño del LettersSet aumenta.
     */
    bool insert (const pair<char, LetterInfo> &val);

    /**
     * @brief Elimina un carácter del LettersSet.
     * @param key Carácter a borrar.
     * @return Booleano que indica true si ha eliminado correctamente o false en cualquier
     *  otro caso.
     * @post El tamaño del LettersSet disminuye.
     */
    bool erase (const char &key);

    /**
     * @brief Elimina todos los caracteres del LettersSet.
     * @post El LettersSet pasa a tener 0 elementos.
     */
    void clear();

    /**
     * @brief Indica si el LettersSet está vacío.
     * @return Booleano que marca true si el LettersSet está vacío, false en caso contrario.
     * @post El LettersSet no se modifica
     */
    bool empty() const;

    /**
     * @brief Devuelve el tamaño del LettersSet.
     * @return Número de elementos en el LettersSet.
     */
    unsigned int size () const;

    /**
     * @brief Calcula la puntuación de una palabra.
     * @param word Palabra cuya puntuación queremos calcular.
     * @pre Solo se tendrán en cuenta en el cálculo aquellos caracteres que pertenezcan
     *  al LettersSet.
     * @return Puntación de la palabra, calculada como la suma de la puntuación de los
     *  caracteres que la forman.
     */
    int getScore (string word);

    /**
     * @brief Busca el carácter indicado dentro del LettersSet.
     * @param key Carácter a buscar.
     * @return Booleano que marca true si el valor pertenece al LettersSet,
     *  false en caso contrario.
     */
    bool find (const char &key);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param cl LettersSet que se va a copiar.
     * @return Referencia al objeto this que permita encadenar el operador.
     */
    LettersSet & operator=(const LettersSet &cl);

    /**
     * @brief Sobrecarga del operador de consulta. Permite acceder a los elementos del LettersSet.
     * @param val Carácter del LettersSet a consultar.
     * @return Devuelve la estructura LetterInfo del carácter consultado.
     */
    LetterInfo & operator[](const char &val);

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida.
     * @param cl LettersSet donde se encuentran los datos que vamos a escribir.
     * @return Devuelve el flujo de salida.
     */
    friend ostream & operator<<(ostream &os, const LettersSet &cl);

    /**
     * @brief Sobrecarga del operador de entrada.
     * @param is Flujo de entrada.
     * @param cl LettersSet donde se van a guardar los datos leídos.
     * @return Devuelve el flujo de entrada.
     */
    friend istream & operator>>(istream &is, LettersSet &cl);

    /**
     * @brief TDA LettersSet::const_iterator
     *
     * Este TDA representa un 'iterador' sobre la clase LettersSet con todas las operaciones
     * que cabría esperar del 'iterador' si se tratase de un contenedor tipo map.
     */
    class iterator{

    private:
        map<char, LetterInfo>::const_iterator it; //Iterador constante

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
         * @brief Sobrecarga del operador de asignación.
         * @param other iterator que se va a copiar.
         * @return Referencia al objeto this que permita encadenar el operador.
         */
        iterator & operator=(const map<char, LetterInfo>::const_iterator &other){
            it = other;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de relacional 'distinto de'.
         * @param other iterator que se va a comparar.
         * @return Booleano que marca true en caso de ser iteradores distintos,
         *  false en caso contrario.
         */
        bool operator!=(const map<char, LetterInfo>::const_iterator &other){
            bool distintos = this->it!=other ? true : false;
            return distintos;
        }

        /**
         * @brief Sobrecarga del operador de relacional de igualdad.
         * @param other iterator que se va a comparar.
         * @return Booleano que marca true en caso de ser iteradores iguales,
         *  false en caso contrario.
         */
        bool operator==(const map<char, LetterInfo>::const_iterator &other){
            bool iguales = this->it!=other ? true : false;
            return iguales;
        }

    };

};


#endif

