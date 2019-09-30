#pragma comment(linker, "/STACK:10000000")
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const int MOD = 1000003;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans, cnt, id[101][101];
vector<int> adj[20000];
int deg[10000], used[20000];
set<pii> S;
char ss[1000002];

void add(int x, int i, int j) {
	if (i < 0) i += m;
	if (i >= m) i -= m;
	if (j < 0) j += n;
	if (j >= n) j -= n;
	int y = id[i][j];
	deg[y]++;
	adj[x].push_back(y+k);
	adj[y+k].push_back(x);
}

void dfs(int i) {
	used[i] = 1;
	cnt++;
	int _j, j, sz = SZ(adj[i]);
	F0(_j,sz) {
		j = adj[i][_j];
		if (!used[j]) dfs(j);
	}
}

int main() {
//	freopen("c.in", "r", stdin);

//	freopen("C-small-attempt0.in", "r", stdin);
//	freopen("C-small-attempt0.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
		printf("Case #%d: ", tt);

		scanf("%d%d\n", &m, &n);
		k = 0;
		F0(i,m) F0(j,n) id[i][j] = k++;

		F0(i,k) {
			used[i] = used[i+k] = deg[i] = 0;
			adj[i].clear();
			adj[i+k].clear();
		}
		
		F0(i,m) {
			gets(ss);
			F0(j,n) {
				if (ss[j] == '-') {
					add(id[i][j], i, j-1);
					add(id[i][j], i, j+1);
				} else if (ss[j] == '|') {
					add(id[i][j], i-1, j);
					add(id[i][j], i+1, j);
				} else if (ss[j] == '/') {
					add(id[i][j], i-1, j+1);
					add(id[i][j], i+1, j-1);
				} else {
					add(id[i][j], i+1, j+1);
					add(id[i][j], i-1, j-1);
				}
			}
		}
		S.clear();
		F0(i,k)
			S.insert(pii(deg[i], i));
		ans = 1;
		while (!S.empty()) {
			int d = S.begin()->first;
			int i = S.begin()->second;
			S.erase(S.begin());
			if (d == 0) {
				ans = 0;
				break;
			}
			if (d >= 2) break;
			used[i+k] = 1;
			F0(j,SZ(adj[i+k]))
				if (!used[adj[i+k][j]]) break;
			i = adj[i+k][j];
			used[i] = 1;
			F0(l,SZ(adj[i])) {
				j = adj[i][l]-k;
				if (!used[j+k]) {
					S.erase( pii(deg[j], j) );
					deg[j]--;
					S.insert( pii(deg[j], j) );
				}
			}
		}
		if (ans) {
			F0(i,k)
				if (!used[i]) {
					cnt = 0;
					dfs(i);
					if (cnt%2 != 0) throw 9;
					ans = (ans * 2) % MOD;
				}
		}
		cout << ans << endl;
	}
	
	return 0;
}
