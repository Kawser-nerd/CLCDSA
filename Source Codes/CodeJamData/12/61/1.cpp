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

const int Z_MAX = 505, INF = 1000000005;
const int ZOMBIE = 1000, SMASH = 750, MOVE = 100;

struct zombie
{
    int X, Y, M;

    int dist(const zombie &other) const
    {
        return max(abs(X - other.X), abs(Y - other.Y));
    }
};

struct state
{
    int n, k, time;

    bool operator < (const state &other) const
    {
        return time > other.time;
    }
};

int Z;
zombie zombies[Z_MAX];
// dp[n][k] = given I smashed zombie n and I smashed k zombies, what's the earliest time I could have smashed zombie n; >= INF if impossible
int dp[Z_MAX][Z_MAX];
bool visited[Z_MAX][Z_MAX];
priority_queue<state> heap;

// fully charged: since_smash = SMASH
int earliest_smash(zombie from, zombie to, int since_smash, int start_time)
{
    assert(0 <= since_smash && since_smash <= SMASH);
    return max(start_time + max(MOVE * from.dist(to), SMASH - since_smash), to.M);
}

void initialize()
{

}

void heap_push(int n, int k, int time)
{
    assert(time >= zombies[n].M);

    if (time < dp[n][k] && time <= zombies[n].M + ZOMBIE)
    {
        dp[n][k] = time;
        heap.push((state) {n, k, time});
    }
}

void dijkstra()
{
    memset(dp, 63, sizeof(dp));
    memset(visited, false, sizeof(visited));
    heap = priority_queue<state>();

    zombie origin;
    origin.X = origin.Y = 0;
    origin.M = INF;

    for (int i = 0; i < Z; i++)
    {
        int early = earliest_smash(origin, zombies[i], SMASH, 0);
        heap_push(i, 1, early);
    }

    while (!heap.empty())
    {
        state top = heap.top(); heap.pop();

        if (visited[top.n][top.k])
            continue;

        visited[top.n][top.k] = true;

        for (int i = 0; i < Z; i++)
            if (i != top.n)
            {
                int early = earliest_smash(zombies[top.n], zombies[i], 0, top.time);
                heap_push(i, top.k + 1, early);
            }
    }
}

void solve_case(int test_case)
{
    scanf("%d", &Z);

    for (int i = 0; i < Z; i++)
        scanf("%d %d %d", &zombies[i].X, &zombies[i].Y, &zombies[i].M);

    dijkstra();
    int best = 0;

    for (int n = 0; n <= Z; n++)
        for (int k = 0; k <= Z; k++)
            if (dp[n][k] < INF)
            {
//                printf("%d %d: %d\n", n, k, dp[n][k]);
                best = max(best, k);
            }

    printf("Case #%d: %d\n", test_case, best);
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
