#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	string S;
	cin >> S;
	vector<int> dp(4); dp[0] = 1;
	for (char c : S) {
		vector<int> ndp(4);
		for (int i = 0; i <= 3; ++i) {
			ndp[i] = dp[i] * (c == '?' ? 3LL : 1LL) % mod;
			if (i >= 1 && (c == '?' || c == char('A' + i - 1))) {
				ndp[i] += dp[i - 1];
				if (ndp[i] >= mod) ndp[i] -= mod;
			}
		}
		dp = ndp;
	}
	cout << dp[3] << endl;
	return 0;
}