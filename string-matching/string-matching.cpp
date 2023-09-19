#include <iostream>
using namespace std;

//String-matching
//Complejidad O(n^2)
//lol
void strMatch(const string &patron, string &busqueda)
{
    int n = patron.size();
        int iteraciones = 0;


    for (int i = 0; i <= n; i++)
    {
        iteraciones++;
        if (patron[i] == busqueda[0])
        {
            string checa;
            string checador;


            for (int j = 0; j <= n - i; j++)
            {
                iteraciones++;

                checador += patron[i + j];
                // cout << checador;

                // cout << j << endl;
                checa = checador;

                if (checa == busqueda)
                {
                    cout << "Se ha encontrado " <<checa << " del indice: " << i << " al " << i+j << " con " << iteraciones << " iteraciones";
                    break;
                }
            }
            // cout << busqueda.size();
            //cout << "********" << endl;
            //cout << checa;
            
        }
        // cout << i << ' ';
    }
}

int main()
{
    //string patron = "effable_effanineffable";
    string busqueda = "effable_effanineffable";
    string patron = "effanineffable";

    //string busqueda = "effanineffable";
    // cout << patron[3];

    strMatch(patron, busqueda);

    return 0;
}
