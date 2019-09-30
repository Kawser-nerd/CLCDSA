#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 1005;
using namespace std;
int T; ll bit[20], n, ans;
void dfs(int p, int las, int cmp, ll sum) {
    if (ans >= 0) return ;
    if (p < 0) {
        ans = sum;
        return ;
    }
    int c = (n / bit[p]) % 10;
    for (int i = 9; i >= las; i --) {
        if (ans >= 0) return ;
        if (!cmp && i > c) continue ;
        if (!cmp && i == c) {
            dfs(p - 1, i, 0, sum + i * bit[p]);
            continue ;
        }
        dfs(p - 1, i, 1, sum + i * bit[p]);
    }
}
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d", &T);
    bit[0] = 1; rep(i, 1, 18) bit[i] = bit[i - 1] * 10;
    rep(cas, 1, T) {
        scanf("%lld", &n);
        ans = - 1, dfs(18, 0, 0, 0);
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}