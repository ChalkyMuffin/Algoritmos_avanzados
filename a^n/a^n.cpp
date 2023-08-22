#include <iostream>
using std::cout;
using std::endl;


//Complejidad O(log n)

int cuadrado(int a, int n) {
    //Todo a la 0 da 1
    if (n == 0){
        return 1;
    }
    
    int medio_cuadrado = cuadrado(a, n / 2);
    int result = medio_cuadrado * medio_cuadrado;
    
    if (n % 2 == 1){
        result *= a;
    }
    
    return result;
}

int main() {
    int a = 2;
    int n = 10;
    
    int result = cuadrado(a, n);
    
    cout << a << "^" << n << " = " << result << endl;
    
    return 0;
}