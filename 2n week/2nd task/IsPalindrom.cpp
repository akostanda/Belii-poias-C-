#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str) {
    int size = str.size();

    if (size <= 1) {
        return true;
    }
    else {
        for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
            if (str[i] != str[j])
                return false;
        }
        return true;
    }
}

int main() {
    cout << isPalindrom("mmadamm");
    return 0;
}
