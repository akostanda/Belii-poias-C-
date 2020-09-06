#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int rows = 0;
    int columns = 0;
    int num = 0;

    input >> rows >> columns;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            input >> num;
            cout << setw(10) << num;
            input.ignore(1);
            if (j < columns -1)
                cout << " ";
        }
        if (i != rows - 1)
            cout << "\n";
    }
    return 0;
}