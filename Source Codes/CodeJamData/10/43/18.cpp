#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXR = 5005, INF = 1000000005;

int TC = 1, C, R, X1 [MAXR], X2 [MAXR], Y1 [MAXR], Y2 [MAXR];
bool vis [MAXR];

inline bool connected (int a, int b)
{
    int diff1 = min (X2 [a], X2 [b]) - max (X1 [a], X1 [b]);
    int diff2 = min (Y2 [a], Y2 [b]) - max (Y1 [a], Y1 [b]);

    if (diff1 == -1 && diff2 == -1)
        return (X1 [a] < X1 [b]) ^ (Y1 [a] < Y1 [b]);
    else
        return diff1 >= -1 && diff2 >= -1;
}

int minsum, maxx, maxy;

void dfs (int num)
{
    vis [num] = true;
    minsum = min (minsum, X1 [num] + Y1 [num]);
    maxx = max (maxx, X2 [num]);
    maxy = max (maxy, Y2 [num]);

    for (int i = 0; i < R; i++)
        if (!vis [i] && connected (num, i))
            dfs (i);
}

int main ()
{
    for (scanf ("%d", &C); TC <= C; TC++)
    {
        scanf ("%d", &R);

        for (int i = 0; i < R; i++)
            scanf ("%d %d %d %d", X1 + i, Y1 + i, X2 + i, Y2 + i);

        memset (vis, false, sizeof (vis));
        int die = 0;

        for (int i = 0; i < R; i++)
            if (!vis [i])
            {
                minsum = INF;
                maxx = -INF;
                maxy = -INF;
                dfs (i);
                die = max (die, (maxx + maxy - minsum + 1));
            }

        printf ("Case #%d: %d\n", TC, die);
    }

    return 0;
}
