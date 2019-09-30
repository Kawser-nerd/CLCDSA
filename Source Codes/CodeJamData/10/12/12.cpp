#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>

#define INF 1000000000
#define EPS 1E-8
#define PI 3.14159265358979

using namespace std;

int pix[110];
int dp[110][260];

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		printf("Case #%d: ", t + 1);
		int D, I, M, N;
		cin >> D >> I >> M >> N;
		for(int i = 0; i < N; ++i) cin >> pix[i];
		dp[0][256] = 0;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < 257; ++j) dp[i + 1][j] = INF;
			for(int j = 0; j < 257; ++j) {
				for(int k = 0; k < 256; ++k) if(M != 0 || j == k) {
					int cost = abs(pix[i] - k);
					if(j != 256 && k != j) cost += max((abs(k - j) - 1), 0) / M * I;
					dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cost);
				}
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + D);
			}
		}
		int c = INF;
		for(int i = 0; i < 257; ++i) c = min(c, dp[N][i]);
		cout << c << endl;
	}
	return 0;
}
