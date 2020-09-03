#include <iostream>
#include <string>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> pwords;

    for (auto w : words) {
        if (IsPalindrom(w) && w.size() >= minLength) {
            pwords.push_back(w);
        }
    }
    return pwords;
}

int main() {
    vector<string> words;
    vector<string> pwords;

    words.push_back("abacaba");
    words.push_back("aba");
    pwords = PalindromFilter(words, 9);
    for (auto w : words) {
        cout << w << " ";
    }
    cout << endl;
    for (auto w : pwords) {
        cout << w << " ";
    }
    return 0;
}
