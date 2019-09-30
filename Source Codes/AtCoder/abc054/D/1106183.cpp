#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

int main() {
	int n, ma, mb;

	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	VVVI dp(n + 1, VVI(401, VI(401, inf)));
	dp[0][0][0] = 0;

	for (int i = 0; i < n; i++) {
	for (int j = 0; j < 401; j++) {
	for (int k = 0; k < 401; k++) {
			if (dp[i][j][k] == inf) {
				continue;
			}

			int j2 = j + a[i];
			int k2 = k + b[i];

			dp[i+1][j2][k2] = min(dp[i+1][j2][k2], dp[i][j][k] + c[i]);
			dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
	}}}

	int min_cost = inf;
	for (int i = 1; i <= n; i++) {
	for (int j = 0; j < 401; j++) {
	for (int k = 0; k < 401; k++) {
		if (dp[i][j][k] == inf || dp[i][j][k] == 0) {
			continue;
		}
		if (j * mb == k * ma) {
			min_cost = min(min_cost, dp[i][j][k]);
		}
	}}}

	if (min_cost == inf) {
		min_cost = -1;
	}

	cout << min_cost << endl;
	return 0;
}