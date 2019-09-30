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
    ll N;
    cin >> N;
    vector<ll> As(N);
    REP(n,N) cin >> As[n];
    map<ll, set<ll>> mnts;
    ll remain = 0LL;
    REP(n,N) {
        mnts[As[n]].insert(n);
        remain += As[n];
    }

    vector<ll> keys;
    for (auto k : mnts) keys.pb(k.first);
    reverse(ALL(keys));

    ll seen = 0;
    vector<ll> ans(N);
    ll rep = 1e9;
    REP(i, SIZE(keys)) {
        auto height = keys[i];
        auto& mnt_idxes = mnts[height];
        seen += SIZE(mnt_idxes);
        if (mnt_idxes.count(0)) {
            ans[0] = remain;
            break;
        }
        auto val = (keys[i] - keys[i+1]) * seen;
        rep = min(rep, *mnt_idxes.begin());
        ans[rep] += val;
        remain -= val;
    }
    for (auto a : ans) cout << a << endl;
    
    return 0;
}