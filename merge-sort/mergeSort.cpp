#include <iostream>
using namespace std;

//l = left
//m = middle
//r = right
void merge(int arr[], int l, int m, int r){
    //s1 = sub-arreglo 1
    int s1 = m - l + 1;
    //s2 = sub-arreglo 2
    int s2 = r - m;

    //auto hace que automaticamente detecte el tipo de variable
    //Variables para generar los ambos lados en los0 que se parte el arreglo para ordenarlo
    //L = Left array
    //R = Right array
    auto *L = new int[s1];
    auto *R = new int[s2];

    for (int i = 0; i < s1 - 1; i++){
        L[i] = arr[l+i];
    }

    for (int j = 0; j < s2 - 1; j++){
        R[j] = arr[m + 1 + j];
    }

    //indexOfSubArrayOne
    int i = 0;
    //indexOfSubArrayTwo
    int j = 0;
    //indexOfMergedArray
    int k = l;

    while (i < s1 && j < s2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i = i + 1;
        }
        else{
            arr[k] = R[j];
            j = j+1;
        }
        k = k + 1;

    }

    while (i < s1){
        arr[k] = L[i];
        i = i+1;
        k = k+1;
    }

    while (j < s2){
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }

    delete[] L;
    delete[] R;

}

//l = left
//m = middle
void mergeSort(int arr[], int l, int r){
    if (l < r){
        //Para llegar mas o menos en medio del arreglo
        int m = l +(r-l)/2;
        mergeSort(arr, l,m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    int arr[6] = { 12, 11, 13, 5, 6, 7 };
    int n = 6;

    cout << "Given array is \n";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, n);
    return 0;
    return 0;
}