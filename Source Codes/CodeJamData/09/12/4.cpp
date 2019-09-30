#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 45;
const int dr [] = {-1, 0, 1, 0}, dc [] = {0, 1, 0, -1};

struct inter
{
    int S, W, T;

    inline int next_time (int t, int dir)
    {
        int mod = (t - T % (S + W) + S + W) % (S + W);

        if (dir == 0 || dir == 2)
        {
            if (mod < S)
                return t;
            else
                return t + S + W - mod;
        }
        else
        {
            if (mod < S)
                return t + S - mod;
            else
                return t;
        }
    }
};

struct state
{
    int r, c, dist;

    inline bool operator < (const state &o) const
    {
        return dist > o.dist;
    }
};

int C, N, M, dist [MAX][MAX];
inter square [MAX][MAX];
priority_queue <state> pq;

inline bool valid (int r, int c)
{
    return r >= 0 && r < 2 * N && c >= 0 && c < 2 * M;
}

inline int dijkstra (int ar, int ac, int br, int bc)
{
    memset (dist, 63, sizeof (dist));
    dist [ar][ac] = 0;
    pq.push ((state) {ar, ac, 0});

    while (!pq.empty ())
    {
        state top = pq.top (); pq.pop ();

        if (top.dist > dist [top.r][top.c])
            continue;

        for (int d = 0; d < 4; d++)
        {
            int nr = top.r + dr [d], nc = top.c + dc [d];

            if (valid (nr, nc))
            {
                int ndist;

                if ((top.r + 1) / 2 == (nr + 1) / 2 && (top.c + 1) / 2 == (nc + 1) / 2)
                    ndist = top.dist + 2;
                else
                    ndist = square [top.r / 2][top.c / 2].next_time (top.dist, d) + 1;

                if (ndist < dist [nr][nc])
                    pq.push ((state) {nr, nc, dist [nr][nc] = ndist});
            }
        }
    }

    return dist [br][bc];
}

int main ()
{
    scanf ("%d", &C);

    for (int test = 1; test <= C; test++)
    {
        scanf ("%d %d", &N, &M);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf ("%d %d %d", &square [i][j].S, &square [i][j].W, &square [i][j].T);

        printf ("Case #%d: %d\n", test, dijkstra (2 * N - 1, 0, 0, 2 * M - 1));
    }

    return 0;
}
