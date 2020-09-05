#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    string str;
    vector<string> interges;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> str;
        interges.push_back(str);
    }
    sort(begin(interges), end(interges), [](string str1, string str2) {
        int i = 0;
        for (; i < str1.size(); i++) {
            if (tolower(str1[i]) != tolower(str2[i]))
                break;
        }
        return tolower(str1[i]) < tolower(str2[i]);
    });
    for (auto& i : interges)
        cout << i << " ";
    return 0;
}