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

char tp[110000];
int x[110000];

void solve() {
	int n;
	scanf("%d", &n);
	forn(i, n)
		scanf(" %c %d", &tp[i], &x[i]);
	int x1 = 1;
	int x2 = 1;
	int t1 = 1;
	int t2 = 1;

	forn(i, n)
		if (tp[i] == 'O') {
			t1 = max(t2, abs(x1 - x[i]) + t1) + 1;
			x1 = x[i];
		}
		else {
			t2 = max(t1, abs(x2 - x[i]) + t2) + 1;
			x2 = x[i];
		}

	cout << max(t1, t2) - 1 << endl;
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