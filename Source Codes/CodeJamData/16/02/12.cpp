#include <iostream>

using namespace std;

int t;
string s;

void solve(int x) {
    cin >> s;
    cout << "Case #" << x << ": ";
    s += "+";
    int c = 0;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] != s[i+1]) c++;
    }
    cout << c << "\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
