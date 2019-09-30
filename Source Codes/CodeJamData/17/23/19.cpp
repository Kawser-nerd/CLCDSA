
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:36777216")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;
const int MAX_N = 128;
typedef long long LL;
LL E[MAX_N];
LL dist[MAX_N][MAX_N];
double S[MAX_N];
double hour[MAX_N][MAX_N];

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		int N, Q;
		scanf("%d %d", &N, &Q);

		for (int i = 0; i < N; i++) {
			scanf("%lld %lf", &E[i], &S[i]);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%lld", &dist[i][j]);
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
				if (dist[i][k] < -0.5) continue;
				if (dist[k][j] < -0.5) continue;
				if (dist[i][j] < -0.5 || dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) hour[i][j] = 0.0;
				else {
					hour[i][j] = -1;
					
					if (dist[i][j] > -0.5 && dist[i][j] <= E[i]) {
						hour[i][j] = double(dist[i][j]) / S[i];
					}
				}
			}
		}
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (hour[i][k] < -0.5) continue;
					if (hour[k][j] < -0.5) continue;
					if (hour[i][j] < -0.5 || hour[i][j] > hour[i][k] + hour[k][j]) {
						hour[i][j] = hour[i][k] + hour[k][j];
					}
				}
			}
		}

		static int cs = 1;
		printf("Case #%d:", cs++);
		for (int i = 0; i < Q; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			u--; v--;

			printf(" %.9lf", hour[u][v]);
		}
		printf("\n");
	}
	return 0;
}