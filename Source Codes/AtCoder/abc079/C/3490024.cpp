#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;

int func(long long n) {
	if (n < 10)return 1;
	return func(n/10)+1;
}
int a[4];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	string input;
	cin >> input;
	REP(i,4)a[i] = input[i] - '0';
	REP(x, 8) {
		int sum = a[0];
		string s;
		s += (char)('0' + a[0]);
		REP(i, 3) {
			if (x & (1 << i)) {
				sum += a[i+1];
				s += '+';
			}
			else {
				sum -= a[i + 1];
				s += '-';
			}
			s += (char)('0' + a[i + 1]);
		}
		if (sum == 7) {
			cout << s << "=7" << endl;
			return 0;
		}
	}
	return 0;
}