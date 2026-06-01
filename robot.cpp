#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    while (true) {
        getline(cin, input);

        if (input == "EXIT") {
            break;
        }

        // Check CMD
        if (input.find("CMD|") == 0) {

            // Find positions of '|'
            int first = input.find('|');
            int second = input.find('|', first + 1);

            // Extract ID and command
            string id = input.substr(first + 1, second - first - 1);
            string cmd = input.substr(second + 1);

            // 1. ACK
            cout << "ACK|" << id << endl;

            // 2. BUSY
           cout << "STAT|" << id << "|BUSY" << endl;

            // 3. Do work
            if (cmd == "PICK") {
                cout << "EVT|" << id << "|PICK_DONE" << endl;
            }
            else if (cmd == "PLACE") {
                cout << "EVT|" << id << "|PLACE_DONE" << endl;
            }
            else {
                cout << "EVT|" << id << "|UNKNOWN_CMD" << endl;
            }

            // 4. IDLE
            cout << "STAT|" << id << "|IDLE" << endl;
        }
    }

    return 0;
}