#include <bits/stdc++.h>
#include "header.h"

int main() {
	int T, n;
	char c;
	cin >> T;
	rep(X, 0, T) {
		cin >> n;
		int ans = 0, total = 0;
		rep(i, 0, n + 1) {
			cin >> c;
			total += c - '0';
			ans = max(i - total + 1, ans);
		}
		printf("Case #%d: %d\n", X + 1, ans);
	}
}
