#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define sz(a) ((int)((a).size()))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define foreach(i,a) for (typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
typedef pair<int, int> ii;
typedef long long LL;

int a[1024], d[1024], s[1024], it[1024];
LL sv[1024];

int main() {
    freopen("b.in", "rt", stdin);
    freopen("b.out", "wt", stdout);
    
    int tests;
    scanf("%d\n", &tests);
    for (int test = 1; test <= tests; test++) {
        int R, k, n;
        scanf("%d%d%d", &R, &k, &n);
        forn(i, n) scanf("%d", &a[i]);
        
        forn(i, n) {
            int j = (i + 1) % n, z = a[i];
            while (j != i && z + a[j] <= k) z += a[j], j = (j + 1) % n;
            d[i] = j;
            s[i] = z;
        }
        // forn(i, n) printf("%d: %d %d\n", i, d[i], s[i]);
        
        LL ans = 0;
        
        if (0) {
            int x = 0;
            forn(i, R) ans += s[x], x = d[x];
        } else {
            memset(it, -1, sizeof it);
            int x = 0;
            forn(i, R) {
                if (it[x] != -1) {
                    int its = i - it[x];
                    LL add = ans - sv[x];
                    int t = (R - i) / its;
                    i += t * its - 1;
                    ans += t * (LL)add;
                    it[x] = -1;
                } else {
                    it[x] = i;
                    sv[x] = ans;
                    ans += s[x];
                    x = d[x];
                }
            }
        }
        
        
        printf("Case #%d: %I64d\n", test, ans);
    }
    
    return 0;
}
