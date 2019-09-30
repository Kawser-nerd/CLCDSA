#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 105

int ty[NMAX][NMAX];

string ch = "|\\/-";
int dx[4] = {1, 1, 1, 0};
int dy[4] = {0, 1, -1, 1};
int num[NMAX][NMAX];
vector<int> g[NMAX * NMAX], gt[NMAX * NMAX], G[NMAX * NMAX];
bool ok;
bool used[NMAX * NMAX];

int it =0;

void go(int v)
{
    it++;
    if (!ok) return;
    if (gt[v].size() == 0)
    {
        ok = false;
        return;
    }    

    if (gt[v].size() > 1) return;

    used[v] = true;
    int u = gt[v][0];
    gt[v].clear();

    int w = -1;
    forv(i, g[u])
    {
        if (g[u][i] == v) continue;
        w = g[u][i];
    }
    g[u].clear();

    forv(i, gt[w])
    {
        if (gt[w][i] == u)
        {
            gt[w].erase(gt[w].begin() + i, gt[w].begin() + i + 1);
            break;
        }
    }

    go(w);
}

void dfs(int v)
{
    if (used[v]) return;
    used[v] = true;

    forv(i, G[v]) dfs(G[v][i]);
}

const ll mod = 1000003;

void solve(int test)
{
    printf("Case #%d: ", test);

    forn(i, NMAX * NMAX)
    {
        g[i].clear();
        gt[i].clear();
        G[i].clear();
    }

    int n, m;
    scanf("%d %d\n", &n, &m);
    forn(i, n)
    {
        forn(j, m)
        {
            char c; scanf("%c", &c);
            forn(k, 4)
            {
                if (ch[k] == c) ty[i][j] = k;
            }
        }
        scanf("\n");
    }

    forn(i, n)
    {
        forn(j, m)
        {
            num[i][j] = i * m + j;
        }
    }

    forn(i, n)
    {
        forn(j, m)
        {
            for (int dir = -1; dir <= 1; dir += 2)
            {
                int x = (i + dir * dx[ty[i][j]] + n) % n;
                int y = (j + dir * dy[ty[i][j]] + m) % m;

                g[num[i][j]].pb(num[x][y]);
                gt[num[x][y]].pb(num[i][j]);
            }
        }
    }

    int N = n * m;

    forn(i, N) assert(g[i].size() == 2);

    ok = true;

    memset(used, 0, sizeof(used));
    it = 0;
    forn(i, N)
    {
        if (used[i]) continue;
        go(i);
    }

    cerr << it << endl;

    if (!ok) 
    {
        cout << 0 << endl;
        return;
    }

    forn(i, N)
    {
        if (gt[i].size() == 0) continue;
        assert(gt[i].size() == 2);
        G[gt[i][0]].pb(gt[i][1]);
        G[gt[i][1]].pb(gt[i][0]);
    }
    int cnt = 0;
    memset(used, 0, sizeof(used));

    forn(i, N)
    {
        if (G[i].size() == 0 || used[i]) continue;
        cnt++;
        dfs(i);
    }

    ll ans = 1;
    forn(i, cnt)
    {
        ans = (ans * 2) % mod;
    }
    cout << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}