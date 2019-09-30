#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main() {

    string s;
    cin >> s;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int i = 0; i < a; i++) {
        cout << s[i];
    }
    cout << "\"";

    for (int i = a; i < b; i++) {
        cout << s[i];
    }
    cout << "\"";

    for (int i = b; i < c; i++) {
        cout << s[i];
    }
    cout << "\"";

    for (int i = c; i < d; i++) {
        cout << s[i];
    }
    cout << "\"";

    for (int i = d; i < s.size(); i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}