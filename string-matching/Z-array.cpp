#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Complejidad O(n)

// Funcion para calcular el Z array
// Input: String concatenada y un vector int
// Regresa: Z array
void zArray(const string &str, vector<int> &z) {
    int n = str.size();
    // Inicializamos el Z array con ceros
    z.resize(n, 0); 


    // Inicializamos los limites del subarreglo que estamos analizando
    int L = 0, R = 0;  

    // Empezamos desde 1, ya que z[0] siempre es 0
    for (int i = 1; i < n; i++) {  
        if (i <= R) {
            // Si estamos dentro del subarreglo que ya hemos analizado,
            // utilizamos información previa para calcular z[i] de manera eficiente.
            z[i] = min(R - i + 1, z[i - L]);
        }

        // Expandimos el subarreglo hacia la derecha mientras los caracteres coincidan
        while (i + z[i] < n && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        }

        // Si encontramos un nuevo subarreglo que se extiende más alla de R,
        // actualizamos los limites L y R.
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
}

// Funcion para buscar coincidencias de patron en un texto utilizando el Z algorithm
// Input: patron y texto
// Regresa: Posicion del patron buscado en el texto
void strMatch(const string &patron, const string &busqueda) {
    // Concatenamos el patron y el texto con un caracter especial ('$') entre ellos
    string concat = patron + "$" + busqueda;
    vector<int> z;
    // Calculamos el Z array
    zArray(concat, z);  

    int patronLength = patron.size();
    int concatLength = concat.size();

    // Buscamos coincidencias en el Z array
    for (int i = patronLength + 1; i < concatLength; i++) {
        if (z[i] == patronLength) {
            
            // Si encontramos una coincidencia, calculamos los indices en el texto original
            int startIndex = i - patronLength - 1;
            int endIndex = startIndex + patronLength - 1;
            cout << "Se ha encontrado '" << patron << "' del indice: " << startIndex << " al " << endIndex << endl;
        }
    }
}

int main() {
    string patron = "effanineffable";  
    string busqueda = "effable_effanineffable"; 

    strMatch(patron, busqueda);  

    return 0;
}