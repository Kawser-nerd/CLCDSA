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

int n;
string l, r;
ll ma;
ll mx, my;
int g(int a, int b) {
    if (a < b) return -1;
    if (a == b) return 0;
    if (a > b) return 1;
    assert(false);
}
void dfs(int p, ll x, ll y, int f) {
//    printf("%d %lld %lld\n", p, x, y);
    if (p == -1) {
        if (abs(x-y) < ma) {
            ma = abs(x-y);
            mx = x; my = y;
        } else if (abs(x-y) == ma) {
            if (x < mx) {
                mx = x; my = y;
            } else if (mx == x) {
                my = min(my, y);
            }
        }
        return;
    }
    if (f == -1) {
        int A, B;
        if (l[p] != '?') A = l[p]-'0';
        else A = 9;
        if (r[p] != '?') B = r[p]-'0';
        else B = 0;
        dfs(p-1, x*10+A, y*10+B, f);
    } else if (f == 1) {
        int A, B;
        if (l[p] != '?') A = l[p]-'0';
        else A = 0;
        if (r[p] != '?') B = r[p]-'0';
        else B = 9;
        dfs(p-1, x*10+A, y*10+B, f);        
    } else {
        if (l[p] != '?' and r[p] != '?') {
            int A = l[p]-'0', B = r[p]-'0';
            dfs(p-1, x*10+A, y*10+B, g(A, B));
        } else if (l[p] == '?' and r[p] == '?') {
            dfs(p-1, x*10+0, y*10+0, 0);
            dfs(p-1, x*10+1, y*10+0, 1);
            dfs(p-1, x*10+0, y*10+1, -1);
        } else if (l[p] != '?') {
            int A = l[p]-'0', B;
            if (1 <= A) {
                dfs(p-1, x*10+A, y*10+A-1, 1);
            }
            if (A <= 8) {
                dfs(p-1, x*10+A, y*10+A+1, -1);
            }
            dfs(p-1, x*10+A, y*10+A, 0);
        } else {
            int A, B = r[p]-'0';
            if (1 <= B) {
                dfs(p-1, x*10+B-1, y*10+B, -1);
            }
            if (B <= 8) {
                dfs(p-1, x*10+B+1, y*10+B, 1);
            }
            dfs(p-1, x*10+B, y*10+B, 0);
        }
    }
    // for (int i = 0; i < 10; i++) {
    //     if (l[p] != '?' and l[p]-'0' != i)continue;
    //     for (int j = 0; j < 10; j++) {
    //         if (r[p] != '?' and r[p]-'0' != j) continue;
    //         dfs(p-1, x*10+i, y*10+j);
    //     }
    // }

}

void solve() {
    cin >> l >> r;
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    n = (int)l.size();
    ma = 1e18+1e17;
    dfs(n-1, 0, 0, 0);
    printf("%0*lld %0*lld\n", n, mx, n, my);
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