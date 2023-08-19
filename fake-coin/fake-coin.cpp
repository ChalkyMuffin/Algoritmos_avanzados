#include <iostream>
using namespace std;

void fakeCoin(int coinWeight[]){

    int n = sizeof(coinWeight);
    int realCoin;

    for (int i = 0; i < n; i++){
        if(coinWeight[i] == coinWeight [i+1]){
            realCoin = coinWeight[i];

        }

        else if (coinWeight[i] != realCoin){
            cout << "Fake coin en el index " << i << " pesa " << coinWeight[i] << endl;
            return;

        }
    }

}

int main ()
{
    int coinWeight[6] = {20,20,15,20,20,20};

    fakeCoin(coinWeight);
    


    
    return 0;
}