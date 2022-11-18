#include <dictionary.h>
#include "letters_set.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *arg[]) {

    //Control de entrada de argumentos
    if (argc != 3) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichPalabras> <FichLetras>\n";
        exit(1);
    }

    Dictionary diccionario;
    LettersSet letras;
    ifstream input;

    //Lectura del fichero de palabras
    input.open(arg[1]);
    if(!input)
        cerr << "Imposible abrir el archivo: " << arg[1] << endl;
    input >> diccionario;
    input.close();

    //Lectura del fichero de letras
    input.open(arg[2]);
    if(!input)
        cerr << "Imposible abrir el archivo: " << arg[1] << endl;
    input >> letras;
    input.close();

    cout << "Letra FAbs. Frel. " << endl;
    double fabs, frel;
    int total_letras = diccionario.getTotalLetters();
    for (LettersSet::iterator it = letras.begin(); it != letras.end();  it++) {
        pair<const char, LetterInfo> c =*it;
        fabs = diccionario.getOccurrences(c.first);
        frel = fabs/total_letras;
        cout << c.first << " " << fabs << " " << frel <<endl;
    }

    return 0;
}
