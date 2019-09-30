#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[2002];
int dp[2002][2];

int dfs(int id, int p) {
	int i;
	
	if (dp[id][p] != -1) return dp[id][p];
	
	int ret;
	if (p) ret = 1145141919;
	else ret = -1145141919;
	
	for (i = id + 1; i < n + 2; i++) {
		int res = dfs(i, !p);
		if (p) ret = min(ret, res);
		else ret = max(ret, res);
	}
	if (p) ret = min(ret, abs(a[n + 1] - a[id - 1]));
	else ret = max(ret, abs(a[n + 1] - a[id - 1]));
	return dp[id][p] = ret;
}

int main() {
	int i;
	cin >> n;
	for (i = 0; i < n + 2; i++) { cin >> a[i]; dp[i][0] = dp[i][1] = -1; }
	cout << dfs(2, 0) << endl;
	return 0;
}