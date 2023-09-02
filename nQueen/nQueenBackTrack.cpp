#include <iostream>
#define n 4
using namespace std;
//void printArray(int tablero[n][n]){
//    for (int i = 0; i < n; i++) {

//        for (int j = 0; j < n; j++) {
//            cout << tablero[i][j] << " " ;
//        }
//        cout << endl;
//     }
//}

void nQueen(int tablero[n][n], int columna){

    for (int i = 0; i < n; i++) {
        tablero[i][columna] = 1;

        for (int j = 0; j < n; j++) {
            //tablero[0][j] = 1;
            cout << tablero[i][j] << " " ;
        }
        cout << endl;
     }


}



int main ()
{
    int tablero[4][4] = {0};

    //for (int i = 0; i < n; i++) {
    //    tablero[0][2] = 1;

    //    for (int j = 0; j < n; j++) {
    //        //tablero[0][j] = 1;
    //        cout << tablero[i][j] << " " ;
    //    }
    //    cout << endl;
    // }

    nQueen(tablero, 0);
    
    return 0;
}

