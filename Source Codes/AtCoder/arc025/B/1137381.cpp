#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string>
#include<unordered_set>
#include<map>
using namespace std;

int e[100][100];
int rui[101][101];
signed main() {
	int a, b; scanf("%d%d", &a, &b);
	for (int c = 0; c < a; c++) {
		for (int d = 0; d < b; d++) {
			scanf("%d", &e[c][d]);
			if ((c + d) & 1)e[c][d] *= -1;
		}
	}
	for (int c = 1; c <= a; c++) {
		for (int d = 1; d <= b; d++) {
			rui[c][d] = rui[c - 1][d] + rui[c][d - 1] - rui[c - 1][d - 1] + e[c - 1][d - 1];
		}
	}
	int MAX = 0;
	for (int c = 0; c < a; c++) {
		for (int d = 0; d < b; d++) {
			for (int x = c + 1; x <= a; x++) {
				for (int y = d + 1; y <= b; y++) {
					if (rui[x][y]-rui[c][y]-rui[x][d]+rui[c][d]==0) {
						MAX = max(MAX, (x - c)*(y - d));
					}
				}
			}
		}
	}
	printf("%d\n", MAX);
}