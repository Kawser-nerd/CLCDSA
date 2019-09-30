const bool debug = false;

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

const int MaxN = 500;
const int inf = 0x7fffffff;

int N, weight[MaxN];
bool reach[MaxN][MaxN];

int res[MaxN + 2][MaxN + 2], imprv[MaxN + 2], fa[MaxN + 2];

int FlowUp(int s, int t) {
	fill(imprv, imprv + N, 0);
	fill(fa, fa + N, -1);
	imprv[s] = inf;
	bool mark[MaxN + 2] = {0};
	while (!mark[t]) {
		int best = 0, b = -1;
		for (int i = 0; i < N; ++i)
			if (!mark[i] && imprv[i] > best) {
				best = imprv[i];
				b = i;
			}
		if (b == -1) break;
		mark[b] = true;
		for (int i = 0; i < N; ++i) if (!mark[i] && res[b][i] > 0) {
			int d = min(res[b][i], best);
			if (d > imprv[i]) {
				imprv[i] = d;
				fa[i] = b;
			}
		}
	}
	if (!mark[t]) return 0;
	int d = imprv[t];
	for (int i = t; fa[i] != -1; i = fa[i]) {
		res[fa[i]][i] -= d;
		res[i][fa[i]] += d;
	}
	return d;
}

int MaxFlow(int s, int t) {
	int ans = 0, z;
	while ((z = FlowUp(s, t)) > 0)
		ans += z;
	return ans;
}

int Solve2() {
	for (int i = 0; i < N + 2; ++i)
		fill(res[i], res[i] + N + 2, 0);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (reach[i][j])
				res[i][j] = inf;
	for (int i = 0; i < N; ++i)
		if (weight[i] > 0)
			res[N + 0][i] = weight[i];
		else
			res[i][N + 1] = -weight[i];
	N += 2;
	int ans = -MaxFlow(N - 2, N - 1);
	if (debug) cerr << "flow " << -ans << endl;
	for (int i = 0; i < N - 2; ++i)
		ans += max(weight[i], 0);
	return ans;
}

struct Station {
	int x, y, r, s;

	void read() {
		cin >> x >> y >> r >> s;
	}

	bool reaches(Station const& t) const {
		int dx = x - t.x, dy = y - t.y;
		return dx * dx + dy * dy <= r * r;
	}
} ss[MaxN];
int nS;
int mat[MaxN][MaxN];
int group[MaxN];

vector<int> scc_ord;

void SCCDFS1(int u) {
	group[u] = -1;
	for (int i = 0; i < nS; ++i)
		if (mat[i][u] && !group[i])
			SCCDFS1(i);
	scc_ord.push_back(u);
}

void SCCDFS2(int u) {
	group[u] = N;
	for (int i = 0; i < nS; ++i)
		if (group[i] == -1 && mat[u][i])
			SCCDFS2(i);
}

void MarkGroup(int u) {
	group[u] = N;
	for (int i = 0; i < nS; ++i)
		if (group[i] == -1 && mat[u][i] && mat[i][u])
			MarkGroup(i);
}

int solve() {
	cin >> nS;
	for (int i = 0; i < nS; ++i)
		ss[i].read();
	for (int i = 0; i < nS; ++i)
		for (int j = 0; j < nS; ++j)
			mat[i][j] = (i != j && ss[i].reaches(ss[j]));
//	for (int k = 0; k < nS; ++k)
//		for (int i = 0; i < nS; ++i) if (mat[i][k])
//			for (int j = 0; j < nS; ++j) if (mat[k][j])
//				mat[i][j] = true;
/*
	N = 0;
	fill(group, group + nS, -1);
	for (int i = 0; i < nS; ++i)
		if (group[i] == -1) {
			MarkGroup(i);
			++N;
		}
*/

/*
	fill(weight, weight + N, 0);
	for (int i = 0; i < nS; ++i)
		weight[group[i]] += ss[i].s;
	for (int i = 0; i < N; ++i)
		fill(reach[i], reach[i] + N, false);
	for (int i = 0; i < nS; ++i)
		for (int j = 0; j < nS; ++j)
			if (mat[i][j] && group[i] != group[j])
				reach[group[i]][group[j]] = true;
*/
	N = nS;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			reach[i][j] = mat[i][j];
	for (int i = 0; i < N; ++i)
		weight[i] = ss[i].s;
	if (debug) {
		cerr << "group";
		for (int i = 0; i < nS; ++i)
			cerr << ' ' << group[i];
		cerr << endl;
		cerr << "weight";
		for (int i = 0; i < N; ++i)
			cerr << ' ' << weight[i];
		cerr << endl;
		cerr << "edges";
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (reach[i][j])
					cerr << " (" << i << ' ' << j << ")";
		cerr << endl;
	}
	return Solve2();
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        freopen((string(argv[1]) + ".in").c_str(), "r", stdin);
        freopen((string(argv[1]) + ".out").c_str(), "w", stdout);
    }
    int cc = 0, ccc = 0;
    for (cin >> ccc; cc < ccc; ++cc)
            cout << "Case #" << cc + 1 << ": " << solve() << endl;
    return 0;
}
