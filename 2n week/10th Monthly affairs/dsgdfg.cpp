#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n = 12;

    for (int i = -1; i >= -36; i--) {
        cout << i % n << endl;
    }
    return 0;
}