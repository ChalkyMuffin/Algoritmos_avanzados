#include <iostream>
#include <vector>
using namespace std;


//Complejidad O(n+m)

// Funcion para calcular la tabla LPS (Longest Prefix Suffix) 
//Input: Patron
//Regresa: LPS para string match
vector<int> computaLPS(const string &patron) {
    int m = patron.size();

    // Inicializamos la tabla LPS con ceros.
    vector<int> LPS(m, 0);  

    int n = 0;

    // Recorremos el patron desde el segundo caracter.
    for (int i = 1; i < m; i++) {
        // Mientras no coincida el caracter actual con el caracter en la posicion "n" del patron,
        // Retrocedemos en la tabla LPS
        while (n > 0 && patron[i] != patron[n]) {
            n = LPS[n - 1];
        }

        // Si el caracter actual coincide con el caracter en la posicion "n" del patron, incrementamos "n".
        if (patron[i] == patron[n]) {
            n++;
        }

        // Guardamos n en i
        LPS[i] = n;
    }

    return LPS; 
}

// Algoritmo de coincidencia de cadenas KMP
// Input: Patron y busqueda
// Regresa: Nada
void strMatch(const string &patron, const string &busqueda) {
    int m = patron.size();
    int n = busqueda.size();  

    // Calculamos la tabla LPS.
    vector<int> LPS = computaLPS(patron);  

    // index para la cadena de busqueda.
    int i = 0; 
    // index para el patron.
    int j = 0; 

    
    while (i < n) {
        if (patron[j] == busqueda[i]) {
            i++; 
            j++;
        }

        if (j == m) {
            
            // Si hemos llegado al final del patron, hemos encontrado una coincidencia.
            cout << "Encontrado en índice: " << i - j << endl;

            // Retrocedemos en el patron usando la tabla LPS.
            j = LPS[j - 1];  
        } else if (i < n && patron[j] != busqueda[i]) {
            if (j != 0) {
                // Retrocedemos en el patron utilizando la tabla LPS.
                j = LPS[j - 1];
            } else {
                // Si no podemos retroceder más en el patron, avanzamos en la cadena de busqueda.
                i++;  
            }
        }
    }
}

int main() {
    string busqueda = "effable_effanineffable";  
    string patron = "effanineffable";

    strMatch(patron, busqueda);

    return 0;
}