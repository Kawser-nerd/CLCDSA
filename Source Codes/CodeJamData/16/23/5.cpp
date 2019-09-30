/**
 *    author:  [itmo] enot.1.10
 *    created: 30.04.2016 19:40:44       
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

map<string, int> M;
int Last = 0;

int get(string s)
{
    if (M.find(s) != M.end()) return M[s];
    return M[s] = Last++;
}

const int N = 5100;

#define next sdflkj
int head[N], next[N], to[N], f[N], ec = 1;

inline void add(int x, int y, int ff)
{
    ++ec;
    to[ec] = y;
    next[ec] = head[x];
    head[x] = ec;
    f[ec] = ff;
}

int mark[N];
int mc = 0;

int ST, EN;

int dfs(int x)
{
    if (x == EN) return 1;
    mark[x] = mc;
    for (int e = head[x]; e; e = next[e])
    {
        int y = to[e];
        if (mark[y] != mc && f[e] && dfs(y))
        {
            f[e]--;
            f[e^1]++;
            return 1;
        }
    }
    return 0;
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
        printf("Case #%d: ", tt + 1);
        M.clear();
        Last = 0;

        forn(i, N) head[i] = 0;
        ec = 1;

        ST = 4010;
        EN = ST + 1;

        int n;
        scanf("%d", &n);

        set<string> S1, S2;

        forn(i, n)
        {
            string s1, s2;
            cin >> s1 >> s2;
            S1.insert(s1);
            S2.insert(s2);
            int x = get(s1);
            int y = get(s2) + 2000;

            add(x, y, 1);
            add(y, x, 0);
        }

        forn(i, Last)
        {
            add(ST, i, 1);
            add(i, ST, 0);
        }

        forn(i, Last)
        {
            add(i + 2000, EN, 1);
            add(EN, i + 2000, 0);
        }     
           
        int res = 0;
        while (1)
        {
            ++mc;
            if (!dfs(ST)) break;
            res++;
        }

        res = n - (sz(S1) + sz(S2) - res);
        printf("%d\n", res);
    }


         
    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
