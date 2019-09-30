#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 5, MOD = 1000;

template <typename T> struct matrix
{
    int R, C;
    T nums [MAX][MAX];

    inline matrix (int n = 0)
    {
        R = C = n;
        memset (nums, 0, sizeof (nums));
    }

    inline matrix (int r, int c)
    {
        R = r; C = c;
        memset (nums, 0, sizeof (nums));
    }

    inline void iden ()
    {
        memset (nums, 0, sizeof (nums));

        for (int i = 0; i < R; i++)
            nums [i][i] = 1;
    }

    inline matrix operator * (const matrix &right)
    {
        matrix prod (R, right.C);

        for (int i = 0; i < R; i++)
            for (int j = 0; j < right.C; j++)
                for (int k = 0; k < C; k++)
                    prod.nums [i][j] = (prod.nums [i][j] + nums [i][k] * right.nums [k][j]) % MOD;

        return prod;
    }

    inline matrix power (long long p)
    {
        matrix result (R), temp = *this;
        result.iden ();

        while (p > 0)
        {
            if (p & 1) result = result * temp;
            temp = temp * temp;
            p >>= 1;
        }

        return result;
    }

    inline void print ()
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                printf ("%lld%c", (long long) nums [i][j], (j + 1 < C) ? ' ' : '\n');
    }
};

matrix <int> m;

inline int fib (int n)
{
    m.R = m.C = 2;
    m.nums [0][0] = m.nums [0][1] = m.nums [1][0] = 1;
    m.nums [1][1] = 0;

    m = m.power (n);

    return m.nums [0][1];
}

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

int T, N;

int main ()
{
    scanf ("%d", &T);

    for (int t = 0; t < T; t++)
    {
        scanf ("%d", &N);
        printf ("Case #%d: %03d\n", t + 1, (fib (N) * fib (N) % MOD * fastpow (2, N) * 5 % MOD + fastpow (2, N + 1) * fastpow (-1, N) % MOD - 1 + 10 * MOD) % MOD);
    }

    return 0;
}
