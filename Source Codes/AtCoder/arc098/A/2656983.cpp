#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> c(n + 1);

    for(int i = 0; i < n; i++) {
        c[i + 1] = c[i] + (s[i] == 'E');
    }

    int ans = 1 << 26;
    for(int i = 0; i < n; i++) {
        ans = min(ans, (i - c[i]) + (c[n] - c[i + 1]));
    }

    cout << ans << endl;
}