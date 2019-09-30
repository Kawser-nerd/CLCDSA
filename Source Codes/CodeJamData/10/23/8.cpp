#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
const int64 mod = 100003;

int64 z[510][510][2], c[510][510];

int64 rec(int n, int pr, bool fl) {
	if (n == 1)
		return 1;
	if (z[n][pr][fl] != -1)
		return z[n][pr][fl];

	int64 res = 0;
	for (int i = 1; i <= n - 1; i++)
		res = (res + rec(i, n, false) * (fl ? 1 : c[pr - 1 - n][n - i - 1])) % mod;

	return z[n][pr][fl] = res;
}

void solve() {
	int n;
	scanf("%d", &n);

	printf("%d", rec(n, n + 1, true));
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	

	for (int i = 0; i < 510; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}

	memset(z, -1, sizeof(z));
	rec(500, 501, true);
	rec(500, 501, false);
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);

		solve();

		puts("");
	}
	
	return 0;
}