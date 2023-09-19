#include <iostream>
#include <vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) table
vector<int> computaLPS(const string &patron) {
    int m = patron.size();
    vector<int> lps(m, 0);

    int len = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; i++) {
        while (len > 0 && patron[i] != patron[len]) {
            len = lps[len - 1];
        }

        if (patron[i] == patron[len]) {
            len++;
        }

        lps[i] = len;
    }

    return lps;
}

// KMP string matching algorithm
void strMatch(const string &patron, const string &busqueda) {
    int m = patron.size();
    int n = busqueda.size();
    vector<int> lps = computaLPS(patron);

    int i = 0; // Index for busqueda[]
    int j = 0; // Index for patron[]

    while (i < n) {
        if (patron[j] == busqueda[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Encontrado en index: " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && patron[j] != busqueda[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
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

