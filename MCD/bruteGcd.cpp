#include <iostream>
using namespace std;

//Algoritmo gcd con fuerza bruta
//Complejidad: O(min(m, n))

//Funcion para sacar el maximo comun divisor (greatest common divisor) a traves del enfoque de fuerza bruta, dependiendo de que variable tenga el mayor tamaño hace un loop desde 1 hasta el valor mas pequeño dado y va guardando cada vez los valores que den 0 si hacen modulo con m y n al mismo tiempo
//Input: Dos enteros
//Regresa: El maxicmo comun divisor 
int bruteGcd(int m, int n) {
    //Guarda el menor de los numeros dados
    int mini = min(m,n);
    int mcd;

        //Loop desde 1 hasta el menor de los numeros dados
        for(int i = 1; i <= mini; i++){

            //Si el modulo de i con m y n da 0 lo guarda en la variable mcd
            if(m%i == 0 && n%i == 0){
                mcd = i;
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