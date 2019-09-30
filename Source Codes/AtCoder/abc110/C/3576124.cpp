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

	string S, T;
	cin >> S >> T;
	vector<int> start(26, -1);
	vector<int> goal(26, -1);
	REP(i, S.size()) {
		int a = S[i] - 'a';
		int b = T[i] - 'a';
		if (start[a] != -1 || goal[b] != -1) {
			if (start[a] != b || goal[b] != a) {
				cout << "No" << endl;
				return 0;
			}
		}
		start[a] = b;
		goal[b] = a;
	}
	cout << "Yes" << endl;
	return 0;
}