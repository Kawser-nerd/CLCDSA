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

bool a[32];


int main() {
    freopen("a.in", "rt", stdin);
    freopen("a.out", "wt", stdout);
    
    int tests;
    scanf("%d\n", &tests);
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        int n, k;
        scanf("%d%d", &n, &k);
        
        printf((k + 1) & ((1 << n) - 1) ? "OFF\n" : "ON\n");
        continue;
        
        if (!k) {
            printf("OFF\n");
            continue;
        }
        k--;
        memset(a, 0, sizeof a);
        a[0] = 1;
        forn(i, k) {
            int j = 0;
            while (j < n && a[j]) j++;
            forn(z, min(j + 1, n)) a[z] = 1 - a[z];
            // forn(z, n) printf("%d", a[z]); printf("\n");
        }
            
        bool ans = true;
        forn(i, n) ans &= a[i];
        printf(ans ? "ON\n" : "OFF\n");
    }
    
    return 0;
}
