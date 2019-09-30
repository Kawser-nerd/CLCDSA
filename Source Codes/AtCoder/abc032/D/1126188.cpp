#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
#define P pair<int,int>
using namespace std;
 
P c[200];
int dp[200001]{};
P x[1 << 15], y[1 << 15];
signed main() {
	int a, b; cin >> a >> b;
	int n = 0;
	for (int d = 0; d < a; d++) {
		int e, f; scanf("%lld%lld", &e, &f);
		n = max(n, f);
		c[d] = P(e, f);
	}
	if (n <= 1000) {
		for (int i = 0; i < a; i++) {
			for (int j = b; j >= c[i].second; j--) {
				dp[j] = max(dp[j], dp[j - c[i].second] + c[i].first);
			}
		}
		cout << dp[b] << endl;
	}
	 else if (a <= 30) {
		int h = a / 2, i = a - (a / 2);
		for (int j = 0; j < (1 << h); j++) {
			int o = 0, w = 0;
			for (int k = 1,v=0; k < (1 << h); k <<= 1,v++) {
				if (j&k) { o += c[v].first; w += c[v].second; }
			}
			x[j] = P(o, w);
		}
		for (int j = 0; j < (1 << i); j++) {
			int o = 0, w = 0;
			for (int k = 1, v = 0; k < (1 << i); k <<= 1, v++) {
				if (j&k) { o += c[v+h].first; w += c[v+h].second; }
			}
			y[j] = P(o, w);
		}
		int MAX = 0;
		for (int v = 0; v < (1 << h); v++) {
			for (int w = 0; w < (1 << i); w++) {
				if (x[v].second + y[w].second <= b) {
					MAX = max(MAX, x[v].first + y[w].first);
				}
			}
		}
		cout << MAX << endl;
	}
	else {
		fill(dp, dp + 200001, LLONG_MAX / 3);
		dp[0] = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 200001; j >= c[i].first; j--) {
				dp[j] = min(dp[j], dp[j - c[i].first] + c[i].second);
			}
		}
		int MAX = 0;
		for (int i = 0; i < 200001; i++) {
			if (dp[i] <= b) {
				MAX = max(MAX, i);
			}
		}
		cout << MAX << endl;
	}
}