#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool flg = true;
    int cnt = 0;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == 'C' && 2 <= i && i <= s.length() - 2) {
            cnt++;
        } else if (s[i] != 'C' && (s[i] < 'a' || 'z' < s[i])) {
            flg = false;
        }
    }
    if (s[0] != 'A' || cnt != 1) flg = false;

    cout << (flg ? "AC" : "WA") << endl;
}