#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int INF = 100000000;
const int MAXN = 111111 * 2;
int val[MAXN], l[MAXN], r[MAXN], odd[MAXN];
int n, K;
vector<int> adj[MAXN];

inline bool dfs(int u, int fa) {
//cout << u << " -------- " << fa << endl;
	if (val[u] == INF) {
		l[u] = -INF, r[u] = INF;
		odd[u] = -1;
	} else {
		l[u] = r[u] = val[u];
		odd[u] = val[u] & 1;
	}
	for (int i = 0; i < adj[u].size(); ++i) {
	int v = adj[u][i];
//cout << "e: " << u << " " << v << endl;
		if (v != fa) {
			if (!dfs(v, u)) {
				return false;
			}
			int ll = l[v] - 1, rr = r[v] + 1;
			int o = odd[v] == -1 ? -1 : odd[v] ^ 1;
			l[u] = max(l[u], ll);
			r[u] = min(r[u], rr);
			if (l[u] > r[u]) {
				return false;
			}
			if (o == -1) {
				continue;
			}
			if (odd[u] == -1) {
				odd[u] = o;
			} else {
				if (o != odd[u]) {
					return false;
				}
			}
//cout << l[u] << " " << r[u] << " " << odd[u] << " " << o << endl;
			if (odd[u] != -1) {
				int t1 = l[u], t2 = min(l[u] + 1, r[u]);
				if (((t1 % 2) + 2) % 2 != odd[u] && ((t2 % 2) + 2) % 2 != odd[u]) {
// << "asdf" << endl;
					return false;
				}
			}
		}
	}
//cout << u << " " << l[u] << " " << r[u] << " " << odd[u] << endl;
	return true;
}

inline bool check_in(int x, int l, int r, int o) {
	if (x < l || x > r) {
		return false;
	}
	return o == -1 || ((x % 2) + 2) % 2 == o;
}

inline void solve(int u, int fa) {
//cout << u << " " << fa << " " << val[u] << endl;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (v == fa) {
			continue;
		}
		int t1 = val[u] - 1, t2 = t1 + 2;
		if (check_in(t1, l[v], r[v], odd[v])) {
			val[v] = t1;
		} else {
			if (check_in(t2, l[v], r[v], odd[v])) {
				val[v] = t2;
			} else {
				assert(false);
			}
		}
		solve(v, u);
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		val[i] = INF;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cin >> K;
	for (int i = 1; i <= n; ++i) {
		int u, value; 
		cin >> u >> value;
		val[u] = value;
	}
	
	if (!dfs(1, 0)) {
		cout << "No" << endl;
		return 0;
	} else {
		if (odd[1] == -1 || ((l[1] % 2) + 2) % 2 == odd[1]) {
			val[1] = l[1];
		} else {
			val[1] = l[1] + 1;
		}
		solve(1, 0);
		
		cout << "Yes" << endl;
		for (int i = 1; i <= n; ++i) {
			cout << val[i] << endl;
		}
	} 
}