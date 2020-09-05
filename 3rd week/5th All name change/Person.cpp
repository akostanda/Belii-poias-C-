#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int GetYear(int year, map<int, string> name) {
    int result_year = year;

    if (name.count(year) == 0) {
        for (const auto& f : name) {
            if (f.first < year)
                result_year = f.first;
            else
                break;
        }
    }
    return result_year;
}

string GetName(int year, map<int, string> name) {
    string result_name = "";
    vector<string> all_name;
    vector<string> all_name2;
    int trigger = 0;
    int i = 0;

    if (name.count(year) != 0) {
        for (const auto& n : name) {
            all_name.push_back(n.second);
            if (n.first == year)
                break;
        }
        all_name2.push_back(all_name[all_name.size() - 1]);
        for (i = all_name.size() - 2; i >= 0; i--) {
            if (all_name[i] != all_name[i + 1])
                all_name2.push_back(all_name[i]);
        }
        result_name = all_name2[0];
        for (i = 1; i < all_name2.size(); i++) {
            if (trigger == 0) {
                trigger++;
                result_name += " (" + all_name2[i];
            }
            else
                result_name += ", " + all_name2[i];
        }
        if (result_name != all_name2[all_name2.size() - 1])
            result_name += ")";
            
    }
    return result_name;
}

class Person {
    public:
    void ChangeFirstName(int year, const string& first_name) {
        firstName[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        lastName[year] = last_name;
    }
    string GetFullName(int year) {
        string fullName;
        int first_year = GetYear(year, firstName);
        int last_year = GetYear(year, lastName);

        if (firstName.count(first_year) == 0 && lastName.count(last_year) == 0)
            fullName = "Incognito";
        else if (lastName.count(last_year) == 0)
            fullName = firstName[first_year] + " with unknown last name";
        else if (firstName.count(first_year) == 0)
            fullName = lastName[last_year] + " with unknown first name";
        else
            fullName = (firstName[first_year] + " " + lastName[last_year]);
        return fullName;
    }
    string GetFullNameWithHistory(int year) {
        string fullName;
        string firstTempName;
        string lastTempName;
        int first_year = GetYear(year, firstName);
        int last_year = GetYear(year, lastName);

        if (firstName.count(first_year) == 0 && lastName.count(last_year) == 0)
            fullName = "Incognito";
        else {
            firstTempName = GetName(first_year, firstName);
            lastTempName = GetName(last_year, lastName);
            if (lastTempName.size() == 0)
                fullName = firstTempName + " with unknown last name";
            else if (firstTempName.size() == 0)
                fullName = lastTempName + " with unknown first name";
            else
                fullName = (firstTempName + " " + lastTempName);
        }
        return fullName;
    }
    private:
        map<int, string> firstName;
        map<int, string> lastName;
};
