#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream output ("output.txt");
    ifstream input("input.txt");
    string line;
    while (getline(input, line))
        output << line << "\n";
    return 0;
}