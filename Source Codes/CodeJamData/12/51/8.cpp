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

const int N_MAX = 10005;

struct level
{
    int length, prob, original;

    bool operator < (const level &other) const
    {
        return length * other.prob < other.length * prob;
    }
};

int N;
level levels[N_MAX];

void initialize()
{

}

void solve_case(int test_case)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &levels[i].length);

    for (int i = 0; i < N; i++)
        scanf("%d", &levels[i].prob);

    for (int i = 0; i < N; i++)
        levels[i].original = i;

    stable_sort(levels, levels + N);
    printf("Case #%d:", test_case);

    for (int i = 0; i < N; i++)
        printf(" %d", levels[i].original);

    putchar('\n');
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
