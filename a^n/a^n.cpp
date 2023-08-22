#include <iostream>
using std::cout;
using std::endl;


//Complejidad O(log n)


/*Es mas eficiente que con el metodo de fuerza bruta porque con fuerza bruta su complejidad seria O(n) ya que estaria multiplicando el numero 
las n veces que el exponente diga mientras que con divide and conquer su complejidad seria < n pues seria O(log n) 
ya que este otro usa la recursividad y la division del problema para llegar al mismo resultado con menos iteraciones*/


//Funcion a la que le das un numero y la potencia a la que lo quieres y hace la operacion de forma recursiva siguiendo divide y venceras
//Input: Dos numeros, uno que sera afectado y otro al que vas a usar para que sea la potencia de este
//Regresa: El numero a la potencia del otro
int cuadrado(int a, int n) {

    //Todo a la 0 da 1
    if (n == 0){
        return 1;
    }
    
    int medio_cuadrado = cuadrado(a, n / 2);
    cout << "medio cuadrado = " << medio_cuadrado << endl;
    int result = medio_cuadrado * medio_cuadrado;
    cout << "result = " << result << endl;
    
    //Si el numero es impar se multiplica el resultado una vez mas por a
    if (n % 2 == 1){

        result = result * a;
        cout << "result * a = " << result << endl;

    }
    
    return result;
}

int main() {
    int a = 2;
    int n = 10;
        
    //cout << a << "^" << n << " = " << cuadrado(a, n) << endl;
    cout << cuadrado(a,n);
    
    return 0;
}