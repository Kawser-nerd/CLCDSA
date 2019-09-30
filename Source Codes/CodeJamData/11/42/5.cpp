#pragma comment(linker, "/STACK:64000000")

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long getR(vector<vector<long long> > &sum, int x1, int y1, int x2, int y2) {
	return sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1];
}

void solve() {
	int R, C, D;
	cin >> R >> C >> D;
	vector<string> F(R);
	for (int i = 0; i < R; i++) {
		cin >> F[i];
	}
	vector<vector<long long> > sum1(R + 1, vector<long long>(C + 1, 0));
	vector<vector<long long> > sum2(R + 1, vector<long long>(C + 1, 0));
	vector<vector<long long> > sum3(R + 1, vector<long long>(C + 1, 0));
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			sum1[i][j] = sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1] + D + F[i - 1][j - 1] - '0';
			sum2[i][j] = sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1] + (D + F[i - 1][j - 1] - '0' + 0ll) * (i + 0ll);
			sum3[i][j] = sum3[i - 1][j] + sum3[i][j - 1] - sum3[i - 1][j - 1] + (D + F[i - 1][j - 1] - '0' + 0ll) * (j + 0ll);
		}
	}
	for (int k = min(R, C); k >= 3; k--) {
		for (int i = 1; i <= R - k + 1; i++) {
			for (int j = 1; j <= C - k + 1; j++) {
				long long A = getR(sum1, i, j, i + k - 1, j + k - 1) - getR(sum1, i, j, i, j) - getR(sum1, i + k - 1, j, i + k - 1, j) - getR(sum1, i, j + k - 1, i, j + k - 1) - getR(sum1, i + k - 1, j + k - 1, i + k - 1, j + k - 1);
				long long B = getR(sum2, i, j, i + k - 1, j + k - 1) - getR(sum2, i, j, i, j) - getR(sum2, i + k - 1, j, i + k - 1, j) - getR(sum2, i, j + k - 1, i, j + k - 1) - getR(sum2, i + k - 1, j + k - 1, i + k - 1, j + k - 1);
				long long C = getR(sum3, i, j, i + k - 1, j + k - 1) - getR(sum3, i, j, i, j) - getR(sum3, i + k - 1, j, i + k - 1, j) - getR(sum3, i, j + k - 1, i, j + k - 1) - getR(sum3, i + k - 1, j + k - 1, i + k - 1, j + k - 1);
				if (2 * B == A * (2 * i + k - 1) && 2 * C == A * (2 * j + k - 1)) {
					printf("%d\n", k);
					return;
				}
			}
		}
	}
	printf("IMPOSSIBLE\n");
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
