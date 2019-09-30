#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int sigma = 26; // species of characters
int main() {
	string s;
	cin >> s; s = "a" + s; // <-- sentinel
	int n = s.size();
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		seq[i] = s[i] - 'a';
	}
	vector<vector<int> > nxt(n, vector<int>(sigma, n)), pre(n, vector<int>(sigma, -1));
	for (int i = 1; i < n; ++i) {
		pre[i] = pre[i - 1];
		pre[i][seq[i - 1]] = i - 1;
	}
	for (int i = n - 2; i >= 0; --i) {
		nxt[i] = nxt[i + 1];
		nxt[i][seq[i + 1]] = i + 1;
	}
	vector<int> dp(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = n + 1;
		for (int j = 0; j < 26; ++j) {
			dp[i] = min(dp[i], dp[nxt[i][j]] + 1);
		}
	}
	string ans; int cur = 0;
	for (int i = dp[0] - 1; i >= 0; --i) {
		for (int j = 0; j < sigma; ++j) {
			if (dp[nxt[cur][j]] == i) {
				ans = ans + (char)('a' + j);
				cur = nxt[cur][j];
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}