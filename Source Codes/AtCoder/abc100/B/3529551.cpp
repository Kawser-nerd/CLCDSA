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
	if (x % 100 != 0)return 0;
	return 1 + func(x / 100);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int D, N;
	cin >> D >> N;
	int cnt = 0;

	for (int x = 1;; x++) {
		if (func(x) == D) {
			cnt++;
			if (cnt == N) {
				cout << x << endl;
				return 0;
			}
		}
	}
	return 0;
}