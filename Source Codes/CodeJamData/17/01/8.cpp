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
int T, k, n; char ch[N];
int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    rep(cas, 1, T) {
        scanf("%s%d", ch, &k);
        bitset <N> b, a; n = strlen(ch);
        rep(i, 0, k - 1) b[i] = 1;
        rep(i, 0, n - 1) a[i] = ch[i] == '-';
        int ret = 0;
        rep(i, 0, n - k) if (a[i]) 
            ++ ret, a ^= b << i;
        if (a != 0) printf("Case #%d: IMPOSSIBLE\n", cas); else
            printf("Case #%d: %d\n", cas, ret);
    }
    return 0;
}