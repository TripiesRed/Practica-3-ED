#include "letters_set.h"
#include "letters_bag.h"
#include <fstream>
#include <iostream>

using namespace std;

int main (int argc, char *arg[]){

    if (argc != 2) {
        cerr << "Error: número incorrecto de parámetros.\n";
        exit(1);
    }

    LettersSet conjunto_letras;
    ifstream input;

    input.open(arg[1]);
    if(!input)
        cerr << "Imposible abrir el archivo: " << arg[1] << endl;
    input >> conjunto_letras;
    input.close();

    LettersBag bolsa_letras(conjunto_letras);

    vector<char> v;
    v = bolsa_letras.extractLetters(bolsa_letras.size());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    return 0;
}
