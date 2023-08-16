#include <iostream>
using namespace std;

//Algoritmo gcd con fuerza bruta
//Complejidad: O(min(m, n))


int bruteGcd(int m, int n) {
    int mcd;

    if(m > n){
        for(int i = 1; i <= n; i++){

            if(m%i == 0 && n%i == 0){
                mcd = i;
            }

        }

    }

    else if (m < n){
        for(int i = 1; i <= m; i++){

            if(m%i == 0 && n%i == 0){
                mcd = i;
            }

        }
    }
    return mcd;
    

}

int main ()
{

    int m = 24;
    int n = 60;
    cout << bruteGcd(m,n);


    return 0;
}