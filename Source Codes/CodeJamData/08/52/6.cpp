#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 20, UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const int dr [] = {-1, 0, 1, 0}, dc [] = {0, 1, 0, -1};

struct state
{
    int r, c, bpr, bpc, bd, ypr, ypc, yd;
};

int N, R, C, SR, SC, ER, EC;
int wall [MAX][MAX][4];
char grid [MAX][MAX];

void init ()
{
    memset (wall, 0, sizeof (wall));

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            for (int d = 0; d < 4; d++)
            {
                int r = i, c = j;

                while (grid [r][c] != '#')
                {
                    r += dr [d];
                    c += dc [d];
                    wall [i][j][d]++;
                }
            }
}

const int MAXD = 17;

unsigned char dist [MAXD][MAXD][MAXD][MAXD][4][MAXD][MAXD][4];
queue <state> first, second;

inline unsigned char &getdist (int r, int c, int bpr, int bpc, int bd, int ypr, int ypc, int yd)
{
    return dist [r][c][bpr][bpc][bd][ypr][ypc][yd];
}

inline unsigned char &getdist (state &s)
{
    return getdist (s.r, s.c, s.bpr, s.bpc, s.bd, s.ypr, s.ypc, s.yd);
}

inline void update (state &top, int nr, int nc, int bpr, int bpc, int bd, int ypr, int ypc, int yd)
{
    if (bpr > ypr)
    {
        swap (bpr, ypr);
        swap (bpc, ypc);
        swap (bd, yd);
    }

    int add = top.r == nr && top.c == nc ? 0 : 1, ndist = getdist (top) + add;

    if (ndist < getdist (nr, nc, bpr, bpc, bd, ypr, ypc, yd))
    {
        getdist (nr, nc, bpr, bpc, bd, ypr, ypc, yd) = ndist;

        if (add == 0)
            first.push ((state) {nr, nc, bpr, bpc, bd, ypr, ypc, yd});
        else
            second.push ((state) {nr, nc, bpr, bpc, bd, ypr, ypc, yd});
    }
}

inline bool port (int nr, int nc, int d, int pr, int pc, int pd)
{
    return nr == pr && nc == pc && (d ^ pd) == 2;
}

int bfs ()
{
    memset (dist, 255, sizeof (dist));
    first = second = queue <state> ();

    int BPR = SR + wall [SR][SC][0] * dr [0], BPC = SC + wall [SR][SC][0] * dc [0], BD = 2, YPR = SR + wall [SR][SC][1] * dr [1], YPC = SC + wall [SR][SC][1] * dc [1], YD = 3;

    getdist (SR, SC, BPR, BPC, BD, YPR, YPC, YD) = 0;
    first.push ((state) {SR, SC, BPR, BPC, BD, YPR, YPC, YD});

    while (!first.empty () || !second.empty ())
    {
        if (first.empty ())
        {
            first = second;
            second = queue <state> ();
        }

        state top = first.front (); first.pop ();

        if (top.r == ER && top.c == EC)
            return getdist (top);

        for (int d = 0; d < 4; d++)
        {
            int nr = top.r + wall [top.r][top.c][d] * dr [d], nc = top.c + wall [top.r][top.c][d] * dc [d];
            update (top, top.r, top.c, top.bpr, top.bpc, top.bd, nr, nc, d ^ 2);
            update (top, top.r, top.c, nr, nc, d ^ 2, top.ypr, top.ypc, top.yd);
        }

        for (int d = 0; d < 4; d++)
        {
            int nr = top.r + dr [d], nc = top.c + dc [d];

            if (grid [nr][nc] == '.')
                update (top, nr, nc, top.bpr, top.bpc, top.bd, top.ypr, top.ypc, top.yd);
            else if (port (nr, nc, d, top.bpr, top.bpc, top.bd))
                update (top, top.ypr + dr [top.yd], top.ypc + dc [top.yd], top.bpr, top.bpc, top.bd, top.ypr, top.ypc, top.yd);
            else if (port (nr, nc, d, top.ypr, top.ypc, top.yd))
                update (top, top.bpr + dr [top.bd], top.bpc + dc [top.bd], top.bpr, top.bpc, top.bd, top.ypr, top.ypc, top.yd);
        }
    }

    return -1;
}

int main ()
{
    scanf ("%d", &N);

    for (int n = 1; n <= N; n++)
    {
        memset (grid, '#', sizeof (grid));
        scanf ("%d %d", &R, &C);

        for (int i = 1; i <= R; i++)
        {
            scanf ("%s", grid [i] + 1);
            grid [i][0] = grid [i][C + 1] = '#';

            for (int j = 1; j <= C; j++)
                if (grid [i][j] == 'O')
                {
                    SR = i;
                    SC = j;
                    grid [i][j] = '.';
                }
                else if (grid [i][j] == 'X')
                {
                    ER = i;
                    EC = j;
                    grid [i][j] = '.';
                }
        }

        init ();

        int ans = bfs ();

        if (ans == -1)
            printf ("Case #%d: THE CAKE IS A LIE\n", n);
        else
            printf ("Case #%d: %d\n", n, ans);
    }

    return 0;
}
