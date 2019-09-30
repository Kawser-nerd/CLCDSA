#include <cstdio>
#include <cstring>

const int LIMIT_SIZE = 510;

long long combine [LIMIT_SIZE][LIMIT_SIZE];
long long f       [LIMIT_SIZE][LIMIT_SIZE];

inline long long fix(long long u){ return u % 100003; }

void calc()
{
    memset(combine, 0, sizeof(combine));
    memset(f, 0, sizeof(f));

    combine[0][0] = 1;
    combine[1][0] = combine[1][1] = 1;

    for (int i = 2; i <= 500; i ++)
    {
        combine[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            combine[i][j] = fix(combine[i-1][j-1] + combine[i-1][j]);
    }

    f[1][1] = 1;

    for (int n = 2; n <= 500; n ++)
    {
        f[n][1] = 1;
        for (int L = 2; L < n; L ++)
        {
            for (int i = 1; i < L; i ++)
                f[n][L] = fix(f[n][L] + (long long)f[L][i] * combine[n-L-1][L-i-1]);
        }
    }
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    int caseNo = 0;
    int t;

    calc();

    scanf("%d", &caseNo);
    for (t = 1; t <= caseNo; t ++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", t);

        long long ans = 0;
        for (int L = 1; L < n; L ++)
            ans += f[n][L];

        printf("%d\n", (int)fix(ans));
    }

    return 0;
}