#include <iostream>
using namespace std;

//Tenemos una escalera de 𝑛 peldaños
//Se puede subir en pasos de 1 o 2 peldaños a la vez 
//¿De cuantas formas diferentes se puede llegar hasta arriba? 
//a = 1 por el caso de dar 1 salto
//b = 2 por el caso de dar 2 saltos
int stairs(int n, int a, int b){
    
    
    if (n <= 0){
        return 0;
    }

    else if(n == 1 || n == 2){
        return n;
    }

    else{
        return stairs(n-1, b, a+b);
    }

}

int main ()
{

    cout << stairs(5, 1, 2);
    return 0;
}