#include <iostream>
using namespace std;

int Factorial(int n) {
    int fact = 1;

    if (n > 0) {
        for (int i = 1; i <= n; i++)
            fact *= i;
    }
    return fact;
}
