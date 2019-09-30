#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

int mod = 1e9 + 7;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> C(N), dp(N + 1), pos(200005, -1);
    REP(i, N) cin >> C[i];

    dp[0] = 1;
    REP(i, C.size()) {
        int prev = pos[C[i]];
        pos[C[i]] = i;
        if (i > 0 && C[i] == C[i - 1]) {
            dp[i + 1] = dp[i];
            continue;
        }
        dp[i + 1] = dp[i];
        if (prev == -1 || prev == i - 1) continue;
        dp[i + 1] += dp[prev + 1];
        dp[i + 1] %= mod;
    }

    cout << dp[N] << endl;

    return 0;
}