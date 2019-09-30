#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int cnt[n][26];
    fill(cnt[0], cnt[n], 0);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) cnt[i][c - 'a']++;
    }

    string ret = "";
    for (int i = 0; i < 26; i++) {
        int mn = 50;
        for (int j = 0; j < n; j++) {
            mn = min(mn, cnt[j][i]);
        }

        for (int j = 0; j < mn; j++) {
            ret += 'a' + i;
        }
    }

    cout << ret << "\n";
    return 0;
}