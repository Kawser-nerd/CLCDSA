#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 15, MAX2 = 1025;

int C, M, N, dp1 [MAX2], dp2 [MAX2];
char str [MAX];

int main ()
{
    scanf ("%d", &C);

    for (int c = 1; c <= C; c++)
    {
        scanf ("%d %d", &M, &N);

        memset (dp1, -63, sizeof (dp1));
        dp1 [0] = 0;

        for (int i = 0; i < M; i++)
        {
            scanf ("%s", str);

            for (int m = 0; m < 1 << N; m++)
            {
                dp2 [m] = INT_MIN;

                bool good = true;

                for (int j = 0; j < N && good; j++)
                    if ((m & 1 << j) > 0 && str [j] == 'x')
                        good = false;

                for (int j = 0; j + 1 < N && good; j++)
                    if ((m & 1 << j) > 0 && (m & 1 << j + 1) > 0)
                        good = false;

                if (!good)
                    continue;

                for (int k = 0; k < 1 << N; k++)
                    if ((m & k << 1) == 0 && (m << 1 & k) == 0)
                        dp2 [m] = max (dp2 [m], dp1 [k]);

                dp2 [m] += __builtin_popcount (m);
            }

            memcpy (dp1, dp2, sizeof (dp1));
        }

        int best = 0;

        for (int i = 0; i < 1 << N; i++)
            best = max (best, dp1 [i]);

        printf ("Case #%d: %d\n", c, best);
    }

    return 0;
}
