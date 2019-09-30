#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int n, k;

int f(int b) {
	int x = b - k;
	int y = (n - k) / b;
	return x * y + min(x, n - (y * b + k) + 1);
}

signed main() {
	cin >> n >> k;
	if (k == 0) {
		cout << n * n << endl;
		return 0;
	}
	
	int ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans += f(b);
	}
	cout << ans << endl;
	return 0;
}