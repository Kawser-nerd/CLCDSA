#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int main() {
	int h, w; cin >> h >> w;
	int dp[101][101];
	int i = 0, j = 0;
	int n; cin >> n;
	for (int l = 0; l < n; l++) {
		int k; cin >> k;
		for (int dfs = 0; dfs < k; dfs++) {
			dp[i][j] = l + 1;
			if (i % 2 == 0) if (j == w - 1)i++; else j++;
			else if (j == 0)i++; else j--;
		}
	}
	for (int bfs = 0; bfs < h; bfs++) {
		for (int dfs = 0; dfs < w; dfs++) {
			if (dfs)cout << ' ';
			cout << dp[bfs][dfs];
		}
		cout << endl;
	}
	char ch; cin >> ch;
}