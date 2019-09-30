#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = long long;

int N, X[1000];

struct R {
    int a, b;
    R() {} R(int c, int d): a(c), b(d) {}
};

vector<int> children[1000];

int dp[5050];

R dfs(int v) {
    vector<R> cr;
    for (int w : children[v]) {
        R r = dfs(w);
        if (r.a == -1 && r.b == -1) {
            return R(-1, -1);
        }
        if (r.a > r.b) {
            swap(r.a, r.b);
        }
        cr.push_back(r);
    }
    int base = 0, ss = 0;
    vector<int> ds;
    for (R& r : cr) {
        base += r.a; ss += r.a + r.b;
        ds.push_back(r.b - r.a);
    }
    if (base > X[v]) {
        return R(-1, -1);
    }

    int L = X[v]-base;
    fill(dp, dp+L+1, 0);
    dp[0] = 1;
    for (const int& x: ds) {
        for (int k = L; k >= x; --k) {
            if (dp[k-x]) {
                dp[k] = 1;
            }
        }
    }
    int z = -1;
    for (int j = L; j >= 0; --j) {
        if (dp[j]) {
            z = j;
            break;
        }
    }
    if (z == -1) {
        return R(-1, -1);
    }
    return R(X[v], ss - (z+base));
}

int main() {
    cin >> N;
    for (int j = 0; j < N-1; ++j) {
        int p; cin >> p;
        children[--p].push_back(j+1);
    }
    for (int j = 0; j < N; ++j) {
        cin >> X[j];
    }

    R result = dfs(0);
    cout << (result.a == -1 || result.b == -1 ? "IMPOSSIBLE" : "POSSIBLE") << endl;
    return 0;
}