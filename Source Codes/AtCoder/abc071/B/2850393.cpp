#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    int alphabets[26] = {0};
    for (auto s: str) alphabets[s - 'a'] = 1;
    int offset = -1;
    for (int i = 0; i < 26; i++) {
        if (alphabets[i] == 0) {
            offset = i;
            break;
        }
    }

    if (offset > -1) cout <<  char(97 + offset) << endl;
    else             cout << "None" << endl;

    return 0;
}