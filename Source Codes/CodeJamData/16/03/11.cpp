#include <iostream>

using namespace std;

int t;
int n, j;
typedef long long ll;

void lol(string s, int x) {
    ll t = 0, k = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        t += (s[i]-'0')*k;
        k *= x;
    }
    cout << " " << t;
}

int main() {
    cin >> t;
    cin >> n >> j;
    cout << "Case #1:\n";
    for (int b = 0; ; b++) {
        string s = "1";
        for (int i = 0; i < (n/2)-2; i++) {
            if (b&(1<<i)) s += "1";
            else s += "0";
        }
        s += "1";
        cout << s << s;
        for (int i = 2; i <= 10; i++) lol(s,i);
        cout << "\n";
        j--;
        if (j == 0) break;
    }
}
