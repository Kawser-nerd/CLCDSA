#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n, r, p, s;
string dp[13][3];

bool ok(string S, int r, int p, int s) {
	int cnt[26];
	for (int i = 0; i < 26; i++)
		cnt[i] = 0;
	for (int i = 0; i < (int) S.size(); i++)
		cnt[S[i] - 'A']++;
	return cnt['R' - 'A'] == r && cnt['P' - 'A'] == p && cnt['S' - 'A'] == s;
}

void doit() {
	scanf("%d%d%d%d", &n, &r, &p, &s);
	string ans = "Z";
	for (int i = 0; i < 3; i++)
		if (ok(dp[n][i], r, p, s))
			ans = min(ans, dp[n][i]);
	if (ans == "Z")
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;
}

int main() {
	int T;
	dp[0][0] = "R";
	dp[0][1] = "S";
	dp[0][2] = "P";
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j <= 2; j++)
			dp[i][j] = min(dp[i - 1][j] + dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 1) % 3] + dp[i - 1][j]);
	}
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
