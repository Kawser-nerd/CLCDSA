#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int MAXN = 1000 + 100;

int n;
vi adj[MAXN];

int dfs(int u, int p=-1) {
	int res = 1;
	vi ch(3,-1);
	forn(i,si(adj[u])) {
		int v = adj[u][i];
		if (v == p) continue;
		ch[2] = dfs(v, u);
		if (ch[2] > ch[1]) swap(ch[2], ch[1]);
		if (ch[1] > ch[0]) swap(ch[1], ch[0]);
	}
	if (ch[1] == -1) return 1;
	return 1 + ch[0] + ch[1];
}

int main() {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ": ";
        	cin >> n;
        	forn(u,n) adj[u].clear();
        	forn(_,n-1) {
        		int u,v; cin >> u >> v;
        		u--; v--;
        		adj[u].pb(v);
        		adj[v].pb(u);
        	}

        	int res = 1;
        	forn(u,n) res = max(res, dfs(u));
        	res = n-res;
        	cout << res << endl;
        }

        return 0;
}

