#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX_N = 1024;

int nxt[MAX_N];
int N;

int chk[MAX_N];
int order[MAX_N];
int power[MAX_N];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		vector<pair<int, int> > pr;
		int sol = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &nxt[i]);
			nxt[i] --;
			chk[i] = 0;
		}
		int level = 1;
		for (int i = 0; i < N; i++) {
			if (i == nxt[i]) {
				sol = max(sol, 1);
				continue;
			}
			if (chk[i] == 0) {
				int a = i, cnt =0 ;
				while (chk[a] == 0) {
					chk[a] = level;
					order[a] = cnt;
					a = nxt[a];
					cnt++;
				}
				if (chk[a] == level) {
					int sz = cnt - order[a];
					if (sz > 2) {
						sol = max(sol, sz);
					}
					else {
						int b = nxt[a];
						pr.push_back(make_pair(a, b));
						nxt[a] = nxt[b] = -1;
					}
				}
				level++;
			}
		}
		for (int i = 0; i < N; i++) power[i] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int k = nxt[j];
				if (k == -1)continue;
				if (power[k] < power[j] + 1) power[k] = power[j] + 1;
			}
		}
		int tsol = 0;
		for (auto p : pr) {
			int a = p.first;
			int b = p.second;
			tsol += power[a] + power[b];
		}
		sol = max(sol, tsol);
		printf("Case #%d: %d\n", tc, sol);
	}
	return 0;
}