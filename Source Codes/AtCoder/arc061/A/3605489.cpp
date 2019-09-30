#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPL(i,f,n) for(int i=f, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;
	int n = S.length();
	ll sum = 0;
	REP(mask, 1 << (n - 1)) {
		ll tmp = S[0] - '0';
		REP(i, n - 1) {
			if (mask & (1 << i)) {
				// '+'?i?i+1??????
				sum += tmp;
				tmp = S[i + 1] - '0';
			}
			else {
				tmp = tmp * 10 + (S[i + 1] - '0');
			}
		}
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}