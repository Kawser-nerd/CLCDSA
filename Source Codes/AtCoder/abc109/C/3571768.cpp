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
int gcd(int x, int y) {
	if (x > y)return gcd(y, x);
	return x ? gcd(y%x, x) : y;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,X,x[100010], y[100010],ans;
	cin >> N >> X;
	REP(i, N) {
		cin >> x[i];
		y[i] = abs(X - x[i]);
		if (i == 0)ans = y[i];
		ans = gcd(ans, y[i]);
	}
	cout << ans << endl;
	return 0;
}