#include <iostream>
#include <vector>
using namespace std;


//Complejidad O(n+m)

// Función para calcular la tabla de Longest Prefix Suffix (LPS)
//Input: Patron
//Regresa: lps para string match
vector<int> computaLPS(const string &patron) {
    int m = patron.size();

    // Inicializamos la tabla LPS con ceros.
    vector<int> lps(m, 0);  

    int n = 0;

    // Recorremos el patrón desde el segundo carácter.
    for (int i = 1; i < m; i++) {
        // Mientras no coincida el carácter actual con el carácter en la posición "n" del patrón,
        // Retrocedemos en la tabla LPS
        while (n > 0 && patron[i] != patron[n]) {
            n = lps[n - 1];
        }

        // Si el carácter actual coincide con el carácter en la posición "n" del patrón, incrementamos "n".
        if (patron[i] == patron[n]) {
            n++;
        }

        // Guardamos n en i
        lps[i] = n;
    }

    return lps; 
}

// Algoritmo de coincidencia de cadenas KMP
//Input: Patron y busqueda
//Regresa: Nada
void strMatch(const string &patron, const string &busqueda) {
    int m = patron.size();
    int n = busqueda.size();  

    // Calculamos la tabla LPS.
    vector<int> lps = computaLPS(patron);  

    // index para la cadena de busqueda.
    int i = 0; 
    // index para el patrón.
    int j = 0; 

    
    while (i < n) {
        if (patron[j] == busqueda[i]) {
            i++; 
            j++;
        }

        if (j == m) {
            
            // Si hemos llegado al final del patrón, hemos encontrado una coincidencia.
            cout << "Encontrado en índice: " << i - j << endl;

            // Retrocedemos en el patrón usando la tabla LPS.
            j = lps[j - 1];  
        } else if (i < n && patron[j] != busqueda[i]) {
            if (j != 0) {
                // Retrocedemos en el patrón utilizando la tabla LPS.
                j = lps[j - 1];
            } else {
                // Si no podemos retroceder más en el patrón, avanzamos en la cadena de búsqueda.
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