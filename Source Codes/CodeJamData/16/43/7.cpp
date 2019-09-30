/**
 *    author:  itmo1
 *    created: 28.05.2016 17:36:20       
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

int a[N][N];
int b[N * 4];

inline int in(int x, int y, int z)
{
    return abs(x - y) + abs(x - z) == abs(y - z);
}

pi e[N * 4];
int n, m;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int OK;
int x1, y1, d1, x2, y2, d2;

inline bool in(int x, int y)
{
    return 0 <= x && x < n && 0 <= y && y < m;
}


void get(int &x, int &y, int &d, int v)
{
    if (v < m)
    {
        x = 0, y = v, d = 3;
    }
    else if (v < m + n)
    {
        x = v - m, y = m - 1, d = 1;
    }
    else if (v < m + n + m)
    {
        x = n - 1, y = m - 1 - (v - m - n), d = 0;
    }
    else
    {
        x = n - 1 - (v - m - n - m), y = 0, d = 2;
    }
    //eprintf("v = %d ---> %d %d %d\n", v, x, y, d);
}

int was[N][N][4];
int wc = 0;

/*bool dfs(int x, int y, int d)
{
    if (!OK) return false;
    //eprintf("%d %d %d\n", x, y, d);
    if (x == x2 && y == y2 && d == d2)
    {
        return true;
    }
    if (!in(x, y)) return false;
    if (was[x][y][d] == wc) return false;
    was[x][y][d] = wc;
    int wx = x, wy = y, wd = d;
    if (a[x][y] != 0)
    {
        d ^= a[x][y];
        x += dx[d];
        y += dy[d];
        int res = dfs(x, y, d ^ 3);
        //was[wx][wy][wd] = 0;
        return res;
    }
    else
    {
        for (int i = 1; i <= 2; ++i)
        {
            a[x][y] = i;
            d ^= a[x][y];
            if (dfs(x + dx[d], y + dy[d], d ^ 3))
            {
                //was[wx][wy][wd] = 0;
                return true;
            }
            d ^= a[x][y];
        }
        a[x][y] = 0;
        //was[wx][wy][wd] = 0;
        return false;
    }
} */




pair<pi, int> q[N * N];
int last[N][N][4];
int st, en;

bool add(int x, int y, int d, int ch)
{
    if (x == x2 && y == y2 && d == d2)
    {
        return true;
    }
    if (!in(x, y)) return false;
    if (was[x][y][d] != wc)
    {
        was[x][y][d] = wc;
        q[en++] = mp(mp(x, y), d);
        last[x][y][d] = ch;
    }
    return false;
}

bool bfs(int x, int y, int d)
{
    int x1 = x, y1 = y, d1 = d;
    st = 0, en = 0;
    q[en++] = mp(mp(x, y), d);
    was[x][y][d] = wc;
    int LAST = -1;
    while (st < en && LAST == -1)
    {
        x = q[st].F.F;
        y = q[st].F.S;
        d = q[st].S;
        //eprintf("bfs %d %d %d\n", x, y, d);
        ++st;

        if (a[x][y])
        {
            int ch = a[x][y];
            d ^= a[x][y];
            x += dx[d];
            y += dy[d];
            d ^= 3;
            if (add(x, y, d, ch)) LAST = ch;
        }
        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                d ^= i;
                if (add(x + dx[d], y + dy[d], d ^ 3, i)) LAST = i;
                d ^= i;
            }
        }
    }
    if (LAST != -1)
    {
        x = x2, y = y2, d = d2;
        while (1)
        {
            //eprintf("restore %d %d %d\n", x, y, d);
            x += dx[d];
            y += dy[d];
            d ^= 3;
            //eprintf("last = %d\n", LAST);
            a[x][y] = LAST;
            d ^= a[x][y];
            if (x == x1 && y == y1 && d == d1) return true;
            assert(in(x, y));
            LAST = last[x][y][d];
        }    
    }
    return false;
}






void build(int l, int r)
{
    get(x1, y1, d1, l);
    get(x2, y2, d2, r);
    x2 += dx[d2];
    y2 += dy[d2];   
    d2 ^= 3;
    ++wc;
    //eprintf("start %d %d :: (%d %d %d) --> (%d %d %d)\n", l, r, x1, y1, d1, x2, y2, d2);
    if (!bfs(x1, y1, d1)) OK = 0;
    //eprintf("end %d %d ::: OK = %d\n", l, r, OK);

    /*if (OK)
    {
        forn(i, n)
        {
            forn(j, m)
            {
                if (a[i][j] == 1) eprintf("/");
                else if (a[i][j] == 2) eprintf("\\");
                else eprintf("?");
            }
            eprintf("\n");
        }
    }   */
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
        scanf("%d%d", &n, &m);    
        int k = 2 * (n + m);
        forn(i, n + m)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            b[x] = y;
            b[y] = x;
        }
        //forn(i, k) scanf("%d", &b[i]);
        //forn(i, k) --b[i];
        OK = 1;
        forn(i, k) forn(j, i) if (b[i] != j)
        {
            if (in(j, i, b[i]) ^ in(b[j], i, b[i])) OK = 0;
        }
        memset(a, 0, sizeof a);
        int ec = 0;
        forn(i, k) if (i < b[i]) e[ec++] = mp(min(b[i] - i, k - b[i] + i), i);
        //forn(i, k) if (i < b[i]) e[ec++] = mp(b[i] - i, i);

        sort(e, e + ec);
        forn(i, ec)
        {
            int x = e[i].S;
            build(x, b[x]);
        }

        printf("Case #%d:\n", tt + 1);
        if (OK)
        {
            forn(i, n)
            {
                forn(j, m)
                {
                    if (a[i][j] == 1) putchar('/');
                    else putchar('\\');
                }
                puts("");
            }
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }

    #ifdef home
        eprintf("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}
