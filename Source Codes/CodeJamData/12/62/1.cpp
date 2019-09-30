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

const int N_MAX = 10005, F_MAX = 1000005;

struct activity
{
    int A, B, C;

    bool operator < (const activity &other) const
    {
        return (long long) A * other.B > (long long) other.A * B;
    }
};

int N, K, F;
activity act[N_MAX];
double sorted[F_MAX];
double pref_product[F_MAX], suf_product[F_MAX];
double pref_sum[F_MAX], suf_sum[F_MAX];

void initialize()
{

}

void solve_case(int test_case)
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
        scanf("%d/%d %d", &act[i].A, &act[i].B, &act[i].C);

    sort(act, act + N);
    F = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < act[i].C; j++)
            sorted[F++] = (double) act[i].A / act[i].B;
/*
    printf("%d\n", F);

    for (int i = 0; i < F; i++)
        printf("%.2lf\n", sorted[i]);
*/
// N is dead now
    N = INT_MAX;

    pref_product[0] = 1;

    for (int i = 0; i < F; i++)
        pref_product[i + 1] = pref_product[i] * sorted[i];

    suf_product[F] = 1;

    for (int i = F - 1; i >= 0; i--)
        suf_product[i] = (1 - sorted[i]) * suf_product[i + 1];

    pref_sum[0] = 1;

    for (int i = 0; i < F; i++)
        pref_sum[i + 1] = pref_sum[i] * (1 - sorted[i]) + pref_product[i + 1];

    suf_sum[F] = 1;

    for (int i = F - 1; i >= 0; i--)
        suf_sum[i] = sorted[i] * suf_sum[i + 1] + suf_product[i];
/*
    for (int i = 0; i <= F; i++)
        printf("%lf %lf %lf %lf\n", pref_product[i], suf_product[i], pref_sum[i], suf_sum[i]);
*/
    double best = 0;

    for (int left = 0; left <= K; left++)
    {
        int right = F - (K - left);
        double prob = pref_product[left] * suf_sum[right] + pref_sum[left] * suf_product[right] - pref_product[left] * suf_product[right];
        best = max(best, prob);
    }

    printf("Case #%d: %.9lf\n", test_case, 1 - best);
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
        solve_case(tc);

    return 0;
}
