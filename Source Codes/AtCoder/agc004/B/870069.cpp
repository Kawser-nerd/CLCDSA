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

int main(void)
{
    cin.sync_with_stdio(false);
    ll N, x;
    cin >> N >> x;
    vector<ll> As(N);
    REP(n,N) cin >> As[n];
    
    // vector<ll> Bs;
    // auto itr = min_element(ALL(As));
    // auto mn_idx = distance(begin(As), itr);
    // FOR(i,mn_idx,N) {
    //     Bs.pb( As[i] );
    // }
    // REP(i,mn_idx) {
    //     Bs.pb( As[i] );
    // }

    // // for(auto b: Bs) cout << b << ",";
    // // cout << endl;

    // As = Bs;

    vector<ll> costs = As;
    ll ans = accumulate(ALL(costs), 0LL);
    REP(k,N) { // ?????????????
        vector<ll> new_costs(N);
        REP(n,N) {
            new_costs[n] = min(costs[n], As[(n - k + N) % N]);
        }
        costs = new_costs;
        ans = min(ans, accumulate(ALL(costs), 0LL) + k * x);
    }
    cout << ans << endl;

    // ll longest_streak = 0;
    // ll ans = As[0];
    // FOR(n,1,N) {
    //     ll cost = As[n];
    //     for(int n2 = n-1; n2 >= 0; --n2) {
    //         ll diff = n - n2;
    //         ll cost2 = diff * x;
    //         if (cost2 < cost) {
    //             longest_streak = max(longest_streak, diff);
    //             cost = As[n2];
    //         }
    //     }
    //     ans += cost;
    // }
    // ans += longest_streak * x;
    
    // cout << ans << endl;
    return 0;
}