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

typedef tuple<int, int, int, int> Area;
map<Area, int> memo;

int W, H, N;
int x[40], y[40];

int count(int x1, int y1, int x2, int y2) {
    if (memo.count(Area{x1, y1, x2, y2})) return memo[Area{x1, y1, x2, y2}];
    if (x1 > x2 || y1 > y2) return 0;

    int res = 0;
    REP(i, N) {
        if (x1 <= x[i] && x[i] <= x2 && y1 <= y[i] && y[i] <= y2) {
            int got = x2 - x1 + y2 - y1 + 1;
            res = max(res, got + count(x1, y1, x[i] - 1, y[i] - 1) + count(x1, y[i] + 1, x[i] - 1, y2) +
                           count(x[i] + 1, y1, x2, y[i] - 1) + count(x[i] + 1, y[i] + 1, x2, y2));
        }
    }

    return memo[Area{x1, y1, x2, y2}] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> W >> H >> N;
    REP(i, N) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        x[i] = a;
        y[i] = b;
    }

    cout << count(0, 0, W - 1, H - 1) << endl;

    return 0;
}