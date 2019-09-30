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
    string A;
    cin >> A;
    int n = A.size();

    int next[n+1][26]; // i???????????c?????index(????????n)
    fill(next[0], next[n+1], n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) next[i][j] = next[i+1][j];
        next[i][A[i] - 'a'] = i;
    }

    int dp[n+1]; // i???????????????????????????
    fill(dp, dp+n+1, 1 << 30);

    vector < pair<char, int> > restoration(n+1, make_pair('?', n)); // ???????

    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if (next[i][j] == n) {
                if (dp[i] > 1) {
                    dp[i] = 1;
                    restoration[i] = make_pair('a'+j, n);
                }
            } else if (dp[i] > dp[next[i][j] + 1] + 1) {
                dp[i] = dp[next[i][j] + 1] + 1;
                restoration[i] = make_pair('a'+j, next[i][j] + 1);
            }
        }
    }

    string ret = "";
    int idx = 0;
    while (idx < n) {
        auto p = restoration[idx];
        ret += p.first;
        idx = p.second;
    }

    cout << ret << "\n";
    return 0;
}