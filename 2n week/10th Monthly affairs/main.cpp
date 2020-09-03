#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    int monthIndex = 0;
    int k;
    string str;
    vector<int> daysAmout = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> month(31);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str == "NEXT") {
            if (monthIndex == 11) {
                monthIndex = 0;
            }
            else if (daysAmout[monthIndex] == daysAmout[monthIndex + 1]) {
                monthIndex = monthIndex + 1;
            }
            else if (daysAmout[monthIndex] < daysAmout[monthIndex + 1]) {
                month.resize(daysAmout[monthIndex + 1]);
                monthIndex = monthIndex + 1;
            }
            else if (daysAmout[monthIndex] > daysAmout[monthIndex + 1]) {
                vector<vector<string>> copyMonth;
                copyMonth.insert(begin(copyMonth), begin(month), end(month));
                month.resize(daysAmout[monthIndex + 1]);
                for (int i = (daysAmout[monthIndex + 1]); i < daysAmout[monthIndex]; i++) {
                    if (!copyMonth[i].empty()) {
                        month[(daysAmout[monthIndex + 1]) - 1].insert(end(month[(daysAmout[monthIndex + 1]) - 1]),
                        begin(copyMonth[i]), end(copyMonth[i]));
                    }
                }
                copyMonth.clear();
                monthIndex = monthIndex + 1;
            }
        }
        else {
            cin >> k;
            if (k <= daysAmout[monthIndex]) {
                if (str == "ADD") {
                    cin >> str;
                    month[k - 1].push_back(str);
                }
                else if (str == "DUMP") {
                    cout << month[k - 1].size() << " ";
                    for (int i = 0; i < month[k - 1].size(); i++) {
                        cout << month[k - 1][i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

// int main() {
//     int n;
//     int monthIndex = 0;
//     int k;
//     string str;
//     vector<int> daysAmout = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     vector<vector<string>> month(31);

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> str;
//         if (str == "NEXT") {

//             if (daysAmout[monthIndex] == 11) {
//                 monthIndex = 0;
//             }
//             else if (daysAmout[monthIndex] < daysAmout[monthIndex + 1]) {

//                 for (int i = daysAmout[monthIndex]; i < (daysAmout[monthIndex + 1]); i++) {
//                     month[i].push_back({});
//                 }
//                 monthIndex = monthIndex + 1;
//             }
//             else if (daysAmout[monthIndex] > daysAmout[monthIndex + 1]) {
//                 vector<vector<string>> copyMonth;
//                 copyMonth.insert(begin(copyMonth), begin(month), end(month));
// // cout << "copyMonth: "<< endl; //
// // for (int i = 0; i < copyMonth.size(); i++) { //
// //     cout << i + 1 << ": "; //
// //     for (int j = 0; j < copyMonth[i].size(); j++)
// //         cout << copyMonth[i][j] << " "; //
// //     cout << endl; //
// // }//
// // cout << "month1: "<< endl; //
// // for (int i = 0; i < month.size(); i++) { //
// //     cout << i + 1 << ": "; //
// //     for (int j = 0; j < month[i].size(); j++)
// //         cout << month[i][j] << " "; //
// //     cout << endl; //
// // }//
//                 month.resize(daysAmout[monthIndex + 1]);
// // cout << "month2: "<< endl; //
// // for (int i = 0; i < month.size(); i++) { //
// //     cout << i + 1 << ": "; //
// //     for (int j = 0; j < month[i].size(); j++)
// //         cout << month[i][j] << " "; //
// //     cout << endl; //
// // }//
// // cout << "(daysAmout[monthIndex + 1]): " << (daysAmout[monthIndex + 1]) << endl; //
// // cout << "(daysAmout[monthIndex]): " << (daysAmout[monthIndex]) << endl; //
//                 for (int i = (daysAmout[monthIndex + 1]); i < daysAmout[monthIndex]; i++) {
// // cout << "(daysAmout[monthIndex + 1]) - 1: " << (daysAmout[monthIndex + 1]) - 1 << endl; //
// // cout << "i: " << i << endl; //
//                     if (!copyMonth[i].empty()) {
//                     // cout << "1 "<< endl; //
//                         month[(daysAmout[monthIndex + 1]) - 1].insert(end(month[(daysAmout[monthIndex + 1]) - 1]),
//                         begin(copyMonth[i]), end(copyMonth[i]));
//                         // cout << "2 "<< endl; //
//                     }
//                     // cout << "3: "<< endl; //
//                 }
// // cout << "month3: "<< endl; //
// // for (int i = 0; i < month.size(); i++) { //
// //     cout << i + 1 << ": "; //
// //     for (int j = 0; j < month[i].size(); j++)
// //         cout << month[i][j] << " "; //
// //     cout << endl; //
// // }//
//                 monthIndex = monthIndex + 1;
//             }
//         }
//         else {
//             cin >> k;
//             if (str == "ADD") {
//                 cin >> str;
//                 month[k - 1].push_back(str);
//     // for (int i = 0; i < month[k - 1].size(); i++) { //
//     //     cout << month[k - 1][i] << endl; // 
//     // }//
//             }
//             else if (str == "DUMP") {
//                 cout << month[k - 1].size() << " ";
//                 for (int i = 0; i < month[k - 1].size(); i++) {
//                     cout << month[k - 1][i] << " ";
//                 }
//                 cout << endl;
//             }
//         }
//     }
// }
