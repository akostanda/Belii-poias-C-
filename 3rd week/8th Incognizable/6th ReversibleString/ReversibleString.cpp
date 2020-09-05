#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ReversibleString {
    public:
    ReversibleString () {}
    ReversibleString (string new_str) {
        str = new_str;
    }
    void Reverse() {
        reverse(str.begin(), str.end());
    }
    string ToString() const{
        return str;
    }
    private:
    string str;
};