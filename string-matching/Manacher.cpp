#include <iostream>
#include <string>
#include <vector>
using namespace std;

string manacher(string s) {
    // Transformar el string para lidiar con palindromos de longitud impar
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }

    int n = t.length();
    vector<int> P(n, 0);  // Arreglo de longitud de palindromo

    // centro del palindromo mas largo encontrado hasta ahora
    int cen = 0;  
    // Derecha del palindromo mas largo encontrado hasta ahora
    int R = 0;  

    for (int i = 0; i < n; i++) {
        // Si i esta dentro del palindromo mas largo conocido, podemos aprovechar la simetria
        if (i < R) {
            // Espejo de i con respecto al centro
            int mirror_i = 2 * cen - i;  
            // Extender basado en la simetria
            P[i] = min(R - i, P[mirror_i]);  
        }

        // Intentar extender el palindromo en la posición actual
        // Extender a la derecha
        int a = i + (1 + P[i]);

        // Extender a la izquierda  
        int b = i - (1 + P[i]);  

        while (a < n && b >= 0 && t[a] == t[b]) {
            P[i]++;
            a++;
            b--;
        }

        // Si se extiende mas alla de R, actualizamos el centro y la derecha del palindromo conocido
        if (i + P[i] > R) {
            cen = i;
            R = i + P[i];
        }
    }

    // Encontrar el valor máximo en el arreglo P
    int max_len = 0;
    int center_index = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    // Construir y devolver el palindromo mas largo
    // Indice de inicio en la string original
    int start = (center_index - max_len) / 2;  
    return s.substr(start, max_len);
}

int main() {
    string s = "babad";
    string longest_pal = manacher(s);
    cout << "El palindromo mas largo es: " << longest_pal << endl;
    return 0;
}