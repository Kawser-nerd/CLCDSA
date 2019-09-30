#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 155, INF = 1000000005;

int TC = 1, T, N, A [MAXN][MAXN];

inline bool valid (int r, int c)
{
    return r >= 0 && r < N && c >= 0 && c < N;
}

inline bool sym1 (int num)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i + j < num)
            {
                int sum = 2 * num - (i + j);
                int diff = i - j;

                int a = (sum + diff) / 2, b = (sum - diff) / 2;

                if (valid (a, b) && A [i][j] != A [a][b])
                    return false;
            }

    return true;
}

inline bool sym2 (int num)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i - j < num)
            {
                int sum = i + j;
                int diff = 2 * num - (i - j);

                int a = (sum + diff) / 2, b = (sum - diff) / 2;

                if (valid (a, b) && A [i][j] != A [a][b])
                    return false;
            }

    return true;
}

int main ()
{
    for (scanf ("%d", &T); TC <= T; TC++)
    {
        scanf ("%d", &N);

        for (int sum = 0; sum <= 2 * (N - 1); sum++)
            for (int i = max (0, sum - (N - 1)); i <= min (sum, N - 1); i++)
                scanf ("%d", &A [i][sum - i]);

        int bestsum = INF, bestdiff = INF;

        for (int sum = 0; sum <= 2 * (N - 1); sum++)
            if (sym1 (sum))
                bestsum = min (bestsum, abs (sum - (N - 1)));

        for (int diff = -(N - 1); diff <= N - 1; diff++)
            if (sym2 (diff))
                bestdiff = min (bestdiff, abs (diff));

        printf ("Case #%d: %d\n", TC, (N + bestsum + bestdiff) * (N + bestsum + bestdiff) - N * N);
    }

    return 0;
}
