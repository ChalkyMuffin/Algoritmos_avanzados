#include <iostream>
using namespace std;

void partition(int arr[], int l, int r){
    int pivote = arr[r];
    int i = l-1;
    for (int j = l; j <= r-1; j++){
        //Intercambia arr[i] con arr[j]
        if(arr[j] < pivote){
            i = i+1;
            int aux = arr[i];
            arr[i] =  arr[j];
            arr[j] = aux;
        }
    }
    //Intercambia arr[i+1] con arr[r]
    int aux = arr[i+1];
    arr[i+1] = arr[r];
}

int main ()
{
    return 0;
}