#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;

typedef long long int64;
#define PB push_back
#define MP make_pair
#define debug(x) cout<<(#x)<<": "<<(x)<<endl
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define MOD 1000000007

inline int ADD(int a, int b) { a+=b; if (a>=MOD) a-=MOD; return (int)a; }
inline void ADDTO(int &a, int b) { a+=b; if (a>=MOD) a-=MOD; }
inline void SUBTO(int &a, int b) { a-=b; if (a<0) a+=MOD; }
inline int MUL(int a, int b) { return (int)((int64)a*b%MOD); }

int loop[30], indeg[30], oudeg[30], e[30][30], vis[30];
int fact[110], ans;

void addEdge(char a, char b) {
	int u = a - 'a', v = b - 'a';
	++oudeg[u];
	++indeg[v];
	e[u][v] = 1;
}

void dfs(int u) {
	vis[u] = 1;
	ans = MUL(ans, fact[loop[u]]);
	if (oudeg[u] > 0) {
		REP(v, 26) if (e[u][v] == 1) dfs(v);
	}
}

int main() {
	int tN;
	cin >> tN;
	fact[0] = 1;
	FOR(i, 1, 100) fact[i] = MUL(i, fact[i-1]);
	FOR(cN, 1, tN) {
		memset(loop, 0, sizeof(loop));
		memset(indeg, 0, sizeof(indeg));
		memset(oudeg, 0, sizeof(oudeg));
		memset(e, 0, sizeof(e));
		memset(vis, 0, sizeof(vis));
		int n;
		cin >> n;
		REP(i, n) {
			string s;
			cin >> s;
			bool same = 1;
			REP(i, s.size()) {
				if (s[i] != s[0]) same = 0;
				if (i && s[i] != s[i-1]) addEdge(s[i-1], s[i]);
			}
			if (same) ++loop[s[0] - 'a'];
		}
		bool nosol = 0;
		REP(i, 26) if (indeg[i] > 1 || oudeg[i] > 1) nosol = 1;
		if (!nosol) {
			ans = 1;
			int ncc = 0;
			REP(i, 26) if (!vis[i] && indeg[i] == 0) {
				if (oudeg[i] > 0 || loop[i] > 0) ++ncc;
				dfs(i);
			}
			ans = MUL(ans, fact[ncc]);
			REP(i, 26) if (!vis[i]) nosol = 1;
		}
		printf("Case #%d: ", cN);
		if (nosol) puts("0");
		else printf("%d\n", ans);
	}
}
