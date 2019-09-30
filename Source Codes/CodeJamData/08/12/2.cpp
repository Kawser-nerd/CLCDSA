#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2005, MAXM = 2005;

int C, N, M;
bool malt [MAXN];
vector <int> like [MAXM];

void remove (int num)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < (int) like [i].size (); j++)
            if (like [i][j] == 2 * num)
            {
                swap (like [i][j], like [i][like [i].size () - 1]);
                like [i].pop_back ();
            }
}

int main ()
{
    scanf ("%d", &C);

    for (int c = 0; c < C; c++)
    {
        memset (malt, false, sizeof (malt));
        scanf ("%d %d", &N, &M);

        for (int i = 0, t; i < M; i++)
        {
            like [i].clear ();
            scanf ("%d", &t);

            for (int j = 0, x, y; j < t; j++)
            {
                scanf ("%d %d", &x, &y); x--;
                like [i].push_back (2 * x + y);
            }
        }

        int found;

        do
        {
            found = -1;

            for (int i = 0; i < M; i++)
                if (like [i].size () == 1 && like [i][0] % 2 == 1 && !malt [like [i][0] / 2])
                    found = like [i][0] / 2;

            malt [found] = true;
            remove (found);
        }
        while (found != -1);

        bool bad = false;

        for (int i = 0; i < M; i++)
            if (like [i].size () == 0)
                bad = true;

        printf ("Case #%d: ", c + 1);

        if (bad)
        {
            printf ("IMPOSSIBLE\n");
            continue;
        }

        for (int i = 0; i < N; i++)
            printf ("%c%c", malt [i] ? '1' : '0', i < N - 1 ? ' ' : '\n');
    }

    return 0;
}
