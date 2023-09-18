#include <iostream>
using namespace std;

void KMP(const string &patron, string &busqueda)
{
    int n = patron.size();
    int m = busqueda.size();
    for (int i = 0; i <= n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (patron[i + j] != busqueda[j])
            {
                break;
            }
            
        }
        if (j == m)
            {
                cout << "Pattern found at index " << i << endl;
            }
    }
}

int main()
{
    //string patron = "AABAACAADAABAAABAA";

     string patron = "ababcabcabababd";
    // 00010
    // El 1 esta en b
     string busqueda = "ababd";
    //string busqueda = "AABA";

    KMP(patron, busqueda);

    return 0;
}