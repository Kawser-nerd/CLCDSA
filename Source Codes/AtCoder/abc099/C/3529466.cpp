#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int dp[100010];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	REP(n, N+1 ) {
		dp[n] = n;
		int power = 1;
		while (power <= n) {
			dp[n] = min(dp[n], dp[n - power] + 1);
			power *= 6;
		}
		power = 9;
		while (power <= n) {
			dp[n] = min(dp[n], dp[n - power] + 1);
			power *= 9;
		}
	}
	cout << dp[N] << endl;
	return 0;
}