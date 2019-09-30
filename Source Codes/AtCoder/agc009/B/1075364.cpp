#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
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

vector<vector<int>> d;
vector<int> cache;

int dfs(int n) {
    if (SIZE(d[n]) == 0) return 0;
    if (cache[n] != -1) return cache[n];
    
    auto size = SIZE(d[n]);


    vector<int> depth;
    for (auto x: d[n]) {
        // cout << "x:" << x << endl;
        depth.pb(dfs(x));
    }
    sort(ALL(depth));

    int o = size;
    int mx = 0;
    for(auto d : depth) {
        mx = max(mx, o + d);
        --o;
    }

    return mx;
}
    

int main(void)
{
    cin.sync_with_stdio(false);
    int N;
    cin >> N;

    d.resize(N+2);
    cache.resize(N+2, -1);

    REP(n, N-1) {
        int loser = n + 2;
        int winner;
        cin >> winner;
        d[winner].push_back(loser);
    }

    cout << dfs(1) << endl;
    return 0;
}