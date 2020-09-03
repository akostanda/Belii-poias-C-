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

bool IsCountry(const string& country, const string& capital, string& old_c,
               bool& isTrigger, map<string, string>& countryCapitals) {
    for (auto cont : countryCapitals) {
        if (cont.first == country) {
            if (cont.second == capital)
                isTrigger = true;
            else
                old_c = cont.second;
            return true;
        }
    }
    return false;
}

void ChangeCapital(map<string, string>& countryCapitals) {
    bool isTrigger = false;
    string old_c;
    string str1;
    string str2;

    cin >> str1 >> str2;
    if (!IsCountry(str1, str2, old_c, isTrigger, countryCapitals)) {
        countryCapitals[str1] = str2;
        cout << "Introduce new country " << str1 << " with capital "
             << str2 << endl;
    }
    else if (IsCountry(str1, str2, old_c, isTrigger, countryCapitals)
             && isTrigger) {
        cout << "Country " << str1 << " hasn't changed its capital"
             << endl;
    }
    else if (IsCountry(str1, str2, old_c, isTrigger, countryCapitals)) {
        countryCapitals[str1] = str2;
        cout << "Country " << str1 << " has changed its capital from "
             << old_c << " to " << str2 << endl;
    }
}

void RenameCountry(map<string, string>& countryCapitals) {
    string str1;
    string str2;

    cin >> str1 >> str2;
    if (str1 != str2 && countryCapitals.count(str1) > 0
        && countryCapitals.count(str2) == 0) {
        countryCapitals[str2] = countryCapitals[str1];
        countryCapitals.erase(str1);
        cout << "Country " << str1 << " with capital " << countryCapitals[str2]
             << " has been renamed to " << str2 << endl;
    }
    else
        cout << "Incorrect rename, skip" << endl;
}

void AboutCountry(map<string, string>& countryCapitals) {
    string str1;

    cin >> str1;
    if (countryCapitals.count(str1) > 0) {
        cout << "Country " << str1 << " has capital " << countryCapitals[str1]
             << endl;
    }
    else
        cout << "Country " << str1 << " doesn't exist" << endl;
}

void DumpCountry(map<string, string>& countryCapitals) {
    string str1;

    if (countryCapitals.size() == 0) {
        cout << "There are no countries in the world" << endl;
    }
    else {
        for (auto m : countryCapitals)
            cout << m.first << "/" << m.second << " ";
    }
}

int main() {
    int n;
    string command;
    map<string, string> countryCapitals;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "CHANGE_CAPITAL")
            ChangeCapital(countryCapitals);
        else if (command == "RENAME")
            RenameCountry(countryCapitals);
        else if (command == "ABOUT")
            AboutCountry(countryCapitals);
        else if (command == "DUMP")
            DumpCountry(countryCapitals);
    }
    return 0;
}
