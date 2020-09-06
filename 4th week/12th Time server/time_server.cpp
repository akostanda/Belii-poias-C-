#include <iostream>
#include <exception>
#include <string>
using namespace std;

// string AskTimeServer() {
//     int n;
//     cin >> n;
//     string last_fetched_time = "00:00:00";
//     if (n == 0)
//         last_fetched_time = "01:01:01";
//     else if (n == 1)
//         throw system_error(error_code());
//     else
//         throw exception();
//     return last_fetched_time;
// }

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer();
        }
        catch (system_error&) {
        }
        return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};

// int main() {
//     // AskTimeServer();
//     TimeServer ts;
//     try {
//         cout << ts.GetCurrentTime() << endl;
//     } catch (exception& e) {
//         cout << "Exception got: " << e.what() << endl;
//     }
//     return 0;
// }
