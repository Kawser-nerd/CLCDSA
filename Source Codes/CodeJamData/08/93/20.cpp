#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:60000000")

#include <iostream>
#include <sstream>

#include <cassert>
#include <cmath>
#include <ctime>

#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(a) a.begin(), a.end()

const int INF = INT_MAX >> 1;
const double EPS = 1E-8;
const double PI = 3.1415926535897932384626433832795;

int ans;
int a[10][10];
int n, m;

void go(int r, int c, int cur) {
	if (r > (n + 1) / 2 && cur < ans) return;
	if (r == n + 1) {
		forn(i, n)
			forn(j, m)
				if (a[i + 1][j + 1] != 0) return;
		ans = cur;
		return;
	}
	if (c == m + 1) {
		if (r > 1)
			forn(j, m)
				if (a[r - 1][j + 1] != 0) return;
		return go(r + 1, 1, cur);
	}
	go(r, c + 1, cur);
	bool ok = true;
	for(int dx = -1; dx <= 1; ++dx)
		for(int dy = -1; dy <= 1; ++dy) {
			if (a[r + dx][c + dy] == 0) ok = false;
			--a[r + dx][c + dy];
		}
	if (ok) go(r, c + 1, (r == (n + 1) / 2 ? cur + 1 : cur));
	for(int dx = -1; dx <= 1; ++dx)
		for(int dy = -1; dy <= 1; ++dy)
			++a[r + dx][c + dy];
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int tk;
	scanf("%d\n", &tk);
	
	for(int tc = 1; tc <= tk; ++tc) {
		cin >> n >> m;
		memset(a, 60, sizeof a);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		ans = 0;
		go(1, 1, 0);
		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}