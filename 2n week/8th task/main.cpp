#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int daytemp;
    int tempsum = 0;
    int averagetemp;
    vector<int> upertemp;

    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> daytemp;
        temp[i] = daytemp;
        tempsum += daytemp;
    }
    averagetemp = tempsum / n;
    tempsum = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] > averagetemp) {
            upertemp.push_back(i);
            tempsum++;
        }
    }
    cout << tempsum << endl;
    for (auto i : upertemp) {
        cout << i << " ";
    }
    return 0;
}
