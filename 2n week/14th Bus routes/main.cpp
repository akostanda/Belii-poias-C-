#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool Is_Route(const vector<string>& stops,
              const map<vector<string>, int>& routes, int& rout_number) {
    for (const auto& m : routes) {
        if (stops == m.first) {
            rout_number = m.second;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    int size = 0;
    int rout_number;
    int stop_number;
    string stop;
    vector<string> stops;
    map<vector<string>, int> routes;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stop_number;
        for (int j = 0; j < stop_number; j++) {
            cin >> stop;
            stops.push_back(stop);
        }
        if (!Is_Route(stops, routes, rout_number)) {
            size = routes.size();
            routes[stops] = size + 1;
            cout << "New bus " << size + 1 << endl;
        }
        else
            cout << "Already exists for " << rout_number << endl;
        stops.clear();
    }
    return 0;
}
