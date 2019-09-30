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

int func(int x) {
	if (x % 2 != 0)return 0;
	return 1 + func(x / 2);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,t[10];
	cin >> N;
	REP(i, N) {
		cin >> t[i];
	}
	int ans = 200;
	REP(mask, (1 << 4)) {
		int a = 0, b = 0;
		REP(i, N) {
			if (mask >> i & 1) {
				a += t[i];
			}
			else {
				b += t[i];
			}
		}
		ans = min(ans, max(a, b));
	}
	cout << ans << endl;
	return 0;
}