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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, x;
    cin >> N >> x;

    vector<int> a(N);
    vector<int> mina(N);

    REP(i, N) {
        cin >> a[i];
        mina[i] = INF;
    }

    a.insert(a.end(), a.begin(), a.end());

    int ans = INF;
    REP(k, N) {
        int tmp = k * x;
        REP(i, N) {
            int t = N + i;
            mina[i] = min(mina[i], a[t - k]);
            tmp += mina[i];
        }
        ans = min(tmp, ans);
    }
    cout << ans << endl;


    return 0;
}