#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flag = true;
    int count = 0;

    if (s[0] != 'A') flag = false;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'C' && 2 <= i && i <= s.length() - 2) {
            count++;
        } else if (s[i] != 'C' && (s[i] < 'a' || 'z' < s[i])) {
            flag = false;
        }
    }
    if (count != 1) flag = false;

    cout << (flag ? "AC" : "WA") << endl;
}