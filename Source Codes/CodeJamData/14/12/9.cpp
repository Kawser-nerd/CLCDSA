#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

const int INF = INT_MAX / 4;
vector<vector<int> > edges;
vector<vector<pair<int, int> > > memo;

// first  : 木にするために必要なコスト
// second : 全てのノードを削除するために必要なコスト
pair<int, int> dfs(int curr, int prev)
{
    if(memo[curr][prev].first != -1)
        return memo[curr][prev];

    vector<int> dp(3, INF);
    dp[0] = 0;
    for(unsigned i=0; i<edges[curr].size(); ++i){
        int next = edges[curr][i];
        if(next == prev)
            continue;

        pair<int, int> p = dfs(next, curr);
        dp[2] = min(dp[1] + p.first, dp[2] + p.second);
        dp[1] = min(dp[0] + p.first, dp[1] + p.second);
        dp[0] += p.second;
    }

    return memo[curr][prev] = make_pair(min(dp[0], dp[2]), dp[0] + 1);
}

int solve()
{
    int n;
    cin >> n;

    edges.assign(n+1, vector<int>());
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int ret = INT_MAX;
    memo.assign(n+1, vector<pair<int, int> >(n+1, make_pair(-1, -1)));
    for(int i=1; i<=n; ++i)
        ret = min(ret, dfs(i, 0).first);

    return ret;
}

int main()
{
    int T;
    cin >> T;

    for(int tc=1; tc<=T; ++tc){
        int ret = solve();
        cout << "Case #" << tc << ": " << ret << endl;
    }

    return 0;
}