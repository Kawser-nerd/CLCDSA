#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

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
#include <complex>

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

int n, d[110000], l[110000], fin;

void read() {
	cin >> n;
	forn(i, n)
		scanf("%d%d", &d[i], &l[i]);
	cin >> fin;
}

void solve() {
	int p = 1;
	l[0] = d[0];
	int r = d[0] + l[0];
	int s = 0;
	while (r < fin && s < p) {
		while (p < n && d[p] - d[s] <= l[s]) {
			l[p] = min(l[p], d[p] - d[s]);
			r = max(r, d[p] + l[p]);
			p++;
		}
		s++;
	}

	if (fin <= r)
		puts("YES");
	else
		puts("NO");
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
	
	int tt;
	cin >> tt;
	forn(ii, tt) {
		cerr << ii << "/" << tt << endl;
		read();
		printf("Case #%d: ", ii + 1);
		solve();
	}
	
	return 0;
}