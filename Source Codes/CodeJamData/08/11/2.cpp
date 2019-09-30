#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 805;

int T, N, x [MAXN], y [MAXN];

int main ()
{
    scanf ("%d", &T);

    for (int t = 0; t < T; t++)
    {
        scanf ("%d", &N);

        for (int i = 0; i < N; i++)
            scanf ("%d", x + i);

        for (int i = 0; i < N; i++)
            scanf ("%d", y + i);

        sort (x, x + N);
        sort (y, y + N);

        long long total = 0;

        for (int i = 0; i < N; i++)
            total += (long long) x [i] * y [N - 1 - i];

        printf ("Case #%d: %lld\n", t + 1, total);
    }

    return 0;
}
