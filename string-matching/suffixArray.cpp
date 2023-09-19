#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{
    string s = "Hello World!";
    vector<char> v(s.begin(), s.end());
    int n = size(v);
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    return 0;
}