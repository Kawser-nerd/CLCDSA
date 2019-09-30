#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXR = 15, MAXF = 100000005, MOD = 10007;

pair <short, short> fact [MAXF];

inline int fastpow (int a, int b)
{
    int p = 1;

    while (b > 0)
    {
        if (b & 1) p = p * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return p;
}

inline int inv (int a)
{
    return fastpow (a, MOD - 2);
}

inline int choose (int a, int b)
{
    int c = a - b;

    if (fact [a].second > fact [b].second + fact [c].second)
        return 0;

    return fact [a].first * inv (fact [b].first) % MOD * inv (fact [c].first) % MOD;
}

void init ()
{
    fact [0] = make_pair (1, 0);

    for (int i = 1; i < MAXF; i++)
    {
        int t = i, p = 0;

        while (t % MOD == 0)
        {
            t /= MOD;
            p++;
        }

        t = t % MOD;
        fact [i] = make_pair (fact [i - 1].first * t % MOD, fact [i - 1].second + p);
    }
}

inline int solve (int a, int b)
{
    if (a < 0 || b < 0 || (a + b) % 3 != 0 || 2 * a < b || 2 * b < a)
        return 0;

    return choose ((a + b) / 3, (2 * a - b) / 3);
}

int N, H, W, R;
pair <int, int> rock [MAXR], temp [MAXR];

inline int calc (int mask)
{
    int n = 0, p = __builtin_popcount (mask) & 1 ? -1 : 1;

    temp [n++] = make_pair (1, 1);

    for (int i = 0; i < R; i++)
        if (mask & 1 << i)
            temp [n++] = rock [i];

    temp [n++] = make_pair (H, W);

    for (int i = 0; i + 1 < n; i++)
        p = p * solve (temp [i + 1].first - temp [i].first, temp [i + 1].second - temp [i].second) % MOD;

    return p;
}

int main ()
{
    init ();
    scanf ("%d", &N);

    for (int n = 1; n <= N; n++)
    {
        scanf ("%d %d %d", &H, &W, &R);

        for (int i = 0; i < R; i++)
            scanf ("%d %d", &rock [i].first, &rock [i].second);

        sort (rock, rock + R);

        int total = 0;

        for (int m = 0; m < 1 << R; m++)
            total = (total + calc (m)) % MOD;

        total = (total + MOD) % MOD;
        printf ("Case #%d: %d\n", n, total);
    }

    return 0;
}
