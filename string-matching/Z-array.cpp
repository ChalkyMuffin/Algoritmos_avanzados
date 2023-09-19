#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to compute the Z-array
void computeZArray(const string &str, vector<int> &z) {
    int n = str.size();
    z.resize(n, 0);

    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i <= R) {
            z[i] = min(R - i + 1, z[i - L]);
        }

        while (i + z[i] < n && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        }

        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
}

// String matching using Z-Algorithm
void strMatch(const string &pattern, const string &text) {
    string concat = pattern + "$" + text;
    vector<int> z;
    computeZArray(concat, z);

    int patternLength = pattern.size();
    int concatLength = concat.size();

    for (int i = patternLength + 1; i < concatLength; i++) {
        if (z[i] == patternLength) {
            int startIndex = i - patternLength - 1;
            int endIndex = startIndex + patternLength - 1;
            cout << "Se ha encontrado '" << pattern << "' del indice: " << startIndex << " al " << endIndex << endl;
        }
    }
}

int main() {
    string pattern = "effanineffable";
    string text = "effable_effanineffable";

    strMatch(pattern, text);

    return 0;
}