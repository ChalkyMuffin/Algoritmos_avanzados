#include <iostream>
using namespace std;

int coinCollect(int mat[]){

}

int main ()
{
    int mat[5][5]={{0, 0, 0, 0, 1}, {0, 1, 0, 1, 0}, {0, 0, 0, 1,0}, {0, 0, 1, 0,0}, {1,0,0,0,1}};
    
     for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 4; j++) {
            cout << mat[i][j] << " " ;
        }
        cout << endl;
     }
    return 0;
}