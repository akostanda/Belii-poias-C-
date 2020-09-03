#include <iostream>
#include <string>
#include <map>

using namespace std;

map <char, int> BuildCharCounters(const string& str) {
    map<char, int> charCounter;

    for (char c : str) {
        ++charCounter[c];
    }
    return charCounter;
}

bool IsAnagram(const string& str1, const string& str2) {
    map<char, int> charCounter1;
    map<char, int> charCounter2;

    charCounter1 = BuildCharCounters(str1);
    charCounter2 = BuildCharCounters(str2);
    if (charCounter1.size() != charCounter2.size())
        return false;
    for (int i = 0; i < charCounter1.size(); i++) {
        if (charCounter1[i] != charCounter2[i])
            return false;
    }
    return true;
}

int main() {
    int n;
    string str1;
    string str2;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2;
        if (str1.size() != str2.size() || !IsAnagram(str1, str2))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
