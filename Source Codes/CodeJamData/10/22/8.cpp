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

int64 x[1100], v[1100];

void solve() {
	int n, k;
	int64 b, t;
	scanf("%d%d%lld%lld", &n, &k, &b, &t);

	forn(i, n)
		scanf("%lld", &x[i]);
	forn(i, n)
		scanf("%lld", &v[i]);

	int ans = 0;
	ford(i, n) {
		if (k == 0)
			break;

		if (b - x[i] <= t * v[i])
			k--;
		else
			ans += k;
	}

	if (k == 0)
		printf("%d", ans);
	else
		printf("IMPOSSIBLE");
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		printf("Case #%d: ", ii + 1);

		solve();

		puts("");
	}
	
	return 0;
}