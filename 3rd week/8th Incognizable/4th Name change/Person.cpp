#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

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
        int first_year = year;
        int last_year = year;

        if (firstName.count(year) == 0) {
            for (const auto& f : firstName) {
                if (f.first < year)
                    first_year = f.first;
                else
                    break;
            }
        }
        if (lastName.count(year) == 0) {
            for (const auto& l : lastName) {
                if (l.first < year)
                    last_year = l.first;
                else
                    break;
            }
        }
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
    private:
        map<int, string> firstName;
        map<int, string> lastName;
};

// int main() {
//     Person person;

//     person.ChangeFirstName(1965, "Polina");
//     person.ChangeLastName(1967, "Sergeeva");
//     for (int year : {1900, 1965, 1990}) {
//         cout << person.GetFullName(year) << endl;
//     }
    
//     person.ChangeFirstName(1970, "Appolinaria");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullName(year) << endl;
//     }
    
//     person.ChangeLastName(1968, "Volkova");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullName(year) << endl;
//     }
    
//     return 0;
// }