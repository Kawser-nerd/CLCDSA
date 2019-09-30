#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 998244353;
constexpr double PI = 3.14159265358979323846;
constexpr int di[] = {0, 0, 1, -1};
constexpr int dj[] = {1, -1, 0, 0};

ll fastPow(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fastPow(x * x % MOD, n / 2);
    else
        return x * fastPow(x, n - 1) % MOD;
}

ll fac[112346];
void combInit(int mx)
{
    fac[0] = 0;
    fac[1] = 1;
    for (int i = 2; i <= mx; i++)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

ll modDiv(ll a, ll b)
{
    return a * fastPow(b, MOD - 2) % MOD;
}

ll comb(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (a < b)
        return 0;
    if (a <= 0 || b < 0)
        return 0;
    if (a == b)
        return 1;

    ll p, c;

    c = modDiv(fac[a], fac[a - b]);
    p = fac[b];

    ll res = modDiv(c, p);

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    combInit(210);

    int n, x[210], y[210];

    ll li[210];
    fill(li, li + n + 1, 0);

    cin >> n;
    REP(i, n)
    cin >> x[i] >> y[i];

    ll res = 0;

    bool used[210][210];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            used[i][j] = i == j;

    V l;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (used[i][j])
                continue;

            V v;

            v.push_back(i);
            v.push_back(j);

            int cnt = 2;
            for (int k = j + 1; k < n; k++)
            {
                int a = (x[j] - x[i]) * (y[k] - y[j]);
                int b = (y[j] - y[i]) * (x[k] - x[j]);

                if (a == b)
                {
                    cnt++;

                    v.push_back(k);
                }
            }

            if (cnt > 2)
            {
                for (int k = 0; k < v.size(); k++)
                    for (int m = 0; m < v.size(); m++)
                        used[v[k]][v[m]] = true;

                l.push_back(cnt);
            }
        }

    for (int i = 3; i <= n; i++)
    {
        ll tmp = 0;
        tmp += comb(n, i);

        for (int j : l)
        {
            if (i > j)
                continue;
            tmp += MOD - comb(j, i);
            tmp %= MOD;
        }

        res += tmp;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}