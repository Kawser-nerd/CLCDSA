#include <bits/stdc++.h>
using namespace std;
int t, n, q;
double d[200][200];
double f[200];
double e[200];
double s[200];
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &e[i], &s[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%lf", &d[i][j]);
				if (d[i][j] < 0) {
					d[i][j] = 1e17;
				}
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		printf("Case #%d:", tt);
		for (int i = 0; i < q; i++) {
			queue<int>q;
			int start, end;
			scanf("%d%d", &start, &end);
			start--;
			end--;
			for (int j = 0; j < n; j++) {
				f[j] = 1e17;
			}
			f[start] = 0;
			q.push(start);
			while (q.size()) {
				int u = q.front();
				q.pop();
				for (int j = 0; j < n; j++) {
					if (d[u][j] <= e[u] && f[j] > f[u] + d[u][j] / s[u]) {
						f[j] = f[u] + d[u][j] / s[u];
						q.push(j);
					}
				}
			}
			printf(" %.6f", f[end]);
		}
		printf("\n");
	}
	return 0;
}