#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        s = s[s.size()-1] + s.substr(0, s.size() - 1);
        if (s == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}