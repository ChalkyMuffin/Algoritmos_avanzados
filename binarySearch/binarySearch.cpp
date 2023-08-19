#include <iostream>
using namespace std;

int binarySearch(int arreglo[], int busca, int n){
    int l = 0;
    int r = n-1;

    while (l <= r){
        int i = l + (r - l) / 2;
        if (arreglo[i] == busca){
            return i; // Devuelve el índice encontrado en lugar del valor
        }

        else if(busca < arreglo[i]){
            r = i - 1;
        }

        else if(busca > arreglo[i]){
            l = i + 1;
        }
    }
    return -1;
}

int main ()
{
    int sortedArray[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int busca = 11;
    cout <<"Found " << busca << " at index " << binarySearch(sortedArray, busca, 10);

    return 0;
}