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
	forn(i, n)
		scanf("%d", &a[i]);

	int x = 0;
	forn(i, n)
		x ^= a[i];

	if (x) {
		puts("NO");
		return;
	}

	int sum = 0;
	forn(i, n)
		sum += a[i];

	sum -= *min_element(a, a + n);

	cout << sum << endl;
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
	}
	
	return 0;
}