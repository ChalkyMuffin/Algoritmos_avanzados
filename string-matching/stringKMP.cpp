#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array
vector<int> computeLPS(const string& pattern) {
    int patternLength = pattern.length();
    vector<int> lps(patternLength, 0);  // Initialize the LPS array with zeros
    int length = 0;  // Length of the previous longest prefix suffix

    int i = 1;
    while (i < patternLength) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;  // Store the length of the longest prefix suffix
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];  // Update 'length' using LPS values
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP search function
vector<int> KMPSearch(const string& text, const string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    vector<int> result;  // To store the indices of occurrences

    vector<int> lps = computeLPS(pattern);  // Calculate LPS array for the pattern
    int i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]

    while (i < textLength) {
        if (pattern[j] == text[i]) {
            i++;  // Increment both indices when characters match
            j++;
        }

        if (j == patternLength) {
            // Pattern found at index i-j in the text
            result.push_back(i - j);  // Store the starting index of the match
            j = lps[j - 1];  // Update 'j' using LPS values for potential additional matches
        } else if (i < textLength && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];  // Update 'j' using LPS values
            } else {
                i++;  // No match found, move to the next character in the text
            }
        }
    }
    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> result = KMPSearch(text, pattern);

    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}