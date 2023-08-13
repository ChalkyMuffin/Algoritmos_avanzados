#include <iostream>
using namespace std;

//String-matching
//Complejidad O(n^2)
//lol
void strMatch(const string &patron, string &busqueda)
{
    int n = patron.size();

    for (int i = 0; i <= n; i++)
    {
        if (patron[i] == busqueda[0])
        {
            string checa;
            string checador;


            for (int j = 0; j <= n - i; j++)
            {

                checador += patron[i + j];
                // cout << checador;

                // cout << j << endl;
                checa = checador;

                if (checa == busqueda)
                {
                    cout << "Se ha encontrado " <<checa << " del indice: " << i << " al " << i+j;
                    break;
                }
            }
            // cout << busqueda.size();
            //cout << "********" << endl;
            //cout << checa;
            continue;
            ;
        }
        // cout << i << ' ';
    }
}

int main()
{
    string patron = "This is a small example";
    string busqueda = "small example";
    // cout << patron[3];

    strMatch(patron, busqueda);

    return 0;
}
