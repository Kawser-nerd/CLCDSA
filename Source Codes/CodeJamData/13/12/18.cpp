#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int64 E, R;
int n, m;
int64 t[2][20050];
int64 a[10050];
vector<int> s;

void solve() {
	cin >> E >> R >> n;
	s.clear();
	forn(i, n+1)
		if (E - i * R >= 0)
			s.pb(E - i * R);
	forn(i, n+1)
		if (i * R <= E)
			s.pb(i * R);
	sort(all(s));
	s.resize(unique(all(s)) - s.begin());
	m = s.size();
	int64 res = 0;
	forn(i, 2)
		forn(j, m)
			t[i][j] = 0;
	for(int i = 1; i <= n; i++) {
		forn(j, m)
			t[i&1][j] = 0;
		int64 v;
		cin >> v;
		int p = 0;
		forn(j, m) {
			while (p+1 < m && s[p+1] <= s[j] + R) p++;
			if (j == 0)
				t[i&1][j] = t[(i-1)&1][p];
			else 
				t[i&1][j] = max(t[(i-1)&1][p], t[i&1][j-1] + v * (s[j] - s[j-1]));
			res = max(res, t[i&1][j]);
		}
	}
	cout << res << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn(ii, tt) {
		printf("Case #%d: ", ii+1);
		solve();
	}
	return 0;
}
