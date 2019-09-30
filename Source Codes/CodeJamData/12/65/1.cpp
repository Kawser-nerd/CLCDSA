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

const int N_MAX = 12, INF = 1000000005;

int N, left_path[N_MAX], right_path[N_MAX];
bool seen[N_MAX][1 << N_MAX];

void initialize()
{

}

int go(int num, int mask)
{
    if (num == N - 1)
        return 0;

    if (seen[num][mask])
        return INF;

    seen[num][mask] = true;
    mask ^= 1 << num;

    if (mask & 1 << num)
        return go(left_path[num], mask) + 1;
    else
        return go(right_path[num], mask) + 1;
}

void solve_case(int test_case)
{
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &left_path[i], &right_path[i]);
        left_path[i]--; right_path[i]--;
    }

    memset(seen, false, sizeof(seen));
    int answer = go(0, 0);

    printf("Case #%d: ", test_case);

    if (answer < INF)
        printf("%d\n", answer);
    else
        puts("Infinity");
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
