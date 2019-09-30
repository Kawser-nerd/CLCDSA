#include <iostream>
#include <algorithm>

using namespace std;

int count (string s, char ch) {

    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ch) {
            cnt++;
        }
    }

    return cnt;
}

int main () {

    int n;
    cin >> n;

    int red = 0, blue = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        red += count(s, 'R');
        blue += count(s, 'B');
    }

    if (blue < red) {
        cout << "TAKAHASHI" << endl;

    } else if (red < blue) {
        cout << "AOKI" << endl;

    } else {
        cout << "DRAW" << endl;
    }

    return 0;
}