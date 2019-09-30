#include <cmath>
#include <map>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 10000 + 10;

int n;
long long a[N], f[N], g[N];

bool checkOk(long long x)
{
	if (x == 0) {
		for(int i = 0; i < n; ++ i) {
			if (f[i] & 1) return false;
		}
		for(int i = 0; i < n; ++ i) {
			f[i] /= 2;
		}
		return true;
	}

	for(int i = 0; i < n; ++ i) {
		g[i] = f[i];
	}
	if (x > 0) {
		int ptr = 0;
		for(int i = 0; i < n; ++ i) {
			if (g[i] == 0) continue;
			for( ; ptr < n && a[ptr] < a[i] + x; ++ ptr);
			if (ptr == n || g[ptr] < g[i]) return false;
			g[ptr] -= g[i];
		}
	} else {
		int ptr = n - 1;
		for(int i = n - 1; i >= 0; -- i) {
			if (g[i] == 0) continue;
			for( ; ptr >= 0 && a[ptr] > a[i] + x; -- ptr);
			if (ptr < 0 || g[ptr] < g[i]) return false;
			g[ptr] -= g[i];
		}
	}
	for(int i = 0; i < n; ++ i) {
		f[i] = g[i];
	}
	return true;
}

void dfs(long long tot)
{
	if (tot == 1) {
		return;
	}
	for(int i = 0; i < n; ++ i) {
		if (f[i]) {
			//cout << "! " << tot << ' ' << a[i] << endl;
			if (checkOk(a[i])) {
				cout << ' ' << a[i];
				dfs(tot / 2);
				return;
			}
		}
	}
	assert(0);
}

void solve()
{
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		scanf("%lld", a + i);
	}
	long long tot = 0;
	for(int i = 0; i < n; ++ i) {
		scanf("%lld", f + i);
		tot += f[i];
	}
	dfs(tot);
	cout << endl;
}

int main()
{
	//freopen("D-small-attempt0.in", "r", stdin); freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-small-attempt1.in", "r", stdin); freopen("D-small-attempt1.out", "w", stdout);
	freopen("D-large.in", "r", stdin); freopen("D-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d:", i + 1);
		solve();
	}
	return 0;
}
