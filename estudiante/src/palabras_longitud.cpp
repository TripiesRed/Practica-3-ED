#include <dictionary.h>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char *arg[]) {

    //Control de entrada de argumentos
    if (argc != 3) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichPalabras> <Longitud>\n";
        exit(1);
    }

    Dictionary conjunto;
    ifstream input;
    ofstream output;

    //Lectura del fichero
    input.open(arg[1]);
    if(!input)
        cerr << "Imposible abrir el archivo: " << arg[1] << endl;
    input >> conjunto;
    input.close();

    int length = stoi(arg[2]);

    vector<string> words = conjunto.wordsOfLength(length);

    cout << "Palabras de longitud " << length << endl;
    for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
        cout << *it << endl;

    return 0;
}