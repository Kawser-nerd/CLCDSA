/**
 *    author:  itmo1
 *    created: 28.05.2016 17:19:48       
**/
#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

using namespace std;

typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;

/* --- main part --- */

const int N = 210;

dbl p[N];
dbl d[N][N];
dbl a[N];
int ac;

dbl get()
{
    memset(d, 0, sizeof d);
    forn(i, ac + 1) forn(j, ac + 1) d[i][j] = 0;
    d[0][0] = 1;
    forn(i, ac)
    {
        forn(j, ac)
        {
            d[i + 1][j] += d[i][j] * a[i];
            d[i + 1][j + 1] += d[i][j] * (1 - a[i]);
        }
    }
    return d[ac][ac / 2];
}

int main()
{
    #ifdef home
        assert(freopen("1.in", "r", stdin));
        assert(freopen("1.out", "w", stdout));
    #endif
    int tn;
    scanf("%d", &tn);
    forn(tt, tn)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        forn(i, n) scanf("%lf", p + i);
        sort(p, p + n);
        dbl res = 0;
        for (int i = 0; i <= k; ++i)
        {
            ac = 0;
            forn(j, i) a[ac++] = p[j];
            forn(j, k - i) a[ac++] = p[n - 1 - j];
            res = max(res, get());
        }
        printf("Case #%d: %.10f\n", tt + 1, res);
    }
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
