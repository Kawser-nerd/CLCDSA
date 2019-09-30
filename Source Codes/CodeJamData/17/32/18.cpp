#include <bits/stdc++.h>
using namespace std;

const int MAXX = 720;

int dp[2][2][MAXX+5][MAXX+5];

int active[2*MAXX+5];
int ac, aj;

void init() {
	for(int i = 0 ; i < 2*MAXX + 5 ; i++)
		active[i] = 3;
	cin >> ac >> aj;

	for(int i = 0 ; i < ac ; i++) {
		int c, d; cin >> c >> d;
		for(int j = c ; j < d ; j++) {
			if(active[j] & 1) active[j] -= 1;
		}
	}

	for(int i = 0 ; i < aj ; i++) {
		int c, d; cin >> c >> d;
		for(int j = c ; j < d ; j++) {
			if(active[j] & 2) active[j] -= 2;
		}
	}
}

int solve(int st, int lst, int tota, int totb) {
	if(tota > MAXX || totb > MAXX) return 3*MAXX;
	if(tota+totb == 2*MAXX) return st != lst;

	int &ret = dp[st][lst][tota][totb];
	if(ret != -1) return ret;

	ret = 3*MAXX;
	int cur = tota + totb;

	if(active[cur] & 1) ret = min(ret, (lst == 1) + solve(st, 0, tota+1, totb));
	if(active[cur] & 2) ret = min(ret, (lst == 0) + solve(st, 1, tota, totb+1));

	// cout << st << " " << lst << " " << tota << " " << totb << " " << ret << endl;

	return ret;
}

int work() {
	memset(dp, -1, sizeof dp);
	int ret = 3*MAXX;

	if(active[0] & 1) ret = min(ret, solve(0, 0, 1, 0));
	if(active[0] & 2) ret = min(ret, solve(1, 1, 0, 1));

	return ret;
}

int main() {
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		init();
		int ret = work();
		printf("Case #%d: %d\n", tc, work());	
	}
	return 0;
}