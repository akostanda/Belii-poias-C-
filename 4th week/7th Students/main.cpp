#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string first_name;
    string second_name;
    int day;
    int month;
    int year;
};

int main() {
    int n = 0;
    int student_number;
    string request;
    Student student;
    vector<Student> all_students;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> student.first_name >> student.second_name;
        cin >> student.day >> student.month >> student.year;
        all_students.push_back(student);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> request >> student_number;
        if (request == "name" && student_number <= all_students.size() && student_number > 0) {
            cout << all_students[student_number - 1].first_name << " ";
            cout << all_students[student_number - 1].second_name << "\n";
        }
        else if (request == "date" && student_number <= all_students.size() && student_number > 0) {
            cout << all_students[student_number - 1].day << "." << all_students[student_number - 1].month;
            cout << "." << all_students[student_number - 1].year << "\n";
        }
        else
            cout << "bad request\n";
    }
    return 0;
}