#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, a[2010], ans[2010], q[2010], u[2010], qb, qf;

bool vis(int from, int to, int via) {
    return (ll)(ans[to] - ans[from]) * (ll)(via - from) > (ll)(ans[via] - ans[from]) * (ll)(to - from);
}

bool solve(int tc) {
    scanf("%d", &n);
    forn(i, n-1) scanf("%d", &a[i]), a[i]--;
    forn(i, n-1)
        for (int j = i + 1; j < a[i]; j++)
            if (a[j] > a[i]) {
                fprintf(stderr, "%d - impossible\n", tc);
                return false;
            }
    a[n-1] = -1;

    forn(i, n) u[i] = 0;
    ans[n-1] = (int)1e9;
    qb = qf = 0;
    q[qf++] = n - 1;
    while (qb < qf) {
        int z = q[qb++];
        int cur = -1;
        forn(i, n) 
            if (a[i] == z) {
                if (a[z] == -1) { ans[i] = ans[z] - 1; q[qf++] = i; }
                else {
                    int k = a[z];
                    int j = z;
                    // i -> z.first -> z.second
                    ans[i] = (ans[j] * (ll)(k - j) - ((ll)(ans[k] - ans[j]) * (ll)(j - i))) / (k - j);
                    while (vis(i, k, j)) ans[i]--;
                    if (cur != -1)
                        while (!vis(cur, j, i)) ans[i]--;
                    q[qf++] = i;
                    cur = i;
                }
            }
    }

    forn(i, n)
        for (int j = i + 1; j < a[i]; j++)
            if ((ans[a[i]] - ans[j]) * (ll)(a[i] - i) < (ll)(a[i] - j) * (ans[a[i]] - ans[i]))
                fprintf(stderr, "Wrong!!! %d -> %d, fail on %d\n", i, a[i], j);


    forn(i, n)
        if (ans[i] < 0) fprintf(stderr, "Oh no no no... Fail: ans[%d] = %d\n", i, ans[i]);
        

    forn(i, n) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");

    fprintf(stderr, "%d - ok\n", tc);

    return true;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        if (!solve(q)) printf("Impossible\n");
    }
}
