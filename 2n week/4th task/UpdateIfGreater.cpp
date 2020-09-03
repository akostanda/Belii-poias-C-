#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second) {
    if (first > second)
        second = first;
}

int main() {
    int x = 5;
    int y = 3;

    UpdateIfGreater(4, y);
    cout << "y = " << y;
    return 0;
}