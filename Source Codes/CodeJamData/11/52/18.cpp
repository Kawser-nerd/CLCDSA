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

int a[11000];

void solve() {
	int n;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));

	forn(i, n) {
		int x;
		scanf("%d", &x);
//		x--;
		a[x]++;
	}

	if (n == 0) {
		puts("0");
		return;
	}

	int ans = INF;
	vector<int> b;
	forn(i, 11000) {
		int p = 0, ne = 0;
		forn(j, a[i]) {
			if (p < (int)b.size()) {
				b[p]++;
				p++;
				continue;
			}

			ne++;
		}

		if (p < (int)b.size()) {
			ans = min(ans, b[p]);
			b.erase(b.begin() + p, b.end());
		}

		if (ne) {
			forn(j, ne)
				b.pb(1);

			sort(all(b));
		}
	}

	if (!b.empty())
		throw;

	cout << ans << endl;
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << ' ' << clock() << endl;
		printf("Case #%d: ", ii + 1);

		solve();
	}

	cerr << clock() << endl;
	
	return 0;
}