#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int P, W;
	scanf("%d%d", &P, &W);
	vector<vector<int> > e(P);
	for (int i = 0; i < W; i++) {
		int x, y;
		scanf("%d,%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vector<int> d(P, 123456789);
	queue<int> q;
	d[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < (int)e[cur].size(); i++) {
			if (d[cur] + 1 < d[e[cur][i]]) {
				d[e[cur][i]] = d[cur] + 1;
				q.push(e[cur][i]);
			}
		}
	}
	int D = d[1];
	printf("%d ", D - 1);
	vector<vector<int> > buckets(D + 1);
	for (int i = 0; i < P; i++) {
		if (d[i] <= D) buckets[d[i]].push_back(i);
	}
	vector<vector<int> > e1(P);
	for (int i = 0; i < P; i++) {
		for (int j = 0; j < (int)e[i].size(); j++) {
			if (d[i] + 1 == d[e[i][j]]) {
				e1[i].push_back(e[i][j]);
			}
		}
	}
	vector<bitset<400> > dom(P);
	for (int i = 0; i < P; i++) {
		dom[i].set(i);
		for (int j = 0; j < (int)e[i].size(); j++) {
			dom[i].set(e[i][j]);
		}
	}
	if (D == 1) {
		printf("%d\n", dom[0].count() - 1);
		return;
	}
	vector<vector<int> > dp(P, vector<int>(P, -123456789));
	for (int i = 0; i < (int)e1[0].size(); i++) {
		bitset<400> tmp = dom[0];
		tmp |= dom[e1[0][i]];
		dp[0][e1[0][i]] = tmp.count();
	}
	for (int i = 0; i <= D - 3; i++) {
		for (int j = 0; j < (int)buckets[i].size(); j++) {
			int node1 = buckets[i][j];
			for (int k = 0; k < (int)e1[node1].size(); k++) {
				int node2 = e1[node1][k];
				for (int l = 0; l < (int)e1[node2].size(); l++) {
					int node3 = e1[node2][l];
					bitset<400> tmp = dom[node3];
					bitset<400> tmp1 = dom[node1];
					tmp1.flip();
					tmp &= tmp1;
					tmp1 = dom[node2];
					tmp1.flip();
					tmp &= tmp1;
					int add = tmp.count();
					if (dp[node1][node2] + add > dp[node2][node3]) {
						dp[node2][node3] = dp[node1][node2] + add;
					}
				}
			}
		}
	}
	int best = -123456789;
	for (int i = 0; i < (int)buckets[D - 2].size(); i++) {
		int node1 = buckets[D - 2][i];
		for (int j = 0; j < (int)e1[node1].size(); j++) {
			int node2 = e1[node1][j];
			for (int k = 0; k < (int)e1[node2].size(); k++) {
				int node3 = e1[node2][k];
				if (node3 != 1) continue;
				best = max(best, dp[node1][node2] - D);
			}
		}
	}
	printf("%d\n", best);
}

int main() {
	int nt;
	scanf("%d", &nt);
	for (int it = 1; it <= nt; it++) {
		printf("Case #%d: ", it);
		solve();
	}
	return 0;
}
