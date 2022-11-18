#include <letters_set.h>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *arg[]){

    //Control de entrada de argumentos
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: conjunto_letras <FichLetras> <Palabra>\n";
        exit (1);
    }

    LettersSet conjunto;
    ifstream input;
    ofstream output;

    //Lectura del fichero
    input.open(arg[1]);
    if(!input)
        cerr << "Imposible abrir el archivo: " << arg[1] << endl;
    input >> conjunto;
    input.close();

    //Cálculo de puntuación
    cout << conjunto.getScore(arg[2]) << endl;

    return 0;
}
