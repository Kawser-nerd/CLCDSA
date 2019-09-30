#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1025;

int TC = 1, T, N, P, miss [MAXN];
pair <int, pair <int, int> > ticket [MAXN];

inline bool good (int a, int b)
{
    for (int i = a; i < b; i++)
        if (miss [i] == 0)
            return false;

    for (int i = a; i < b; i++)
        miss [i]--;

    return true;
}

int main ()
{
    for (scanf ("%d", &T); TC <= T; TC++)
    {
        scanf ("%d", &P);
        N = 1 << P;

        for (int i = 0; i < N; i++)
            scanf ("%d", miss + i);

        int sum = 0;

        for (int len = 2, S = 0, cost; len <= N; len <<= 1)
        {
            int start = 0;

            while (start < N)
            {
                scanf ("%d", &cost);
                ticket [S++] = make_pair (cost, make_pair (start, start + len));
                start += len;
                sum += cost;
            }
        }

        sort (ticket, ticket + N - 1);
        reverse (ticket, ticket + N - 1);

        for (int i = 0; i < N - 1; i++)
            if (good (ticket [i].second.first, ticket [i].second.second))
                sum -= ticket [i].first;

        printf ("Case #%d: %d\n", TC, sum);
    }

    return 0;
}
