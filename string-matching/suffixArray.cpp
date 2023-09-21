#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Complejidad O(n^2)
//Algunos usos del suffix array incluyen el data mining, procesamiento de lenguaje, analisis de genoma, pattern matching en textos largos, etc.


// Esta es una estructura que usamos para almacenar un suffix y su posición inicial.
class Suffix {
public:
    string suffix;  // El suffix en si.
    int index;      // La posicion inicial del suffix en la string original.
};

// Genera todos los suffix de una string dada.
//Input: String al que analizar
//Regresa: Suffixes del string
vector<Suffix> generateSuffixes(string str) {
    int n = str.length(); 
    vector<Suffix> suffixes(n);  

    //Genera los suffix.
    for (int i = 0; i < n; ++i) {
        
        suffixes[i].suffix = str.substr(i);

        suffixes[i].index = i;  
    }

    return suffixes;  // Devolvemos todos los suffix generados.
}

// Compara dos suffix y determina su orden en el arreglo.
//Input: Ninguno
//Regresa: True si el primer suffix es mayor al segundo y viceversa
bool comparaSuffix(const Suffix &a, const Suffix &b) {
    return a.suffix < b.suffix;  
}

//Construye un arreglo de suffix.
//Input: string que hacer suffix
//Regresa: suffix array final
vector<int> buildSuffixArray(string str) {
    // Generamos todos los suffix del string.
    vector<Suffix> suffixes = generateSuffixes(str);  

    // Ordenamos los suffix basándonos en sus strings.
    sort(suffixes.begin(), suffixes.end(), comparaSuffix);

    //Arreglo de suffix resultante.
    vector<int> suffixArray;  
    
    for (const auto &suffix : suffixes) {
        suffixArray.push_back(suffix.index);
    }

    return suffixArray;  
}

int main() {
    string s = "Hello World!";
     // Construimos el arreglo de suffix de la string.
    vector<int> suffixArray = buildSuffixArray(s); 

    // Imprimimos el arreglo de suffix resultante.
    for (int i : suffixArray) {
        cout << i << " ";
    }

    return 0;
}





