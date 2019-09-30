#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXC = 3005, UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int dx [] = {0, 1, 0, -1}, dy [] = {1, 0, -1, 0};

int N, L, T, x, y, dir;
char S [100];
vector <short> horiz [2 * MAXC], vert [2 * MAXC];
bitset <2 * MAXC> good [2 * MAXC];

inline void move (char act)
{
    if (act == 'L')
        dir = dir - 1 & 3;
    else if (act == 'R')
        dir = dir + 1 & 3;
    else
    {
        int nx = x + dx [dir], ny = y + dy [dir];

        if (x == nx)
            horiz [min (y, ny)].push_back (x);
        else if (y == ny)
            vert [min (x, nx)].push_back (y);

        x = nx;
        y = ny;
    }
}

int main ()
{
    scanf ("%d", &N);

    for (int n = 1; n <= N; n++)
    {
        x = y = MAXC;
        dir = UP;

        for (int i = 0; i < 2 * MAXC; i++)
        {
            horiz [i].clear ();
            vert [i].clear ();
            good [i].reset ();
        }

        scanf ("%d", &L);

        for (int i = 0; i < L; i++)
        {
            scanf ("%s %d", S, &T);

            while (T--)
                for (int j = 0; j < (int) strlen (S); j++)
                    move (S [j]);
        }

        for (int i = 0; i < 2 * MAXC; i++)
        {
            sort (horiz [i].begin (), horiz [i].end ());
            sort (vert [i].begin (), vert [i].end ());

            for (int a = 0, b = 0, c = 0; a < 2 * MAXC; a++)
            {
                while (b < (int) horiz [i].size () && a >= horiz [i][b])
                {
                    c ^= 1;
                    b++;
                }

                if (c == 0 && b > 0 && b < (int) horiz [i].size ())
                    good [i][a] = true;
            }

            for (int a = 0, b = 0, c = 0; a < 2 * MAXC; a++)
            {
                while (b < (int) vert [i].size () && a >= vert [i][b])
                {
                    c ^= 1;
                    b++;
                }

                if (c == 0 && b > 0 && b < (int) vert [i].size ())
                    good [a][i] = true;
            }
        }

        int area = 0;

        for (int i = 0; i < 2 * MAXC; i++)
            area += good [i].count ();

        printf ("Case #%d: %d\n", n, area);
    }

    return 0;
}
