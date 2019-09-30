#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;

const int N = 100;

int A[N][N];
int C[N];

int E[N][N];
int ept[N];

const int RN = 83;

int D[RN][RN][RN][RN];
bool cache[RN][RN][RN][RN];

const int INF = N * 10500 * 2;

inline bool in(int a, int b, int c)
{
    return A[a][b] + A[b][c] == A[a][c];
}

int lock[RN][RN][RN][RN];
bool cachelock[RN][RN][RN][RN];

int golock(int a1, int b1, int a2, int b2)
{
    if (cachelock[a1][b1][a2][b2])
        return lock[a1][b1][a2][b2];
    cachelock[a1][b1][a2][b2] = true;
    int cur = (!in(a1, b2, b1)) * C[b2];
    int mx = 0;
    for (int i = 0; i < ept[b2]; i++)
    {
        int y = E[b2][i];
        if (A[a2][y] != A[a2][b2] + 1 || (in(a1, y, b1) && in(a1, b2, b1)))
            continue;
        mx = max(mx, golock(a1, b1, a2, y));
    }
    return lock[a1][b1][a2][b2] = cur + mx;
} 

inline int go(int hs, int hc, int ss, int sc)
{
    if (cache[hs][hc][ss][sc])
        return D[hs][hc][ss][sc];
    cache[hs][hc][ss][sc] = true;
    bool anyhy = false;
    int mx = -INF;
    int sum1 = (!in(ss, hc, sc) || hc == sc) * C[hc];
    for (int hyi = 0; hyi < ept[hc]; hyi++)
    {
        int hy = E[hc][hyi];
        if (A[hs][hy] != A[hs][hc] + 1 || (in(ss, hc, sc) && in(ss, hy, sc)))
            continue;
        anyhy = true;
        bool anysy = false;
        int mn = INF;
        int sum2 = sum1 - (!in(hs, sc, hy) || sc == hy) * C[sc];
        for (int syi = 0; syi < ept[sc]; syi++)
        {
            int sy = E[sc][syi];
            if (A[ss][sy] != A[ss][sc] + 1 || (in(hs, sc, hy) && in(hs, sy, hy)))
                continue;
            anysy = true;
            mn = min(mn, go(hs, hy, ss, sy));
        }        
        if (!anysy)
            mx = max(mx, sum2 + golock(ss, sc, hs, hy));
        else
            mx = max(mx, sum2 + mn);
    }
    if (!anyhy)
        return D[hs][hc][ss][sc] = sum1 - golock(hs, hc, ss, sc);
    else
        return D[hs][hc][ss][sc] = mx;
}

void solve(int cs)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    memset(ept, 0, sizeof(ept));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            A[i][j] = (i == j) ? 0 : N + 100;
    for (int i = 1; i <= n - 1; i++)
    {
        int j;
        scanf("%d", &j);
        int a = i, b = j;
        E[a][ept[a]++] = b;
        E[b][ept[b]++] = a;
        A[a][b] = A[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
    memset(cache, 0, sizeof(cache));
    memset(cachelock, 0, sizeof(cachelock));
    pair<int, pair<int, int> > mx = make_pair(-INF, make_pair(-42, -42));

    for (int hs = 1; hs <= n; hs++)
    {
        pair<int, int> mn(INF, -42);
        for (int ss = 1; ss <= n; ss++)
            mn = min(mn, make_pair(go(hs, hs, ss, ss), ss));
        mx = max(mx, make_pair(mn.first, make_pair(hs, mn.second)));
    }
    //printf("%d %d\n", mx.second.first, mx.second.second);
    printf("Case #%d: %d\n", cs, mx.first);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
        fflush(stdout);
    }
}
