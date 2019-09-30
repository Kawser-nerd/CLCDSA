#include <cstdio>
using namespace std;

const int MAX = 450;

int T, C, N;
double dp [MAX], choose [MAX][MAX];

inline double binom (int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;

    if (n == 0)
        return r == 0 ? 1 : 0;

    if (choose [n][r] >= 0)
        return choose [n][r];

    return choose [n][r] = binom (n - 1, r) + binom (n - 1, r - 1);
}

int main ()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            choose [i][j] = -1;

    scanf ("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        scanf ("%d %d", &C, &N);
        dp [0] = 0;

        for (int i = 1; i <= C; i++)
        {
            double prob = 1 - binom (C - i, N) / binom (C, N), sum = 1;

            for (int j = 1; j <= N && j <= i; j++)
            {
                double p = binom (i, j) * binom (C - i, N - j) / binom (C, N);
                sum += p * dp [i - j];
            }

            dp [i] = sum / prob;
        }

        printf ("Case #%d: %lf\n", t, dp [C]);
    }

    return 0;
}
