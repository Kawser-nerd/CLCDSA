#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

const int INF=1e9;
const ll INFF=1e17;
const double EPS=1e-9;
const ll MOD=1e9+7;
const int MAXN=1e5+10;
int n,gr[MAXN];
bool vis[MAXN];
vector<vector<int> > g(MAXN);
void dfs(int v){
	gr[v]=0;
	vis[v]=1;
	for(auto u:g[v]){if(!vis[u]){dfs(u);gr[v]^=(gr[u]+1);}}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	REP(i,n-1){
		int t1,t2;
		cin >> t1 >> t2;t1--;t2--;
		g[t1].pb(t2);
		g[t2].pb(t1);
	}
	REP(i,n)vis[i]=0;
	dfs(0);
	cout << (!gr[0]?"Bob":"Alice") << '\n';
	return 0;
}