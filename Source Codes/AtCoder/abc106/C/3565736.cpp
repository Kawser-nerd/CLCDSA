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

	string S;
	ll K;
	cin >> S >> K;

	for (ll i = 0; i < K;i++) {
		if (S[i] != '1') {
			cout << S[i] << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}