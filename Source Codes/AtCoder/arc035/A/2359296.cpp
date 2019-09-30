#include <iostream>
#include <algorithm>

using namespace std;

string solve (string s) {

    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        if (s[i] != '*' && s[j] != '*' && s[i] != s[j]) {
            return "NO";
        }
    }
    
    return "YES";
}

int main () {

    string s;
    cin >> s;

    cout << solve(s) << endl;

    return 0;
}