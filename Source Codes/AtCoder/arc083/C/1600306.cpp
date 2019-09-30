#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int n;
int p[1000];
int x[1000];
vector<int> et[1000];

//???v?????????????. (?v???????)
int dfs(int v, int p = -1) {
	if (p != -1 && et[v].size() == 0) {	//?
		//cout << "*s[" << v << "] = " << x[v] << endl;
		return x[v];
	}
	
	int i, j;
	
	//???????????
	int N = et[v].size();
	int W = x[v];
	
	vector<vector<bool>> dp;
	vector<int> ws;
	for (i = 0; i <= N; i++) { dp.push_back(vector<bool>(W + 1, false)); }
	for (i = 0; i < N; i++) {
		int s = dfs(et[v][i], v);
		if (s == -1) return -1;
		ws.push_back(s);
	}
	
	dp[0][0] = true;
	for (i = 0; i < N; i++) {
		for (j = 0; j <= W; j++) {
			if (!dp[i][j]) continue;
			
			int a = x[et[v][i]];
			int b = ws[i] - x[et[v][i]];
			//a???
			if (j + a <= W) {
				dp[i + 1][j + a] = true;
			}
			//b???
			if (j + b <= W) {
				dp[i + 1][j + b] = true;
			}
		}
	}
	
	for (i = W; i >= 0; i--) if (dp[N][i]) break;
	if (i < 0) return -1;
	
	//x[v] + ?ws - i???. (i?, ????????v?????????????????)
	int ret = x[v] - i;
	for (j = 0; j < ws.size(); j++) ret += ws[j];
	//cout << "s[" << v << "] = " << ret << endl;
	return ret;
}

signed main() {
	int i;
	
	cin >> n;
	for (i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		et[p[i]].push_back(i);
	}
	for (i = 0; i < n; i++) cin >> x[i];
	
	if (dfs(0) != -1) cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}