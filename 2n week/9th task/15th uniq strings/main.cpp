#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    string str;
    set<string> uniq_string;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        uniq_string.insert(str);
    }
    cout << uniq_string.size();
    return 0;
}