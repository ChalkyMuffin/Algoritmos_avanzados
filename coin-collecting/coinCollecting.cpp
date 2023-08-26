#include <iostream>
using namespace std;

//Se crea la matriz que simula el camino representando los espacion vacios con 0 y los espacios con monedas con 1
int C[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 0,0}, {1, 0, 0, 0, 1}};

int F(int i, int j) {
    if (i >= 0 && j >= 0) {
        return max(F(i - 1, j), F(i, j - 1)) + C[i][j];
        
    }
    if (i < 0 || j < 0) {
        //cout << "xd" << endl;
        return 0;
    }
    return 0;
}

int main ()
{
    
     for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            cout << C[i][j] << " " ;
        }
        cout << endl;
     }

    cout << "Monedas maximas posibles: " << F(4, 4) << endl;

    return 0;
}
