#include <iostream>
#include <vector>
#include<string>

using namespace std;

int n;
string s;
string ans;
string cand[] = {"SS", "SW", "WS", "WW"};

bool build() {
    // cout << s << endl;
    // cout << ans << endl;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'o') {
            ans += ans[i - 1];
        } else {
            ans += ans[i - 1] == 'S' ? 'W' : 'S';
        }
        if (ans[i] == 'W') {
            ans[i + 1] = ans[i + 1] == 'S' ? 'W' : 'S';
        }
    }
    //cout << ans << endl;
    if (ans[0] != ans[n]) return false;
    ans = ans.substr(0, n);
    bool valid = ans[1] == ans[n - 1];
    if (s[0] == 'x') valid = !valid;
    if (ans[0] == 'W') valid = !valid;
    return valid;
}

int main(){
    cin >> n >> s;

    for (int i = 0; i < 4; ++i) {
        ans = cand[i];
        if (build()) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}