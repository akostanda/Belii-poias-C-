#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
// #include <regex>

using namespace std;

class Date {
public:
    Date (int year, int month, int day) : m_year(year), m_month(month), m_day(day) {}

    int GetYear() const {
        return m_year;
    }
    int GetMonth() const {
        return m_month;
    }
    int GetDay() const {
        return m_day;
    }

private:
    const int m_year;
    const int m_month;
    const int m_day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    else
        return lhs.GetDay() < rhs.GetDay();
}

string dateFormat (const Date& date) {
    string year = to_string(date.GetYear());
    string month = to_string(date.GetMonth());
    string day = to_string(date.GetDay());
    while (year.size() != 4)
        year = "0" + year;
    while (month.size() != 2)
        month = "0" + month;
    while (day.size() != 2)
        day = "0" + day;
    return (year + "-" + month + "-" + day);
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
            dateEvent[date].insert(event); 
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (dateEvent.count(date) > 0) {
            for (auto& s : dateEvent.at(date)) {
                if (event == s) {
                    dateEvent.at(date).erase(s);
                    return true;
                }
            }
        }
        return false;
    }
    int DeleteDate(const Date& date) {
        int count = 0;
        if (dateEvent.count(date) > 0) {
            for (auto it = dateEvent.at(date).begin(); it != dateEvent.at(date).end(); it++)
                count++;
            dateEvent.at(date).clear();
        }
        return count;
    }

    void Find(const Date& date) const {
        if (dateEvent.count(date) > 0) {
            for (auto& s : dateEvent.at(date))
                cout << s << "\n";
        }
    }

    void Print() const {
        for (auto& de : dateEvent) {
            for (auto& s : de.second)
                cout << dateFormat(de.first) << " " << s << endl;
        }
    }

private:
    map<Date, set<string>> dateEvent;
};

void getDate(string& date, int& year, int& month, int& day) {
    istringstream dateStr;
    int signY = 1;
    int signM = 1;
    int signD = 1;

    if (*date.begin() == '-') {
        dateStr = istringstream(string(++date.begin(), date.end()));
        signY = -1;
    }
    else
        dateStr = istringstream(date);
    string number;
    getline(dateStr, number, '-');
    year = stoi(number) * signY;
    if (dateStr.peek() == '-') {
        dateStr.ignore(1);
        signM = -1;
    }
    getline(dateStr, number, '-');
    month = stoi(number) * signM;
    if (dateStr.peek() == '-') {
        dateStr.ignore(1);
        signD = -1;
    }
    getline(dateStr, number);
    day = stoi(number) * signD;
}

bool isDate(vector<string> coms, int& year, int& month, int& day) {
    // regex regular("((\\-|\\+)?[0-9]{1,4})\\-(\\-?\\+?[0-9]{1,2})\\-(\\-?\\+?[0-9]{1,2})");
    // if (regex_match(coms[1], regular) == false) {
    //     cout << "Wrong date format: " << coms[1] << endl;
    //     return false;
    // }
    try {
        char def1, def2;
        stringstream dateStr(coms[1]);
        dateStr >> year >> def1 >> month >> def2 >> day;
        if (def1 != '-' || def2 != '-' || !dateStr.eof() || day == -2147483641)
            throw(1);
        getDate(coms[1], year, month, day);
        if (month < 1 || month > 12) {
            cout << "Month value is invalid: " << month << endl;
            return false;
        }
        else if (day < 1 || day > 31) {
            cout << "Day value is invalid: " << day << endl;
            return false;
        }
    }
    catch (...) {
        cout << "Wrong date format: " << coms[1] << endl;
        return false;
    }
    return true;
}

int main() {
    Database db;
    string command;
    while (getline(cin, command)) {
        istringstream line(command);
        vector<string> coms;
        while (!line.eof()) {
            string str;
            line >> str;
            coms.push_back(str);
        }
        int year;
        int month;
        int day = -2147483641;
        if (coms[0] == "Add") {
            if (isDate(coms, year, month, day) && coms.size() == 3) {
                Date date(year, month, day);
                db.AddEvent(date, coms[2]);
            }
        }
        else if (coms[0] == "Del") {
            if (isDate(coms, year, month, day)) {
                Date date(year, month, day);
                if (coms.size() == 3) {
                    if (db.DeleteEvent(date, coms[2])) 
                        cout << "Deleted successfully" << endl;
                    else
                        cout << "Event not found" << endl;
                }
                else {
                    cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
                    
                }
            }
        }
        else if (coms[0] == "Find") {
            if (isDate(coms, year, month, day) && coms.size() == 2) {
                Date date(year, month, day);
                db.Find(date);
            }
        }
        else if (coms[0] == "Print")
            db.Print();
        else if (coms[0] != "")
            cout << "Unknown command: " << coms[0] << endl;
    }
    return 0;
}
