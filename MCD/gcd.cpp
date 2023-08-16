#include <iostream>
using namespace std;
//Algotitmo de Euclides para gcd o mcd
//Complejidad O(Log min(m, n))

//Funcion para sacar el maximo comun divisor (greatest common divisor) usa la recursividad para cambiar el valor de m por el de n y el valor de n por el resultado del m modulo n, en el momento que el valor de m se pasa a n se guarda el valor mas grande hasta el momento en la operacion y se transforma de nuevo en m para usarla en el modulo de m%n, cuando este modulo de igual a 0 se sabra que ese es el mcd y terminara la operacion
//Input: Dos numeros enteros
//Regresa: Su maximo comun divisor
int gcd(int m, int n)
{
    //Revisa si el resultado del modulo es 0 lo que significaria que son divisibles y el maximo comun divisor
    if (n == 0)
        return m;
    
    //Muestra los datos para poder ver el progreso y las iteraciones
    cout << "m = " << m << endl;
    cout <<"n = " << n << endl;
    cout << "m modulo n = " << m%n << endl;

    //Cambia recursivamente primero el valor de m por el de n y luego el valor de n por el de m%n de forma que si m%n da = 0 se sabe que ese es el mcd  
    return gcd(n, m%n);
}
 

int main ()
{
    int m = 24;
    int n = 60;
    cout << gcd(m,n);

    return 0;
}