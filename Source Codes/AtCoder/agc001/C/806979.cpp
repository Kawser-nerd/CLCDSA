#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 2020;
int n;
vector<int> g[MN];

int dfs(int p, int b, int k, int dps = 0) {
    int ans = 0;
    if (dps >= k) ans++;
    for (int d : g[p]) {
        if (d == b) continue;
        ans += dfs(d, p, k, dps+1);
    }
    return ans;
}
int main() {
    int k;
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        int co = 0;
        for (int s: g[i]) {
            co += dfs(s, i, k/2);
        }
        ans = min(ans, co);
    }
    for (int s = 0; s < n; s++) {
        for (int t: g[s]) {
            int co = dfs(s, t, (k+1)/2)+dfs(t, s, (k+1)/2);
            ans = min(ans, co);
        }
    }
    cout << ans << endl;
    return 0;
}