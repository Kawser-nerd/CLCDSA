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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll h, w, K, dp[110][10];
    cin >> h >> w >> K;

    REP(i, 110)
    REP(j, 10)
    dp[i][j] = 0;

    dp[0][1] = 1;

    for (ll i = 0; i <= h; i++)
    {
        ll tmp[10][3];
        for (ll j = 1; j <= w; j++)
        {
            ll d = 0, r = 0, l = 0;
            for (ll k = 0; k < 1 << (w - 1); k++)
            {
                ll k_ = k;
                bool b = true, c = false;
                while (k_ > 0)
                {
                    if (k_ % 2 && c)
                        b = false;

                    if (k_ % 2)
                        c = true;
                    else
                        c = false;

                    k_ /= 2;
                }

                if (!b)
                    continue;

                if (j < w && (k & (1 << (j - 1))))
                {
                    r++;
                }
                else if (1 < j && (k & (1 << (j - 2))))
                    l++;
                else
                    d++;
            }

            tmp[j][0] = (dp[i][j] * r) % MOD;
            tmp[j][1] = (dp[i][j] * l) % MOD;
            tmp[j][2] = (dp[i][j] * d) % MOD;
        }

        for (int j = 1; j <= w; j++)
        {
            dp[i + 1][j + 1] += tmp[j][0];
            dp[i + 1][j - 1] += tmp[j][1];
            dp[i + 1][j] += tmp[j][2];

            dp[i + 1][j + 1] %= MOD;
            dp[i + 1][j - 1] %= MOD;
            dp[i + 1][j] %= MOD;
        }
    }

    if (false)
        REP(i, h + 1)
        {
            REP(j, w)
            {
                cout << dp[i][j + 1] << " ";
            }
            cout << endl;
        }

    cout << dp[h][K] << endl;

    return 0;
}