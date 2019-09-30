#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50;

int g[N][N];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id;
		printf("Case #%d: ", ++id);
		int n;
		long long t;
		cin >> n >> t;
		int bak = n;
		long long maxs = 1;
		bak -= 2;
		for (int i = 0; i < bak; ++i) {
			maxs <<= 1;
		}
		if (maxs < t) {
			puts("IMPOSSIBLE");
		} else {
			puts("POSSIBLE");
			memset(g, 0, sizeof(g));
			for (int i = 1; i < n; ++i) {
				if (t == maxs || (t >> (bak - i) & 1)) {
					g[0][i] = 1;
				}
				for (int j = i + 1; j < n; ++j) {
					g[i][j] = 1;
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					printf("%d", g[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
