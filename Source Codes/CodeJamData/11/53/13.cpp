#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define V2D(A, T, N, M, V) vector<vector<T> > A(N, vector<T>(M, V))
#define V3D(A, T, N, M, K, V) vector<vector<vector<T> > > A(N, vector<vector<T> >(M, vector<T>(K, V)))

void norm(int R, int C, int &x, int &y) {
	x = ((x % R) + R) % R;
	y = ((y % C) + C) % C;
}

void addEdge(vector<vector<vector<pair<int, int> > > > &e, int R, int C, int x1, int y1, int x2, int y2) {
	norm(R, C, x1, y1);
	norm(R, C, x2, y2);
	e[x1][y1].push_back(make_pair(x2, y2));
	e[x2][y2].push_back(make_pair(x1, y1));
}

void dfs(vector<vector<vector<pair<int, int> > > > &e, vector<vector<char> > &was, int &nodes, int &edges, int x, int y) {
	was[x][y] = 1;
	nodes++;
	edges += (int)e[x][y].size();
	for (int i = 0; i < (int)e[x][y].size(); i++) {
		int x1 = e[x][y][i].first;
		int y1 = e[x][y][i].second;
		if (was[x1][y1]) continue;
		dfs(e, was, nodes, edges, x1, y1);
	}
}

void solveTest() {
	int R, C;
	cin >> R >> C;
	vector<string> F(R);
	for (int i = 0; i < R; i++) {
		cin >> F[i];
	}
	vector<vector<vector<pair<int, int> > > > e(R, vector<vector<pair<int, int> > >(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (F[i][j] == '-') {
				addEdge(e, R, C, i, j - 1, i, j + 1);
			}
			else if (F[i][j] == '|') {
				addEdge(e, R, C, i - 1, j, i + 1, j);
			}
			else if (F[i][j] == '/') {
				addEdge(e, R, C, i + 1, j - 1, i - 1, j + 1);
			}
			else if (F[i][j] == '\\') {
				addEdge(e, R, C, i - 1, j - 1, i + 1, j + 1);
			}
			else {
				assert(false);
			}
		}
	}
	vector<vector<char> > was(R, vector<char>(C, 0));
	int components = 0;
	int nodes = 0;
	int edges = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (was[i][j]) continue;
			components++;
			nodes = 0;
			edges = 0;
			dfs(e, was, nodes, edges, i, j);
			if (edges != 2 * nodes) {
				cout << 0 << endl;
				return;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < components; i++) {
		ans = ans * 2;
		ans = ans % 1000003;
	}
	cout << ans << endl;
}

int main() {
	int nt;
	cin >> nt;
	for (int it = 1; it <= nt; ++it) {
		printf("Case #%d: ", it);
		solveTest();
	}
	return 0;
}
