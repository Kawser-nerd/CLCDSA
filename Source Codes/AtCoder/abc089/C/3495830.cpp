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
	string MARCH = "MARCH";
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	string s;
	ll c[5] = { 0 };
	cin >> N;
	REP(i, N) {
		cin >> s;
		REP(j, MARCH.length()) {
			if (s[0] == MARCH[j]) {
				c[j]++; 
				break;
			}
		}
	}
	ll ans = 0;
	REP(i, 5) {
		REPL(j,i+1, 5) {
			REPL(k,j+1, 5) {
				ans += c[i] * c[j] * c[k];
			}
		}
	}

	cout << ans << endl;
	return 0;
}