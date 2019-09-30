#include <vector>
#include <iostream>
using namespace std;
bool dp[55][55][55]; // (maximum k, current, goal)
int main() {
	for (int i = 0; i <= 50; ++i) {
		for (int j = 0; j <= 50; ++j) {
			for (int k = 0; k <= j; ++k) {
				if (j == k) dp[i][j][k] = true;
				else if (i != 0 && dp[i - 1][j][k]) dp[i][j][k] = true;
				else if (i != 0 && dp[i - 1][j % i][k]) dp[i][j][k] = true;
			}
		}
	}
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	vector<long long> cur(N);
	for (int i = 0; i < N; ++i) {
		cur[i] |= 1LL << A[i];
	}
	long long ans = 0;
	for (int i = 51; i >= 1; --i) {
		bool exec = false;
		for (int j = 0; j < N; ++j) {
			bool ok = false;
			for (int k = 0; k <= 50; ++k) {
				if (((cur[j] >> k) & 1) && dp[i - 1][k][B[j]]) {
					ok = true;
				}
			}
			if (!ok) exec = true;
		}
		if (exec) {
			if (i == 51) {
				ans = -1;
				break;
			}
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k <= 50; ++k) {
					if ((cur[j] >> k) & 1) {
						cur[j] |= 1LL << (k % i);
					}
				}
			}
			ans += 1LL << i;
		}
	}
	cout << ans << endl;
	return 0;
}