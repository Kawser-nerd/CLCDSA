#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

double memo[5000][5000]; // right, total

double f(int y, int h, int n) {
    memset(memo, 0, sizeof memo);
    memo[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int r = 0; r <= i; ++r) {
            if (r < h - 1 && i - r < h - 1) {
                memo[i+1][r] += memo[i][r] * 0.5;
                memo[i+1][r + 1] += memo[i][r] * 0.5;
            } else {
                if (r == h - 1)
                    memo[i+1][r] += memo[i][r];
                else
                    memo[i+1][r+1] += memo[i][r];
            }
        }
    }
    double res = 0;
    for (int r = y; r <= h; ++r)
        res += memo[n][r];
    return res;
}

void solve() {
    double ans = 0;
    int N, X, Y;
    cin >> N >> X >> Y;
    if (X < 0) X = -X;

    int n = 1;
    int k;
    while (n*(2*n - 1) <= N) ++n;
    --n;
    k = N - n*(2*n - 1);
    // -n..n full

    cerr << n << ' ' << k << endl;

    if (X + Y < 2 * n) ans = 1;
    else {
        if (X + Y < 2*n + 2) {
            ans = f(Y + 1, 2*n + 1, k);
        }
    }

    static int testid;
    cout << fixed;
    cout.precision(10);
    cout << "Case #" << ++testid << ": " << ans << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();
    return 0;
}
