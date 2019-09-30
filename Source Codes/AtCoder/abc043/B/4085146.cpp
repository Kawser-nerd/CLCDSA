#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string out;
    unsigned long position = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            out += s[i];
            position++;
        } else if (s[i] == '1') {
            out += s[i];
            position++;
        } else {
            if (out.length() != 0) {
                out = out.substr(0, --position);
            }
        }
    }
    cout << out;

    return 0;
}