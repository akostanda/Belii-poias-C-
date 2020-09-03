#include <iostream>
#include <vector>
using namespace std;

void Swap(int& a, int& b) {
    int buf;

    buf = a;
    a = b;
    b = buf;
}

void Reverse(vector<int>& v) {
    int size = v.size() / 2;

    for (int i = 0, j = v.size() - 1; i < size; i++, j--) {
        Swap(v[i], v[j]);
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (auto w : numbers) {
        cout << w << " ";
    }
    Reverse(numbers);
    cout << endl;
    for (auto w : numbers) {
        cout << w << " ";
    }
    return 0;
}