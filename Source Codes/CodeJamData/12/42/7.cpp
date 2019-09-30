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

#define sqr(x) ( (ll)(x) * (x) )

pii a[1010];
int n, W, H, ansX[1010], ansY[1010];

void solve() {
    scanf("%d %d %d", &n, &W, &H);
    forn(i, n) { scanf("%d", &a[i].first); a[i].second = i; }
    // sort(a, a+n);
    while (true) {
        bool glok = true;
    random_shuffle(a, a+n);
    // reverse(a, a+n);

    ansX[ a[0].second ] = 0;
    ansY[ a[0].second ] = 0;

    for (int qi = 1; qi < n; qi++) {
        int i = a[qi].second;
        int ri = a[qi].first;

        int bx = W + 1, by = H + 1;
        forn(qj, qi) {
            int xj = ansX[ a[qj].second ];
            int yj = ansY[ a[qj].second ];
            int rj = a[qj].first;

            forn(dxb, 2)
            forn(dyb, 2) 
            forn(dxs, 2) 
            forn(dys, 2)  {
                int nx = xj + dxb * rj + dxs * ri;
                int ny = yj + dyb * rj + dys * ri;

                if (nx < 0) nx = 0;
                if (ny < 0) ny = 0;
                if (nx > W) nx = W;
                if (ny > H) ny = H;

                bool ok = true;
                forn(tj, qi) {
                    int xt = ansX[ a[tj].second ];
                    int yt = ansY[ a[tj].second ];
                    int rt = a[tj].first;

                    if (sqr(nx-xt) + sqr(ny-yt) < sqr(rt+ri)) {
                        ok = false;
                        break;
                    }
                }

                if (ok && nx < bx) {
                    bx = nx;
                    by = ny;
                }
            }
        }

        if (bx == W + 1) {
            // fprintf(stderr, "Oh no no no... failed to put %d-th circle of %d =(((\n", qi + 1, n);
            glok = false;
            fprintf(stderr, "fail...\n");
            break;
        }

        ansX[i] = bx;
        ansY[i] = by;
    }

    if (glok) break;
    }

    forn(i, n) printf(" %d %d", ansX[i], ansY[i]);
    printf("\n");
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d:", q);
        solve();
        fprintf(stderr, "%d done\n", q);
    }
}
