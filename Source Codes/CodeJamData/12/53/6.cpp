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

const int N_MAX = 1005;

struct food
{
    long long price, stale;

    bool operator < (const food &other) const
    {
        if (price != other.price)
            return price < other.price;

        return stale > other.stale;
    }
};

int N;
long long M, F, best;
food foods[N_MAX];

void initialize()
{

}

// pair(number of meals, money left over)
pair<long long, long long> meals(long long deliv)
{
    long long money = M - deliv * F, days = 0;
    assert(money >= 0);

    for (int i = 0; i < N; i++)
    {
        long long price = foods[i].price, duration = deliv * foods[i].stale - days;

        if ((double) deliv * foods[i].stale > 4e18)
            duration = (long long) 4e18;

        long long buy = min(money / price, duration);
        assert(buy >= 0);
        money -= buy * price;
        days += buy;
        assert(money >= 0);
        assert(days <= 1e18);
    }

    best = max(best, days);
    return make_pair(days, money);
}

void solve_case(int test_case)
{
    scanf("%lld %lld %d", &M, &F, &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &foods[i].price, &foods[i].stale);
        foods[i].stale++;
    }

    sort(foods, foods + N);
    int new_N = 0;
    long long best_stale = -1;

    for (int i = 0; i < N; i++)
        if (foods[i].stale > best_stale)
        {
            foods[new_N++] = foods[i];
            best_stale = foods[i].stale;
        }

    N = new_N;

// ternary search on the number of deliveries
    long long lo = 0, hi = M / F;
    best = 0;

    while (lo < hi)
    {
        long long mid1 = (lo + hi) / 2, mid2 = mid1 + 1;
        pair<long long, long long> m1 = meals(mid1), m2 = meals(mid2);

        if (m1 > m2)
            hi = mid2 - 1;
        else
            lo = mid1 + 1;
    }

    meals(lo);
    meals(hi);
    printf("Case #%d: %lld\n", test_case, best);
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
