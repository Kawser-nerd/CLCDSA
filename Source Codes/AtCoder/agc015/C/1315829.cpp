#include<stdlib.h>
#include<cstdio>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<string.h>
#include<iostream>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

bool d[2005][2005];
int K[2005][2005];
int n[2005][2005];//?
int m[2005][2005];//?
char S[2005];
signed main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	for (int e = 0; e < a; e++) {
		scanf("%s", S);
		for (int f = 0; f < b; f++) {
			if (S[f] == '1') {
				d[e][f] = true;
			}
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			K[i][j] = K[i - 1][j] + K[i][j - 1] - K[i - 1][j - 1] + d[i - 1][j - 1];
		}
	}
	for (int i = 1; i < a; i++) {
		for (int j = 1; j <= b; j++) {
			n[i][j] = n[i - 1][j] + n[i][j - 1] - n[i - 1][j - 1] + (d[i - 1][j - 1] && d[i][j - 1]);
		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j < b; j++) {
			m[i][j] = m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1] + (d[i - 1][j - 1] && d[i - 1][j]);
		}
	}
	for (int i = 0; i < c; i++) {
		int dx, dy, ex, ey;
		scanf("%d%d%d%d", &dx, &dy, &ex, &ey);
		dx--; dy--;
		int ans = K[ex][ey] - K[ex][dy] - K[dx][ey] + K[dx][dy];
		ans -= n[ex - 1][ey] - n[ex - 1][dy] - n[dx][ey] + n[dx][dy];
		ans -= m[ex][ey - 1] - m[ex][dy] - m[dx][ey - 1] + m[dx][dy];
		printf("%d\n", ans);
	}
}