#include <iostream>
using namespace std;


int C[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1,0}, {0, 0, 1, 0,0}, {1,0,0,0,1}};

int F(int i, int j) {
    if (i == 0 && j == 0) {
        return C[i][j];
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    return max(F(i - 1, j), F(i, j - 1)) + C[i][j];
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
