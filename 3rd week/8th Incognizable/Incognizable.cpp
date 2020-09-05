#include <iostream>

using namespace std;

class Incognizable {
    public:
    Incognizable() {
        first = 0;
        second = 0;
    }
    Incognizable(const int& new_first) {
        first = new_first;
    }
    Incognizable(const int& new_first, const int& new_second) {
        first = new_first;
        second = new_second;
    }
    private:
        int first;
        int second;
};