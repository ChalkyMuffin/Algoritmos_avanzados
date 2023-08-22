#include <iostream>
using std::cout;
using std::endl;



//Funcion que une dos subarreglos o arreglos partidos a la mitad, primer arreglo va desde l a m y el segundo desde m+1 a r
//Input: Arreglo, inicio del arreglo, mitad del arreglo, final del arreglo
//Regresa: Arreglo unido
//l = left
//m = middle
//r = right
void merge(int arr[], int l, int m, int r){
    //s1 = sub-arreglo 1
    int s1 = m - l + 1;
    //s2 = sub-arreglo 2
    int s2 = r - m;

    //auto hace que automaticamente detecte el tipo de variable
    //Variables para generar los ambos lados en los que se parte el arreglo para ordenarlo
    //Arreglos imaginarios de cierta forma
    //L = Left array
    //R = Right array
    auto *L = new int[s1];
    auto *R = new int[s2];

    //Iteraciones en el arreglo de la izquierda
    for (int i = 0; i <= s1 -1; i++){
        L[i] = arr[l+i];
    }


    //Iteraciones en arreglo de la derecha
    for (int j = 0; j <= s2 -1; j++){
        R[j] = arr[m + 1 + j];
    }

    //indexOfSubArrayOne
    int i = 0;
    //indexOfSubArrayTwo
    int j = 0;
    //indexOfMergedArray
    int k = l;


    //Une los nuevos arreglos dentro del arreglo en si
    //Caso de arreglo izquierdo
    while (i < s1 && j < s2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i = i + 1;
        }

    //Caso de arreglo derecho
        else{
            arr[k] = R[j];
            j = j+1;
        }
        k = k + 1;

    }


    //Copia los elementos del lado izquierdo si quedan
    while (i < s1){
        arr[k] = L[i];
        i = i+1;
        k = k+1;
    }

    //Copia los elementos del lado derecho si quedan
    while (j < s2){
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }

    //Elimina los arreglos imaginarios de la memoria
    delete[] L;
    delete[] R;

}

//Algoritmo de ordenamiento que usa merge para partir en dos un arreglo y dividir su tamaño para trabajar mas eficientemente
//Input: arreglo, primer posicion, ultima posicion disponible
//Regresa: El arreglo ordenado
//l = left
//m = middle
//r = right
void mergeSort(int arr[], int l, int r){
    if (l < r){
        //Para llegar mas o menos en medio del arreglo
        int m = l +(r-l)/2;
        mergeSort(arr, l,m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

}

//Imprime el arreglo
//Input: Arreglo y tamaño del arreglo
//Regresa: El arreglo impreso
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

    cout << "El arreglo es: " << endl;
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);
 
    cout << "\nEl arreglo ordenado es: " << endl;
    printArray(arr, n);
    return 0;
}