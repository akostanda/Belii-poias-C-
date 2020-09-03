#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool Is_Cyn(string word, const set<string>& synonyms) {
    for (const auto& s : synonyms) {
        if (s == word) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    string command, word1, word2;
    map<string, set<string>> synonym;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        // cout << "i_main: " << i << endl;//
        if (command == "ADD") {
            cin >> word1 >> word2;
            synonym[word1].insert(word2);
            synonym[word2].insert(word1);
        }
            // WordAdding(busesStops, stopsBuses);
        else if (command == "COUNT") {
            cin >> word1;
            cout << synonym[word1].size() << endl;
        }
            // BusesForStop(busesStops, stopsBuses);
        else if (command == "CHECK") {
            cin >> word1 >> word2;
            if (Is_Cyn(word2, synonym[word1]))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
            // StopsForBus(busesStops, stopsBuses);
    }
    return 0;
}