#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

ll dp[2001][2001];

int main(void)
{
    cin.sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> As(N);
    REP(n,N) cin >> As[n];

    ll prev = 0;
    ll curr = 0;

    ll sum = accumulate(ALL(As), 0LL);
    if (sum == K) {
        cout << 1 << endl;
        return 0;
    }

    FOR(d1, 1, N+1) {
        prev = curr;
        curr = prev + As[d1-1];
        
        if (d1 == 1) {
            dp[1][0] = 0;
            dp[1][1] = 1;
            continue;
        }


        REP(d2, d1+1) {
            ll v1 = dp[d1-1][d2];
            ll v2 = curr * dp[d1-1][d2-1] / prev + 1;

            if (d2 == 0) {
                dp[d1][d2] = v1;
            }
            else if (d2 == d1) {
                dp[d1][d2] = v2;
            }
            else {
                dp[d1][d2] = min(v1, v2);
            }
        }
    }

    ll ans = 0;
    REP(n,N+1) {
        if (dp[N][n] <= K) ans = n;
        else break;
    }
    cout << ans << endl;

    return 0;
}