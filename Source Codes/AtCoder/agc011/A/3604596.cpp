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

int main() {
	int N,C,K;
	cin >> N >> C >> K;
	int elt = 0;
	int rideCnt = 0;
	int ans = 0;
	int T[100010];
	REP(i, N) cin >> T[i];
	sort(T, T + N);
	elt = T[0];
	REP(i, N) {
		if (rideCnt < C && T[i] - elt <= K) {
			rideCnt++;
		}
		else {
			rideCnt = 1;
			elt = T[i];
			ans++;
		}
	}
	cout << ++ans << endl;
	return 0;
}