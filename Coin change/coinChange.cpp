#include <iostream>
using namespace std;

//Tenemos una escalera de 𝑛 peldaños
//Se puede subir en pasos de 1 o 2 peldaños a la vez 
//¿De cuantas formas diferentes se puede llegar hasta arriba? 
//a = 1 por el caso de dar 1 salto
//b = 2 por el caso de dar 2 saltos
int coins(int C[], int n, int K){
    
    
    if (K == 0){
        return 1;
    }

    else if(n <= 0 || K < 0){
        return 0;
    }

    else{
        return coins(C, n-1, K) + coins(C, n, K - C[n-1]);
    }

}


int coins_memo (int C[], int n, int K,  int T[]){
    if (K == 0){
        T[n,K] = 1;
    }
}

int main ()
{

    return 0;
}