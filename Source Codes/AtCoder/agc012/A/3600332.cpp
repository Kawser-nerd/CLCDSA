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

	int N;
	int a[300010];
	cin >> N;

	REP(i, 3*N) cin >> a[i];
	sort(a, a + 3*N,greater<int>());
	ll sum = 0;
	for (int i = 1; i < 2 * N;i+=2) {
		sum += a[i];
	}

	cout << sum << endl;
	return 0;
}