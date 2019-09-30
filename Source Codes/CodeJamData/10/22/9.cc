#include <cstdio>
#include <cstring>

const int LIMIT_SIZE = 1000;

int n, k, b, T;

int x[LIMIT_SIZE];
int v[LIMIT_SIZE];

void init()
{
    scanf("%d%d%d%d", &n, &k, &b, &T);
    for (int i = 0; i < n; i ++)
        scanf("%d", x + i);
    for (int i = 0; i < n; i ++)
        scanf("%d", v + i);
}

void solve()
{
    int ret = 0;
    int xx = 0;

    int got = 0;

    for (int i = n - 1; i >= 0 && got < k; i --)
    {
        if (v[i] * T + x[i] >= b)
        {
            got ++;
            ret += xx;
        }
        else
        {
            xx ++;
        }
    }

    if (got < k)
        puts("IMPOSSIBLE");
    else printf("%d\n", ret);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int caseNo = 0;
    int t;

    scanf("%d", &caseNo);
    for (t = 1; t <= caseNo; t ++)
    {
        init();

        printf("Case #%d: ", t);

        solve();
    }

    return 0;
}