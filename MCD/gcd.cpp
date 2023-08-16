#include <iostream>
using namespace std;

int gcd(int n, int m)
{
    if (n == 0)
        return m;
    return gcd( m % n, n);
}
 

int main ()
{
    int n = 60;
    int m = 24;
    cout << gcd(n,m);

    return 0;
}