#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string s; int K, dp[309][309][309];
int main() {
	cin >> s >> K;
	string d1 = s, d2 = s;
	reverse(d2.begin(), d2.end());
	for (int i = 0; i <= d1.size(); i++) {
		for (int j = 0; j <= d2.size(); j++) {
			for (int k = 0; k <= K; k++) {
				if (i >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				if (j >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
				if (i >= 1 && j >= 1) {
					if (d1[i - 1] == d2[j - 1]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
					else if(k >= 1) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
				}
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j <= K; j++) {
			ret = max(ret, dp[i][s.size() - i - 1][j] * 2 + 1);
		}
	}
	for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= K; j++) {
			ret = max(ret, dp[i][s.size() - i][j] * 2);
		}
	}
	cout << ret << endl;
	return 0;
}