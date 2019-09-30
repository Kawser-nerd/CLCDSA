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

const int D_MAX = 105, HEX = 6;
const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, 0, 1};

struct loc
{
    int x, y;

    loc()
    {
        x = y = 0;
    }

    loc(int _x, int _y)
    {
        x = _x;
        y = _y;
    }

    bool operator < (const loc &other) const
    {
        return make_pair(x, y) < make_pair(other.x, other.y);
    }
};

// S = 5, D = 9
int S, D, M;
bool stone[D_MAX][D_MAX];
bool corner[D_MAX][D_MAX];
vector<loc> corners;
int edge[D_MAX][D_MAX]; // 1 through 6
bool visited[D_MAX][D_MAX];

void initialize()
{
}

bool inside(int x, int y)
{
    return x >= 1 && x <= D && y >= 1 && y <= D && abs(x - y) < S;
}

set<int> colors;

void floodfill(int x, int y, bool on)
{
    assert(inside(x, y));
    assert(stone[x][y] == on);
    assert(!visited[x][y]);
    visited[x][y] = true;

    if (edge[x][y] > 0)
        colors.insert(edge[x][y]);

    for (int d = 0; d < HEX; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (inside(nx, ny) && stone[nx][ny] == on && !visited[nx][ny])
            floodfill(nx, ny, on);
    }
}

bool has_ring()
{
    memset(visited, false, sizeof(visited));

    for (int x = 1; x <= D; x++)
        for (int y = 1; y <= D; y++)
            if ((corner[x][y] || edge[x][y] > 0) && !stone[x][y] && !visited[x][y])
                floodfill(x, y, false);

    for (int x = 1; x <= D; x++)
        for (int y = 1; y <= D; y++)
            if (inside(x, y) && !stone[x][y] && !visited[x][y])
                return true;

    return false;
}

bool has_bridge()
{
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < (int) corners.size(); i++)
        if (stone[corners[i].x][corners[i].y])
        {
            floodfill(corners[i].x, corners[i].y, true);

            for (int j = i + 1; j < (int) corners.size(); j++)
                if (visited[corners[j].x][corners[j].y])
                    return true;
        }

    return false;
}

bool has_fork()
{
    memset(visited, false, sizeof(visited));
    set<loc> to_visit;

    for (int x = 1; x <= D; x++)
        for (int y = 1; y <= D; y++)
            if (inside(x, y) && edge[x][y] > 0)
                to_visit.insert(loc(x, y));

    while (!to_visit.empty())
    {
        colors.clear();
        loc p = *to_visit.begin();
        to_visit.erase(to_visit.begin());

        if (stone[p.x][p.y] && !visited[p.x][p.y])
        {
            floodfill(p.x, p.y, true);

            if (colors.size() >= 3)
                return true;
        }
    }

    return false;
}

void solve_case(int test_case)
{
    memset(stone, false, sizeof(stone));
    memset(corner, false, sizeof(corner));
    memset(edge, 0, sizeof(edge));
    corners.clear();

    scanf("%d %d", &S, &M);
    D = 2 * S - 1;

    corners.push_back(loc(1, 1));
    corners.push_back(loc(1, S));
    corners.push_back(loc(S, 1));
    corners.push_back(loc(S, D));
    corners.push_back(loc(D, S));
    corners.push_back(loc(D, D));

    for (int i = 0; i < (int) corners.size(); i++)
        corner[corners[i].x][corners[i].y] = true;

    for (int i = 2; i < S; i++)
    {
        edge[1][i] = 1;
        edge[i][1] = 2;
    }

    for (int i = S + 1; i < D; i++)
    {
        edge[i][i - S + 1] = 3;
        edge[i - S + 1][i] = 4;
    }

    for (int i = S + 1; i < D; i++)
    {
        edge[i][D] = 5;
        edge[D][i] = 6;
    }

    printf("Case #%d: ", test_case);
    bool done = false;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if (done)
            continue;

        stone[x][y] = true;
        bool ring = has_ring();
        bool bridge = has_bridge();
        bool fork = has_fork();

        string output = "";

        if (bridge)
            output += "-bridge";

        if (fork)
            output += "-fork";

        if (ring)
            output += "-ring";

        if (output.length() > 0 && output[0] == '-')
            output = output.substr(1);

        if (output.length() > 0)
        {
            cout << output << " in move " << i + 1 << '\n';
            done = true;
        }
    }

    if (!done)
        puts("none");
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
