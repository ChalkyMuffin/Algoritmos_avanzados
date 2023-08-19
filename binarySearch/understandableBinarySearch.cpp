#include <iostream>
using namespace std;

// Funcion eficiente que busca un valor dentro de una lista ordenada
void binarySearch(int arreglo[], int busca, int n)
{
    int l = 0;
    int r = n - 1;
    int i = 0;

    while (l <= r)
    {
        cout << "i = " << i << endl;
        cout << "r = " << r << endl;
        cout << "l = " << l << endl;

        cout << "r - l = " << r - l << endl;
        i = l + (r - l) / 2;
        cout << "i = " << i << endl;

        if (arreglo[i] == busca)
        {
            cout << busca << " es = a " << arreglo[i] << endl;
            cout << "i = " << i << endl;

            cout << busca << " encontrado en index " << i; // Devuelve el índice encontrado en lugar del valor
            break;
        }

        else if (busca < arreglo[i])
        {
            cout << busca << " es < a " << arreglo[i] << " en posicion " << i << endl;

            r = i - 1;
            cout << "r = " << r << endl;
        }

        else if (busca > arreglo[i])
        {
            cout << busca << " es > a " << arreglo[i] << " en posicion " << i << endl;
            l = i + 1;
            cout << "l = " << l << endl;
        }
    }
}

int main()
{
    int sortedArray[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int busca = 11;
    binarySearch(sortedArray, busca, 10);

    return 0;
}