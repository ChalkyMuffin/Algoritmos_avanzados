#include <iostream>
using std::cout;
using std::endl;

int partition(int arr[], int l, int r){
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
    arr[r] = aux;
    return (i + 1);
}

void quickSort(int arr[], int l, int r){
    if(l < r){
        int pivote = partition(arr, l, r);
        quickSort(arr,l,pivote-1);
        quickSort(arr,pivote+1,r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main ()
{
    int arr[6] = { 10, 7, 8, 9, 1, 5 };
    int n = 6;

 cout << "Given array is \n";
    printArray(arr, n);

    quickSort(arr,0,n-1);
 
    cout << "\nSorted array is \n";
    printArray(arr, n);

    
    return 0;
}