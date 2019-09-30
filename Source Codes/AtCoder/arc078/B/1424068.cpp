#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;

vector < int > g[maxn];
int p[maxn];

bool used[maxn];
int color[maxn];

void dfs(int v) {
	used[v] = true;
	for (int u : g[v]) {
		if (!used[u]) {
			p[u] = v;
			dfs(u);
		}
	}
}

void paint(int v, int c) {
	used[v] = true;
	color[v] = c;
	for (int u : g[v]) {
		if (!used[u] && color[u] == 0)
			paint(u, c);
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	color[0] = 1;
	color[n - 1] = 2;
	dfs(0);
	for (int i = 0; i < n; i++) {
		used[i] = false;
	}
	vector < int > path;
	int v = n - 1;
	while (v != 0) {
		int pv = p[v];
		if (pv == 0)
			break;
		path.push_back(pv);
		v = pv;
	}
	int l = 0;
	int r = path.size() - 1;
	while (l <= r) {
		color[path[r]] = 1;
		r--;
		if (l <= r) {
			color[path[l]] = 2;
			l++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (color[i] != 0)
			paint(i, color[i]);
	}
	int cnt[3] = {};
	for (int i = 0; i < n; i++) {
		cnt[color[i]]++;
	}
	if (cnt[1] == cnt[2]) {
		cout << "Snuke";
		return 0;
	}
	if (cnt[1] < cnt[2]) {
		cout << "Snuke";
		return 0;
	}
	cout << "Fennec";
	return 0;
}