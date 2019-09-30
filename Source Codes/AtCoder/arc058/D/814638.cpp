/**
 * ??????O(NK)
 */
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
 
vector<int> z_algo(string s) {
    int n = (int)s.size();
    vector<int> R(n+1); R[0] = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        int &k = R[i]; k = (j + R[j] <= i) ? 0 : min(j+R[j]-i, R[i-j]);
        while (i+k < n and s[k] == s[i+k]) k++;
        if (j + R[j] < i + R[i]) j = i;
    }
    R[0] = n;
    return R;
}

 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    vector<int> sz(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sz[i] = (int)a[i].size();
    }
    bool can[n][k+1];
    fill_n(can[n-1], k+1, false);
    can[n-1][k] = true;
    for (int i = n-1; i >= 1; i--) {
        for (int j = 0; j <= k; j++) {
            can[i-1][j] = can[i][j];
        }
        for (int j = 0; j <= k-sz[i]; j++) {
            can[i-1][j] |= can[i][j+sz[i]];
        }
    }
    bool ok[n][k+1];
    for (int i = 0; i < n; i++) {
        fill_n(ok[i], k+1, false);
    }
    vector<string> b(n+1);
    ok[0][0] = true;
    b[0] = "";
    for (int i = 0; i < n; i++) {
        string ab = a[i]+b[i];
        vector<int> zv = z_algo(ab);
        using P = pair<int, bool>;
        auto same = [&](int s, int ty) {
            if (ty == 0) {
                s += sz[i];
            }
            int u = min(sz[i], zv[s]);
            if (ty == 1) {
                u = min(u, sz[i]-s);
            }
            return u;
        };
        auto cmp = [&](const P &l, const P &r) {
            //-1: ls big
            // 0: equal
            // 1: rs big
            if (l.first == -1) return -1;
            if (!l.second and !r.second) return 0;
            if (!l.second) {
                if (l.first <= r.first) return 0;
                int u = same(r.first, 0);
                if (l.first <= r.first + u) return 0;
                return a[i][u] - b[i][r.first+u];
            }
            if (!r.second or l.first + (l.second ? sz[i] : 0) <= r.first) {
                int u = same(l.first, 0);
                if (u == sz[i]) return 0;
                return b[i][l.first+u] - a[i][u];
            }
            int u = same(l.first, 0);
            if (u < r.first-l.first) {
                return b[i][l.first+u] - a[i][u];
            }
            int v = same(r.first-l.first, 1);
            if (v+r.first-l.first == sz[i]) return 0;
            return a[i][v] - a[i][v+r.first-l.first];
        };
        vector<P> buf(k+1);
        fill_n(buf.begin(), k+1, P(-1, false));
        P mi = P(-1, false);
        for (int j = 0; j <= k; j++) {
            if (!can[i][j]) continue;
            if (ok[i][j]) {
                P p = P(j, false);
                if (cmp(buf[j], p) <= 0) {
                    buf[j] = p;
                }
            }
            if (j >= sz[i] and ok[i][j-sz[i]]) {
                P p = P(j-sz[i], true);
                if (cmp(buf[j], p) <= 0) {
                    buf[j] = p;
                }
            }
            if (buf[j].first == -1) continue;
            if (cmp(mi, buf[j]) <= 0) {
                mi = buf[j];
            }
        }
        assert(mi.first != -1);
        b[i+1] = b[i].substr(0, mi.first);
        if (mi.second) {
            b[i+1] += a[i];
        }
        for (int j = 0; j <= b[i+1].size(); j++) {
            if (!can[i][j]) continue;
            if (cmp(buf[j], mi) < 0) {
                buf[j] = P(-1, false);
            }
        }
        for (int j = b[i+1].size()+1; j <= k; j++) {
            buf[j] = P(-1, false);
        }
        for (int j = 0; j <= k; j++) {
            ok[i+1][j] = buf[j].first != -1;
        }
    }
    cout << b[n] << endl;
    return 0;
}