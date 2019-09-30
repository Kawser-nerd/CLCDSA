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

using R = double;
using P = array<R, 3>;
const int MN = 1010;
int N;
R S;
P po[MN], v[MN];

R dist(P l, P r) {
    R sm = 0;
    for (int i = 0; i < 3; i++) {
        sm += (l[i]-r[i])*(l[i]-r[i]);
    }
    return sqrt(sm);
}
bool calc(R md) {
    bool used[MN] = {};
    queue<int> q;
    q.push(0);
    while (q.size()) {
        int p = q.front(); q.pop();
        if (used[p]) continue;
        used[p] = true;
        if (p == 1) return true;
        for (int j = 0; j < N; j++) {
            if (dist(po[p], po[j]) < md) {
                q.push(j);
            }
        }
    }
    return false;
}
void solve() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        R a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        po[i] = P{a, b, c};
        v[i] = P{d, e, f};
    }
    R l = 0, r = 1e10;
    for (int i = 0; i < 300; i++) {
        R md = (l+r)/2;
        if (!calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    printf("%.20lf\n", l);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}