#include <iostream>

//Complejidad O(log n)

int power(int a, int n) {
    if (n == 0)
        return 1;
    
    int half_pow = power(a, n / 2);
    int result = half_pow * half_pow;
    
    if (n % 2 == 1)
        result *= a;
    
    return result;
}

int main() {
    int a = 2;
    int n = 10;
    
    int result = power(a, n);
    
    std::cout << a << "^" << n << " = " << result << std::endl;
    
    return 0;
}