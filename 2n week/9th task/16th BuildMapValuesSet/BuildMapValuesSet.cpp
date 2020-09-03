#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> values;

    for (auto& value : m) {
        values.insert(value.second);
    }
    return values;
}