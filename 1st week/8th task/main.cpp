#include <iostream>
using namespace std;

int main() {
    int a, b, size, delim;
    int flag = 0;

    cin >> a >> b;
    if (a == b) {
        cout << a;
        return 0;
    }
    else if (a == 0) {
        cout << b;
        return 0;
    }
    else if (b == 0) {
        cout << a;
        return 0;
    }
    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    cout << a + b;
    return 0;
}
