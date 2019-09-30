#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int inf = 1e9;
int dp[1447][727][2];
int zaj[1447][2];
int n, m;

void solve() {
	cin >> n >> m;
	for(int t = 1; t <= 1440; ++t) zaj[t][0] = zaj[t][1] = 0;
	
	for(int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		for(int j = a + 1; j <= b; ++j) zaj[j][0] = 1;	
	}	
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		for(int j = a + 1; j <= b; ++j) zaj[j][1] = 1;	
	}
	
	
	for(int t = 1; t <= 1440; ++t) {
		for(int j = 0; j <= 720; ++j) {
			for(int k = 0; k < 2; ++k) dp[t][j][k] = inf;
		}
	}
	
	if(!zaj[1][0]) dp[1][1][0] = 0;
	//if(!zaj[1][1]) dp[1][0][1] = 0;
	
	for(int t = 2; t <= 1440; ++t) {
		for(int j = 0; j <= 720; ++j) {
			if(!zaj[t][0] && j > 0) {
				dp[t][j][0] = min(dp[t - 1][j - 1][0], dp[t - 1][j - 1][1] + 1);
			}
			if(!zaj[t][1]) {
				dp[t][j][1] = min(dp[t - 1][j][1], dp[t - 1][j][0] + 1);
			}
		}
	}
	
	int wynik = min(dp[1440][720][0], dp[1440][720][1] + 1);
	
	for(int t = 1; t <= 1440; ++t) {
		for(int j = 0; j <= 720; ++j) {
			for(int k = 0; k < 2; ++k) dp[t][j][k] = inf;
		}
	}
	
	//if(!zaj[1][0]) dp[1][1][0] = 0;
	if(!zaj[1][1]) dp[1][0][1] = 0;
	
	for(int t = 2; t <= 1440; ++t) {
		for(int j = 0; j <= 720; ++j) {
			if(!zaj[t][0] && j > 0) {
				dp[t][j][0] = min(dp[t - 1][j - 1][0], dp[t - 1][j - 1][1] + 1);
			}
			if(!zaj[t][1]) {
				dp[t][j][1] = min(dp[t - 1][j][1], dp[t - 1][j][0] + 1);
			}
		}
	}
	
	wynik = min(wynik, min(dp[1440][720][0] + 1, dp[1440][720][1]));
	cout << wynik << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for(int it = 1; it <= tt; ++it) {
		cout << "Case #" << it << ": ";
		solve();
	}
	return 0;
}
