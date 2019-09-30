?// ?????s=x+y, t=x-y????????
// ???????????

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <climits>
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

ll N, a, b;
vector<pair<ll,ll>> raw_points;
map<ll, vector<pair<ll,int>>> S;
map<ll, vector<pair<ll,int>>> T;
map<ll, set<pair<ll, ll>>> S_set;
map<ll, set<pair<ll, ll>>> T_set;
vector<pair<ll,ll>> points_st;
vector<pair<ll,ll>> points_ts;
// map<pair<ll,ll>,ll> st_to_index;
// map<pair<ll,ll>,ll> ts_to_index;
ll dist;

set<ll> find_neighbors_new(ll n) {
    set<ll> ans;

    auto& p = points_st[n];
    auto it = S_set[p.first + dist].lower_bound(mp(p.second - dist, 0));
    while(it != S_set[p.first + dist].end() && it->first <= p.second + dist) {
        ans.insert(it->second);
        ++it;
    }

    it = S_set[p.first - dist].lower_bound(mp(p.second - dist, 0));
    while(it != S_set[p.first - dist].end() && it->first <= p.second + dist) {
        ans.insert(it->second);
        ++it;
    }
    
    it = T_set[p.second + dist].lower_bound(mp(p.first - dist, 0));
    while(it != T_set[p.second + dist].end() && it->first <= p.first + dist) {
        ans.insert(it->second);
        ++it;
    }

    it = T_set[p.second - dist].lower_bound(mp(p.first - dist, 0));
    while(it != T_set[p.second - dist].end() && it->first <= p.first + dist) {
        ans.insert(it->second);
        ++it;
    }

    return ans;
}

// vector<ll> find_neighbors(ll n) {
//     set<ll> ans1 = find_neighbors_onedir(S_set, points_st, st_to_index, n);
//     set<ll> ans2 = find_neighbors_onedir(T_set, points_ts, ts_to_index, n);
//     for (auto p : ans2) {
//         ans1.pb(p);
//     }
//     return ans1;
// }

ll count_pairs(ll n) {
    ll ret = 0;
    auto& p = points_st[n];
    auto s = p.first;
    auto t = p.second;
    ret += lower_bound(ALL(S[s + dist]), mp(t + dist + 1, 0)) - lower_bound(ALL(S[s + dist]), mp(t - dist, 0)); // ?????? 
    ret += lower_bound(ALL(S[s - dist]), mp(t + dist + 1, 0)) - lower_bound(ALL(S[s - dist]), mp(t - dist, 0)); // ?????? 
    ret += lower_bound(ALL(T[t + dist]), mp(s + dist, 0)) - lower_bound(ALL(T[t + dist]), mp(s - dist + 1, 0)); // ????????
    ret += lower_bound(ALL(T[t - dist]), mp(s + dist, 0)) - lower_bound(ALL(T[t - dist]), mp(s - dist + 1, 0)); // ????????
    return ret;
}

set<ll> seen;
ll dfs(ll n) {
    ll ans = 0;
    seen.insert(n);
    //cout << "n:" << n << endl;

    // ??????????????????????
    auto p = points_st[n];
    S_set[p.first].erase(mp(p.second, n));
    T_set[p.second].erase(mp(p.first, n));

    auto pair_num = count_pairs(n);
    //cout << n << "'s pair_num: " << pair_num << endl;

    ans += pair_num;
    auto neighbors = find_neighbors_new(n);
    //cout << n << "'s neighbors: " << endl;
    for (auto& nei: neighbors) {
        auto p = points_st[nei];
        //cout << "  " << nei << endl;
        S_set[p.first].erase(mp(p.second, nei));
        T_set[p.second].erase(mp(p.first, nei));
    }
    
    for (auto& nei: neighbors) {
        if (n == nei) continue;
        if (!seen.count(nei)) {
            ans += dfs(nei);
        }
    }
    return ans;
}

int main(void)
{
    cin.sync_with_stdio(false);
    cin >> N >> a >> b;
    --a; --b;
    raw_points.resize(N);
    points_st.resize(N);
    points_ts.resize(N);
    
    REP(n,N) {
        ll x, y;
        cin >> x >> y;
        raw_points[n] = mp(x,y);
        ll s = x + y;
        ll t = x - y;
        points_st[n] = mp(s,t);
        points_ts[n] = mp(t,s);
        S[s].pb(mp(t,n));
        T[t].pb(mp(s,n));
        S_set[s].insert(mp(t, n));
        T_set[t].insert(mp(s, n));
        // st_to_index[mp(s,t)] = n;
        // ts_to_index[mp(t,s)] = n;
    }
    for(auto& kv: S) sort(ALL(kv.second));
    for(auto& kv: T) sort(ALL(kv.second));

    auto p1 = raw_points[a];
    auto p2 = raw_points[b];
    dist = (ll)abs(p1.first - p2.first) + (ll)abs(p1.second - p2.second);

    ll ans = dfs(a);
    cout << ans / 2 << endl;

    return 0;
}