#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') cnt++;
        else ans += cnt;
    }
    cout << ans << endl;
    return 0;
}