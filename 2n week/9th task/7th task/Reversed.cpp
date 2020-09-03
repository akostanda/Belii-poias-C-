#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
    vector<int> copy;
    int size = v.size();

    for (int i = 0; i < size; i++) {
        copy.push_back(v[size - i - 1]);
    }
    return copy;
}

// int main() {
//     vector<int> numbers = {-7, -6, -5, -4, -3, -2, -1 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//     vector<int> copy;

//     for (auto w : numbers) {
//         cout << w << " ";
//     }
//     copy = Reversed(numbers);
//     cout << endl;
//     for (auto w : copy) {
//         cout << w << " ";
//     }
//     return 0;
// }
