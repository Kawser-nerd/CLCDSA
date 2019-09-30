#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define REPD(i,n) FORD(i,0,n)
#define VAR(v,w) __typeof(w) v=(w)
#define FORE(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define SIZE(c) ((int)(c).size())
#define MP make_pair
#define FT first
#define SD second
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<double> VD;
typedef vector<LD> VLD;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef istringstream ISS;
typedef ostringstream OSS;

int n, k;

VVI g;
int fat[500];
const LL mod = 1000000009;

void gofat(int x, int f) {
	if (fat[x] != -2)
		return;
	fat[x] = f;
	FORE(it,g[x])
		gofat(*it,x);
}

LL solve(int v, int m) {
	LL r = 1;
	LL col = max(k-m-1,0);
	FORE(it,g[v]) if (*it != fat[v]) {
		if (!col)
			return 0;
		r = (r * col) % mod;
		r = (r * solve(*it,SIZE(g[v])-1)) % mod;
		col--;
	}
	return r;
}

int main() {
	int ccc;
	cin >> ccc;
	REP(cc,ccc) {
		cin >> n >> k;
		g.clear();
		g.resize(n);
		REP(i,n-1) {
			int x, y;
			cin >> x >> y;
			g[x-1].PB(y-1);
			g[y-1].PB(x-1);
		}
		int t = -1;
		REP(i,n)
			if (SIZE(g[i]) == 1) {
				t = i;
				break;
			}
		REP(i,n)
			fat[i] = -2;
		gofat(t,-1);
		LL r = (solve(g[t][0],0) * LL(k)) % mod;
		cout << "Case #" << cc+1 << ": " << r << endl;
	}
}
