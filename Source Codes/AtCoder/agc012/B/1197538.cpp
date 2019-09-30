#include<iostream>
#include<string.h>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int ans[100000];
vector<int>rinsetu[100000];
int mincost[100000];
int E[100000], F[100000], G[100000];
int K[100000];//??????????????????
signed main() {
	memset(ans, -1, sizeof(ans));
	memset(K, -1, sizeof(K));
	int a, b;
	scanf("%d%d", &a, &b);
	for (int c = 0; c < b; c++) {
		int d, e; scanf("%d%d", &d, &e); d--; e--;
		rinsetu[d].push_back(e);
		rinsetu[e].push_back(d);
	}
	int c; scanf("%d", &c);
	for (int d = 0; d < c; d++) {
		int e, f, g; scanf("%d%d%d", &e, &f, &g);
		e--;
		E[c - d - 1] = e;
		F[c - d - 1] = f;
		G[c - d - 1] = g;
	}
	for (int d = 0; d < c; d++) {
		int e = E[d], f = F[d], g = G[d];
		memset(mincost, -1, sizeof(mincost));
		mincost[e] = 0;
		queue<int>Q;
		Q.push(e);
		while (Q.size()) {
			int i = Q.front(); Q.pop();
			if (mincost[i] > f)break;
			if (K[i] < f - mincost[i]) {
				K[i] = f - mincost[i];
			}
			else continue;
			if (ans[i] == -1)ans[i] = g;
			for (int j : rinsetu[i]) {
				if (mincost[j] == -1) {
					mincost[j] = mincost[i] + 1;
					Q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < a; i++) {
		if (ans[i] == -1)puts("0");
		else  printf("%d\n", ans[i]);
	}
}