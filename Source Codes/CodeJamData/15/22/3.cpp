#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

inline int bit(int x, int i)
{
    return (x >> i) & 1;
}

int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};

int deg(int r, int c, int y, int x)
{
    int ans = 0;
    for (int v = 0; v < 4; v++)
    {
        int ty = y + vy[v];
        int tx = x + vx[v];
        if (ty < 0 || tx < 0 || ty >= r || tx >= c)
            continue;
        ans++;
    }
    return ans;
}

const int N = 10500;
int T[N];

int go(int r, int c, int n, int f)
{
    int gr = 0;
    int pt = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (((i ^ j) & 1) == f)
                gr++;
            else
                T[pt++] = deg(r, c, i, j);
        }
    if (gr >= n)
        return 0;
    int ans = 0;
    sort(T, T + pt);
    for (int i = 0; i < n - gr; i++)
        ans += T[i];
    return ans;
}

void solve(int cs)
{
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    int anse = go(r, c, n, 0);
    int anso = go(r, c, n, 1);
    int ans = min(anse, anso);
    printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
