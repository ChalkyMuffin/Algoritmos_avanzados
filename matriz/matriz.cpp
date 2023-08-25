#include <iostream>
using namespace std;
int main ()
{
    int arr[4][3]={{1, 2, 3}, {4, 5, 6}, {20, 80, 90}, {100, 110, 120}};
    
     for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " " ;
        }
        cout << endl;
     }
    return 0;
}