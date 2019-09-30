#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10005;

int n;

char s[N];

#define next NEXT

int next[N][10];

int dp[N][N], cut[N][2][10];

inline int cost(int l, int r) {
	if (l > r) {
		return 0;
	} else {
		return dp[l][r - l];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		n = strlen(s);
		/*
		n = 10000;
		for (int i = 0; i < n; ++i) {
			s[i] = rand() % 9 + 1 + '0';
		}
		*/
		for (int i = 0; i < 10; ++i) {
			next[n][i] = n;
			next[n + 1][i] = n;
		}
		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < 10; ++j) {
				next[i][j] = next[i + 1][j];
			} 
			next[i][s[i] - '0'] = i;
		}
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			dp[i][0] = s[i] - '0';
			for (int j = 0; j < 10; ++j) {
				cut[i][0][j] = next[i][j];
			}
		}
		for (int l = 1; l < n; ++l) {
			int nxt = cur ^ 1;
			for (int i = 0; i + l < n; ++i) {
				dp[i][l] = N * 10;
				int j = i + l;
				for (int k = 0; k < 10; ++k) {
					int u = cut[i][cur][k], v = next[u + 1][k];
					while (v <= j && dp[u][0] + max(cost(i, u - 1), cost(u + 1, j)) >= dp[v][0] + max(cost(i, v - 1), cost(v + 1, j))) {
						u = v;
						v = next[u + 1][k];
					}
					if (u <= j) {
						dp[i][l] = min(dp[i][l], dp[u][0] + max(cost(i, u - 1), cost(u + 1, j)));
					}
					cut[i][nxt][k] = u;
				}
			}
			cur = nxt;
		}
		static int id = 0;
		printf("Case #%d: %d\n", ++id, dp[0][n - 1]);
		cerr << t << endl;
	}
	return 0;
}
