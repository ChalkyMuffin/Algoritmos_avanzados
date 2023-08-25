#include <iostream>
using namespace std;

// Tenemos una escalera de 𝑛 peldaños
// Se puede subir en pasos de 1 o 2 peldaños a la vez
// ¿De cuantas formas diferentes se puede llegar hasta arriba?
// a = 1 por el caso de dar 1 salto
// b = 2 por el caso de dar 2 saltos
int fibo(int n, int a, int b)
{

    if (n == 0)
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "n = 1" << endl;
        return a;
    }

    else if (n == 1)
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "n = 2" << endl;
        return b;
    }

    else
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        return fibo(n - 1, b, a + b);
    }
}

int main()
{

    cout << fibo(7, 0, 1);
    return 0;
}