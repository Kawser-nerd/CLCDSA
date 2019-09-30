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

	int N,x;
	int a[110];
	cin >> N >> x;

	REP(i, N) cin >> a[i];
	sort(a, a + N);
	int ans = 0;
	int sum = 0;
	for (int i=0;i<N;i++) {
		sum += a[i];
		if (sum > x) {
			ans = i;
			break;
		}
	}
	if (ans == 0) {
		if (sum == x) {
			ans = N;
		}
		else if(sum < x) {
			ans = N-1;
		}
	}

	cout << ans << endl;
	return 0;
}