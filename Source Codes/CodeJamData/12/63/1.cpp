#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int N_MAX = 1005, XY_MAX = 1500, INF = 1000000005;

struct tile
{
    int x, y;
    char color;
};

int N;
tile tiles[N_MAX];
bool _potential[2 * XY_MAX + 5][2 * XY_MAX + 5];

bool &potential(int x, int y)
{
    return _potential[x + XY_MAX + 2][y + XY_MAX + 2];
}

void initialize()
{

}

int dist(int dx, int dy)
{
    return max(abs(dx), abs(dy));
}

void mark(int x, int y, char color)
{
    assert(color == '.' || color == '#');
    int mod = color == '.' ? 1 : 0;

    for (int i = -XY_MAX; i <= XY_MAX; i++)
        for (int j = -XY_MAX; j <= XY_MAX; j++)
            if (dist(i - x, j - y) % 2 == mod)
                potential(i, j) = false;
}

bool better(tile a, tile b)
{
    int a_man = abs(a.x) + abs(a.y);
    int b_man = abs(b.x) + abs(b.y);

    if (a_man != b_man)
        return a_man < b_man;

    if (a.x != b.x)
        return a.x > b.x;

    return a.y > b.y;
}

void solve_case(int test_case)
{
    memset(_potential, true, sizeof(_potential));
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %c", &tiles[i].x, &tiles[i].y, &tiles[i].color);
        mark(tiles[i].x, tiles[i].y, tiles[i].color);
    }

    tile best;
    best.x = best.y = INF;

    for (int i = -XY_MAX; i <= XY_MAX; i++)
        for (int j = -XY_MAX; j <= XY_MAX; j++)
            if (potential(i, j))
            {
                tile t = (tile) {i, j, '.'};

                if (better(t, best))
                    best = t;
            }

    printf("Case #%d: ", test_case);

    if (best.x != INF)
        printf("%d %d\n", best.x, best.y);
    else
        puts("Too damaged");
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
