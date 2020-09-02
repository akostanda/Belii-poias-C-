#include <iostream>
using namespace std;

int main() {
    string str;
    int flag = 0;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'f') {
            flag++;
            if (flag == 2) {
                cout << i;
                break;
            }
        }
    }
    if (flag == 1) {
        cout << -1;
    }
    else if (flag == 0) {
        cout << -2;
    }
    return 0;
}
