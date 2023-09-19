#include <iostream>
#include <string>
#include <vector>

using namespace std;

string manacher(string s) {
    // Transformar la cadena para lidiar con palíndromos de longitud impar
    string t = "#";
    for (char c : s) {
        t += c;
        t += '#';
    }

    int n = t.length();
    vector<int> P(n, 0);  // Arreglo de longitud de palíndromo

    int C = 0;  // Centro del palíndromo más largo encontrado hasta ahora
    int R = 0;  // Derecha del palíndromo más largo encontrado hasta ahora

    for (int i = 0; i < n; i++) {
        // Si i está dentro del palíndromo más largo conocido, podemos aprovechar la simetría
        if (i < R) {
            int mirror_i = 2 * C - i;  // Espejo de i con respecto al centro
            P[i] = min(R - i, P[mirror_i]);  // Extender basado en la simetría
        }

        // Intentar extender el palíndromo en la posición actual
        int a = i + (1 + P[i]);  // Extender a la derecha
        int b = i - (1 + P[i]);  // Extender a la izquierda

        while (a < n && b >= 0 && t[a] == t[b]) {
            P[i]++;
            a++;
            b--;
        }

        // Si se extiende más allá de R, actualizamos el centro y la derecha del palíndromo conocido
        if (i + P[i] > R) {
            C = i;
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

    // Construir y devolver el palíndromo más largo
    int start = (center_index - max_len) / 2;  // Índice de inicio en la cadena original
    return s.substr(start, max_len);
}

int main() {
    string s = "babad";
    string longest_palindrome = manacher(s);
    cout << "El palindromo más largo es: " << longest_palindrome << endl;
    return 0;
}