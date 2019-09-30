#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#define REP(i,n) for(ll i=0;i<(n);i++)
#define MOD 1000000007
#define int long long
#ifdef int
const long long INF = LLONG_MAX / 10;
#else
const int INF = 1010101010;
#endif
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
typedef pair<int, int> P;
//typedef pair<double, double> P;
 
int N;
int a, b;
 
vector<int> G[101010];
vector<int> GG[101010];
 
void dfs(int v, int p)
{
    for (int ne : G[v]) {
        if (ne == p) continue;
        GG[v].push_back(ne);
        dfs(ne, v);
    }
}
 
int dp[101010][2];
 
int rec(int v, int color)
{
    if (dp[v][color] != -1) return dp[v][color];
 
    int res = 1;
    for (int ne : GG[v]) {
        if (color == 0) {
            res *= rec(ne, 1);
        } else {
            res *= rec(ne, 0) + rec(ne, 1);
        }
        res %= MOD;
    }
    return dp[v][color] = res;
}
 
signed main()
{
    cin >> N;
    REP(i,N-1) {
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    dfs(0, -1);
 
    memset(dp, -1, sizeof dp);
    cout << (rec(0, 0) + rec(0, 1)) % MOD << endl;
}