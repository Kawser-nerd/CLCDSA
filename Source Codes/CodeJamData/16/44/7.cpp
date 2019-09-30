/**
 *    author:  itmo1
 *    created: 28.05.2016 18:46:00       
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

const int N = 110;

char s[N][N];
vi v[N];

int L, R;

int mark[N];
int n;

void dfs(int x)
{
    if (x < n) L++;
    else R++;
    mark[x] = 1;
    forn(i, sz(v[x]))
    {
        int y = v[x][i];
        if (!mark[y]) dfs(y);
    }
}

pi e[N];

unordered_map<int, int> d[(int)2e5];
pi S[(int)2e5];

void upd(int mask, int x, int y, int val)
{
    int pos = (x << 6) + y;
    if (d[mask].find(pos) == d[mask].end())
    {
        d[mask][pos] = val;
    }
    else
    {
        d[mask][pos] = min(d[mask][pos], val);
    }
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
        eprintf("test %d\n", tt);
        scanf("%d", &n);
        forn(i, n) scanf("%s", s[i]);
        forn(i, 2 * n) v[i].clear();
        memset(mark, 0, sizeof mark);
        forn(i, n) forn(j, n)
        {
            if (s[i][j] == '1')
            {
                v[i].pb(j + n);
                v[j + n].pb(i);
            }
        }
        int l = 0, r = 0;
        int ec = 0;
        int res = 0;
        forn(i, 2 * n) if (!mark[i])
        {
            L = 0;
            R = 0;
            dfs(i);
            //eprintf("L = %d, R = %d\n", L, R);
            if (L == 0) r++;
            else if (R == 0) l++;
            else if (L != R) e[ec++] = mp(L, R);
            else res += L * L;
        }
        forn(i, pw(ec)) d[i].clear();

        forn(i, pw(ec))
        {
            L = 0, R = 0;
            forn(j, ec) if (i & pw(j)) L += e[j].F, R += e[j].S;
            S[i] = mp(L, R);
        }

        for (int i = 0; i <= min(l, r); ++i)
        {
            d[0][(i << 6) + i] = i;
        }

        forn(mask, pw(ec)) for (auto it : d[mask])
        {
            int lq = it.F >> 6;
            int rq = it.F & 63;
            int mask2 = pw(ec) - 1 - mask;
            for (int mm = mask2; mm > 0; mm = (mm - 1) & mask2)
            {
                int l1 = S[mm].F;
                int r1 = S[mm].S;
                if (l1 == r1)
                {
                    upd(mask | mm, lq, rq, it.S + l1 * l1);
                }
                else if (l1 < r1)
                {
                    if (l - lq + l1 >= r1)
                    {
                        upd(mask | mm, lq + r1 - l1, rq, it.S + r1 * r1);
                    }
                }
                else
                {
                    if (r - rq + r1 >= l1)
                    {
                        upd(mask | mm, lq, rq + l1 - r1, it.S + l1 * l1);
                    }
                }
            }
        }

        res += d[pw(ec) - 1][(l << 6) + r];

        forn(i, n) forn(j, n) if (s[i][j] == '1') res--;

        printf("Case #%d: %d\n", tt + 1, res);
    }
                    
             
        
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
