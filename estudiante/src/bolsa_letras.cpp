//
// Created by diegoos_03 on 19/11/22.
//
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

    for(int i = 0; i < bolsa_letras.size(); i++){
        cout << bolsa_letras.extractLetter();
    }

    return 0;

}
