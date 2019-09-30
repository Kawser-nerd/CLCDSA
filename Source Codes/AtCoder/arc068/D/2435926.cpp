#include <iostream>
using namespace std;

long long N, K, dp[2009][2009], mod = 1000000007;

int main() {
	cin >> N >> K;
	dp[0][N + 1] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			int E = N - i + 1;
			if (j > E) continue;
			if (j != 1) dp[i][j] += dp[i - 1][j];
			for (int k = j + 1; k <= N + 1; k++) dp[i][j] += dp[i - 1][k];
			dp[i][j] %= mod;
		}
	}
	long long G = dp[K][1];
	for (int i = 0; i < N - K - 1; i++) { G *= 2; G %= mod; }
	cout << G << endl;
	return 0;
}