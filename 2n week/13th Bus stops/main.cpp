#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// bool HasStop(string stop, const vector<string>& stops) {
//     for (const auto& st : stops) {
//         if (st == stop)
//             return true;
//     }
//     return false;
// }

void BusAdding(map<string, vector<string>>& busesStops, map<string, vector<string>>& stopsBuses) {
    int stop_count;
    string bus;
    string stop;

    cin >> bus >> stop_count;
    for (int i = 0; i < stop_count; i++) {
        // cout << "i_BusAdding: " << i << endl;//
        cin >> stop;
        busesStops[bus].push_back(stop);
        stopsBuses[stop].push_back(bus);
    }
}

void BusesForStop(map<string, vector<string>>& busesStops, map<string, vector<string>>& stopsBuses) {
    string stop;

    cin >> stop;
    if (stopsBuses.count(stop) > 0) {
        for (const auto& v : stopsBuses[stop]) {
            cout << v << " ";
        }
    }
    else
        cout << "No stop";
    cout << endl;
}

void StopsForBus(map<string, vector<string>>& busesStops, map<string, vector<string>>& stopsBuses) {
    string bus;
    int count = 0;

    cin >> bus;
    if (busesStops.count(bus) == 0)
        cout << "No bus" << endl;
    else {
        for (const auto& v : busesStops[bus]) {
            cout << "Stop " << v << ":";
            for (const auto& vv : stopsBuses[v]) {
                if (vv != bus) {
                    cout << " " << vv ;
                    count++;
                }
            }
            if (count == 0)
                cout << " no interchange";
            cout << endl;
            count = 0;
        }
    }
}

void AllBuses(map<string, vector<string>>& busesStops) {
    string stop;

    if (busesStops.size() == 0)
        cout << "No buses" << endl;
    else {
        for (const auto& m : busesStops) {
            cout << "Bus " << m.first << ":";
            for (const auto& v : m.second) {
                cout << " " << v;
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    string bus;
    int stop_count;
    string command;
    map<string, vector<string>> busesStops;
    map<string, vector<string>> stopsBuses;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command;
        // cout << "i_main: " << i << endl;//
        if (command == "NEW_BUS")
            BusAdding(busesStops, stopsBuses);
        else if (command == "BUSES_FOR_STOP")
            BusesForStop(busesStops, stopsBuses);
        else if (command == "STOPS_FOR_BUS")
            StopsForBus(busesStops, stopsBuses);
        else if (command == "ALL_BUSES")
            AllBuses(busesStops);
    }
    return 0;
}
