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

int cnt[100010];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,maxV = 0;
	int c[3][3],x[3], y[3];
	REP(i, 3) {
		REP(j, 3) {
			cin >> c[i][j];
		}
	}
	x[0] = 0;
	REP (i, 3)y[i] = c[0][i] - x[0];
	REP(i, 3)x[i] = c[i][0] - y[0];
	bool good = true;
	REP(i, 3) {
		REP(j, 3) {
			if (x[i] + y[j] != c[i][j]) {
				good = false;
			}
		}
	}

	if(good)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}