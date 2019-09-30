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
using namespace std;

signed main() {
	long long n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 1) {
		if (m == 1) cout << 1 << endl;
		else cout << m - 2 << endl;
	}
	else {
		cout << (n - 2) * (m - 2) << endl;
	}
	return 0;
}