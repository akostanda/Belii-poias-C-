#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CountWorry(const vector<bool>& v) {
    int size = v.size();
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (v[i] == true)
            count++;
    }
    return count;
}

int main() {
    int n;
    int k;
    int size;
    string str;
    vector<bool> queue;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str != "WORRY_COUNT") {
            cin >> k;
            if (str == "COME" && k > 0) {
                if (queue.size() == 0) {
                    for (int j = 0; j < k; j++)
                        queue.push_back(false);
                }
                else
                    queue.resize(queue.size() + k, false);
// cout << "queue:" << endl;
// for (int i = 0; i < queue.size(); i++) {
//     cout << queue[i] << endl;
// }
            }
            else if (str == "COME" && k < 0) {
                queue.resize(queue.size() + k);
// cout << "queue:" << endl;
// for (int i = 0; i < queue.size(); i++) {
//     cout << queue[i] << endl;
// }
            }
            else if (str == "WORRY") {
                queue[k] = true;
// cout << "queue:" << endl;
// for (int i = 0; i < queue.size(); i++) {
//     cout << queue[i] << endl;
// }
            }
            else if (str == "QUIET") {
                queue[k] = false;
// cout << "queue:" << endl;
// for (int i = 0; i < queue.size(); i++) {
//     cout << queue[i] << endl;
// }
            }
        }
        else {
            size = CountWorry(queue);
            cout << size << endl;
        }
    }
}
