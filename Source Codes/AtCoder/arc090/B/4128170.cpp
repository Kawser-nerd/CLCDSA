#include <vector>
#include <iostream>
#include <functional>
using namespace std;
struct edge {
	int to, cost;
};
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int L, R, D;
		cin >> L >> R >> D; --L, --R;
		G[L].push_back(edge{ R, D });
		G[R].push_back(edge{ L, -D });
	}
	vector<bool> vis(N); 
	vector<long long> pot(N);
	function<bool(int)> dfs = [&](int pos) {
		vis[pos] = true;
		for (edge e : G[pos]) {
			if (vis[e.to] && e.cost + pot[pos] != pot[e.to]) {
				return false;
			}
			if (!vis[e.to]) {
				pot[e.to] = pot[pos] + e.cost;
				bool res = dfs(e.to);
				if (!res) return false;
			}
		}
		return true;
	};
	bool ans = true;
	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			ans = ans && dfs(i);
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}