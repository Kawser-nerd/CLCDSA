#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

ll fastPow(ll x, ll n, ll mod)
{
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(x * x % mod, n / 2, mod);
    else
        return x * fastPow(x, n - 1, mod) % mod;
}

int main()
{
    int n;
    scanf("%d", &n);
    map<int, int> num;
    int Max = 0;
    REP(i, n)
    {
        int a;
        scanf("%d", &a);
        num[a]++;
        Max = max(Max, a);
        if (!i && a != 0)
        {
            printf("0\n");
            return 0;
        }
    }
    if (num[0] != 1)
    {
        printf("0\n");
        return 0;
    }

    ll ans = 1;
    FOR(i, 1, Max + 1)
    {
        ll cur = num[i];
        ll bef = num[i - 1];

        ans *= fastPow(fastPow(2, bef, MOD) - 1, cur, MOD);
        ans %= MOD;
        ans *= fastPow(2, cur * (cur - 1) / 2, MOD);

        ans %= MOD;
    }

    printf("%lld\n", ans);
    return 0;
}