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

using P = pair<ll,ll>;

int main(void)
{
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    vector<P> down;
    vector<ll> same;
    vector<P> up;
    REP(n,N) {
        ll a, b;
        cin >> a >> b;
        if (a < b) {
            down.pb( mp(a, b) );
        }
        else if (a == b) {
            same.pb(a);
        }
        else {
            // ???????
            up.pb( mp(-b, a) );
        }
    }

    sort(ALL(down));
    sort(ALL(same));
    sort(ALL(up));
    
    ll ans = -100;
    ll cur = 0;
    for(auto p : down) {
        ans = max(ans, cur + p.first);
        cur += p.first - p.second;
    }
    for(auto e : same) {
        ans = max(ans, cur + e);
    }

    for(auto p : up) {
        ans = max(ans, cur + p.second);
        cur += p.first + p.second;
    }

    cout << ans << endl;

    return 0;
}