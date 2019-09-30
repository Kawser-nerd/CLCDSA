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
int a[100010];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	REP(i, N) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	int x = 0;
	REP(i, 100010) {
		if (x == 1) {
			cout << i << endl;
			return 0;
		}
		x = a[x];
	}

	cout << -1 << endl;
	return 0;
}