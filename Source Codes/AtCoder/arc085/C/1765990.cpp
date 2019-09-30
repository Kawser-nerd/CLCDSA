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

using ll = long long;

int N;
ll a[105];

int broken[105];
ll dfs(int v) {
    if (v >= min(35, N)) {
        ll ret = 0;
        for (int j = v; j <= N; ++j) {
            if (j % 2 == 0 && j / 2 >= v) continue;
            if (broken[j] == 0) {
                if (2*j > N || broken[2*j] > 0) {
                    ret += max(0LL, a[j]);
                } else {
                    ret += max(0LL, max(a[j], a[j]+a[2*j]));
                }
            }
        }
        return ret;
    }

    if (broken[v] > 0) return dfs(v+1);

    // nope
    ll ans = a[v] + dfs(v+1);

    // break
    for (int w = v; w <= N; w += v) {
        broken[w]++;
    }
    ans = max(ans, dfs(v+1));
    for (int w = v; w <= N; w += v) {
        broken[w]--;
    }

    return ans;
}

int main() {
    fill(broken, broken+105, 0);
    cin >> N;
    for (int j = 1; j <= N; ++j) cin >> a[j];
    cout << dfs(1) << endl;
    return 0;
}