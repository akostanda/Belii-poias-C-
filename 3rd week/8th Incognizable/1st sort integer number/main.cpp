#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int i, int j) {
    return abs(i) < abs(j);
}

int main() {
    int q;
    int n;
    vector<int> interges;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n;
        interges.push_back(n);
    }
    sort(begin(interges), end(interges), comp);
    for (auto& i : interges)
        cout << i << " ";
    return 0;
}