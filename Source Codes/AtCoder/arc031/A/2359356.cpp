#include <iostream>
#include <algorithm>

using namespace std;

int main () {

    string s;
    cin >> s;

    bool reversible = true;
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            reversible = false;
            break;
        }
    }
    cout << ((reversible)? "YES" : "NO") << endl;

    return 0;
}