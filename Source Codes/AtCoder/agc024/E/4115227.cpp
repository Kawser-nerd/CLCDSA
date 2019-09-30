#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, K, M;
	cin >> N >> K >> M;
	vector<vector<int> > comb(N);
	for (int i = 0; i < N; ++i) {
		comb[i].resize(i + 1);
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			comb[i][j] = comb[i - 1][j - 1];
			if (j != i) comb[i][j] = (comb[i][j] + comb[i - 1][j]) % M;
		}
	}
	vector<vector<int> > dp(N + 1, vector<int>(K + 1));
	vector<vector<int> > sum(N + 1, vector<int>(K + 2));
	for (int i = 0; i <= K; ++i) {
		dp[0][i] = 1;
		sum[0][i] = K - i + 1;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= K; ++j) {
			for (int k = 0; k <= i - 1; ++k) {
				int sub = (long long)(sum[k][j + 1]) * dp[(i - 1) - k][j] % M * comb[i - 1][k] % M;
				dp[i][j] = (dp[i][j] + sub) % M;
			}
		}
		for (int j = K; j >= 0; --j) {
			sum[i][j] = (sum[i][j + 1] + dp[i][j]) % M;
		}
	}
	cout << dp[N][0] << endl;
	return 0;
}