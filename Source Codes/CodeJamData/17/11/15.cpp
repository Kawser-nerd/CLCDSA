#include <bits/stdc++.h>
using namespace std;

int TC, R, C;
char g[55][55];
vector<int> rows;

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; i++) scanf("%s", &g[i]);
		rows.clear();
		for (int i = 0; i < R; i++) {
			char p = '?';
			for (int j = 0; j < C; j++) {
				if (g[i][j] != '?') {
					p = g[i][j];
					break;
				}
			}
			if (p == '?') {
				rows.push_back(i);
				continue;
			}
			for (int j = 0; j < C; j++) {
				if (g[i][j] != '?') p = g[i][j];
				else g[i][j] = p;
			}
		}
		int r = -1;
		for (int i = 0; i < R; i++) {
			if (g[i][0] != '?') {
				r = i;
				break;
			}
		}
		for (int i = 0; i < R; i++) {
			if (g[i][0] != '?') r = i;
			else {
				for (int j = 0; j < C; j++) g[i][j] = g[r][j];
			}
		}
		printf("Case #%d:\n", tc);
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) printf("%c", g[i][j]);
			printf("\n");
		}
	}
}
