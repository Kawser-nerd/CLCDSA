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
int N;
int ans = -1000000000;
int a[20], F[110][20], P[110][20];
void func() {
	bool isZeroCnt = true;
	REP(i, 10) {
		if (a[i] == 1) {
			isZeroCnt = false;
			break;
		}
	}
	if (isZeroCnt)return;

	int score = 0;
//	cout << a[0] << a[1] << a[2] << a[3] << a[4] << a[5] << a[6] << a[7] << a[8] << a[9] << endl;
	REP(i, N) {
		int cnt = 0;
		REP(j, 10) {
			if (F[i][j] == 1 && a[j] == 1) {
				cnt++;
			}
		}
//		cout << "P[" << i << "][" << cnt << "] = " << P[i][cnt] << endl;
		score += P[i][cnt];
	}
//	cout << "score = " << score << endl;
	ans = max(ans, score);
}
void dfs(int pos) {
	if (pos == 10) {
		func();
		return;
	}
	a[pos] = 0; 
	dfs(pos + 1);
	a[pos] = 1;
	dfs(pos + 1);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	REP(i, N) {
		REP(j, 10) {
			cin >> F[i][j];
		}
	}
	REP(i, N) {
		REP(j, 11) {
			cin >> P[i][j];
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}